#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <ESPmDNS.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include <WiFiManager.h>  // https://github.com/tzapu/WiFiManager

#define air 36
#define BMP_SCK (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS (10)

Adafruit_BMP280 bmp;  // I2C

const char* hostname = "ESP_meteo";                               // Nom de l'ESP
const char* serverUrl = "http://10.1.4.77:8080/recuperer_infos";  // URL du serveur

void setup() {
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);  // explicitly set mode, esp defaults to STA+AP

  WiFiManager wm;
  bool res;
  res = wm.autoConnect("Capteur Est");
  if (!res) {
    Serial.println("FConnexionn échouer");
  } else {
    Serial.println("connected...yeey :)");
  }
  Serial.println(F("BMP280 test"));

  if (!bmp.begin(0x76)) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }
  
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */

  // Connexion au réseau WiFi
  Serial.println("Connecté au WiFi !");

  // Initialisation du service mDNS
  if (!MDNS.begin(hostname)) {
    Serial.println("Erreur lors de l'initialisation de mDNS");
  } else {
    Serial.println("mDNS est actif !");
  }
}

// Fonction pour mesurer la qualité de l'air
int qualiteAir() {
  int tauxAir = analogRead(air);
  return tauxAir;
}

void loop() {
  // Création d'un objet JSON
  DynamicJsonDocument data(1024);
  data["temperature"] = bmp.readTemperature();  // Exemple de valeur
  data["qualite"] = qualiteAir();
  data["pression"] = bmp.readPressure();
  data["ip"] = WiFi.localIP();
  data["mac"] = WiFi.macAddress();

  //Affiche les valeurs en serial
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
}
