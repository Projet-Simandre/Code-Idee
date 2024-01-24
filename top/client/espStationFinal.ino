#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <ESPmDNS.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

#define air 36
#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)

Adafruit_BMP280 bmp; // I2C

const char* hostname = "ESP_meteo"; // Nom de l'ESP
const char* serverUrl = "http://10.1.6.106:8080/recuperer_infos"; // URL du serveur

void setup() {
  Serial.begin(115200);
  if (!bmp.begin(0x76)) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }

  /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

  // Connexion au réseau WiFi
  WiFi.begin("HexIOT", "H3xag0nePriv4te");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connexion au WiFi en cours...");
  }
  Serial.println("Connecté au WiFi !");
  
  // Initialisation du service mDNS
  if (!MDNS.begin(hostname)) {
    Serial.println("Erreur lors de l'initialisation de mDNS");
  } else {
    Serial.println("mDNS est actif !");
  }
}

// Fonction pour mesurer le taux d'humidité

// Fonction pour mesurer la qualité de l'air
int qualiteAir() {
  int tauxAir = analogRead(air);
  return tauxAir;
}

void loop() {
  // Création d'un objet JSON
  DynamicJsonDocument data(1024);
  data["temperature"] = bmp.readTemperature(); // Exemple de valeur
  data["qualite"] = qualiteAir();
  data["pressure"] = bmp.readPressure();
  data["ip"] = WiFi.localIP();
  data["mac"] = WiFi.macAddress();

  Serial.print("Température: ");
  Serial.println(bmp.readTemperature());
  Serial.print("Pollution: ");
  Serial.println(qualiteAir());
  Serial.print("Pression: ");
  Serial.println(bmp.readPressure());
  Serial.print("Ip: ");
  Serial.println(WiFi.localIP());
  Serial.print("Mac: ");
  Serial.println(WiFi.macAddress());

  
  // Conversion de l'objet JSON en chaîne
  String jsonData;
  serializeJson(data, jsonData);

  // Configuration de la requête HTTP POST
  HTTPClient http;
  http.begin(serverUrl);
  http.addHeader("Content-Type", "application/json");

  // Envoi des données JSON
  int httpResponseCode = http.POST(jsonData);

  if (httpResponseCode > 0) {
    String response = http.getString();
    Serial.print("Réponse du serveur : ");
    Serial.println(response);
  } else {
    Serial.print("Erreur : ");
    Serial.println(httpResponseCode);
  }

  http.end();
  delay(10000); // Attendez un moment avant de renvoyer des données
}
