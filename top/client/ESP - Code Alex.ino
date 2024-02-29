#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <ESPmDNS.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>

#define air 34
#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)

Adafruit_BMP280 bmp; // I2C

const char* hostname = "ESP_meteo_alex"; // Nom de l'ESP
const char* serverUrl = "http://10.1.6.106:8080/recuperer_infos"; // URL du serveur

void setup() {
  if (!bmp.begin(0x76)) {/* Verifie si le BMP est valide */
    while (1);
  }

  /* Par defaut du BMP */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Mode d'opération */
                  Adafruit_BMP280::SAMPLING_X2,     /* Température */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pression */
                  Adafruit_BMP280::FILTER_X16,      /* Filtre */
                  Adafruit_BMP280::STANDBY_MS_500); /* Heure. */

  // Connexion au réseau WiFi
  WiFi.begin("HexIOT", "H3xag0nePriv4te");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
  Serial.println("Connecté au WiFi !");
  
  // Initialisation du service mDNS
  if (!MDNS.begin(hostname)) {
    /* Check si la connexion se passe bien */
    /* Connexion echoué */
  } else {
    /* Connexion reussi */
  }
}

// Fonction pour mesurer la qualité de l'air
int qualiteAir() {
  int tauxAir = analogRead(air);
  return tauxAir;
}

void loop() {
  // Création d'un objet JSON
  DynamicJsonDocument data(1024); // Taille maximale de l'objet JSON
  data["temperature"] = bmp.readTemperature(); // Ajout de la température
  data["qualite"] = qualiteAir(); // Ajout de la qualité de l'air
  data["pressure"] = bmp.readPressure(); // Ajout de la pression
  data["ip"] = WiFi.localIP(); // Ajout de l'adresse IP
  data["mac"] = WiFi.macAddress(); // Ajout de l'adresse MAC
  
  // Conversion de l'objet JSON en chaîne
  String jsonData;
  serializeJson(data, jsonData);

  // Configuration de la requête HTTP POST
  HTTPClient http;
  http.begin(serverUrl);
  http.addHeader("Content-Type", "application/json");

  // Envoi des données JSON
  int httpResponseCode = http.POST(jsonData);

  if (httpResponseCode > 0) { // Si la requête a réussi
    String response = http.getString();
  } else { // Si la requête a échoué;
  }

  http.end();
  delay(10000); // Attendez un moment avant de renvoyer des données
}