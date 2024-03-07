#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <ESPmDNS.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>


// On définit les broches/pins qu'on utilisera dans ce code et pour plus de lisibilité on pourra utiliser les noms qu'on a associés au broches/pins
#define AIR_SENSOR_PIN 35
#define BMP_SCK  (13)
#define BMP_MISO (12)
#define BMP_MOSI (11)
#define BMP_CS   (10)

Adafruit_BMP280 bmp; // I2C (On crée un objet bmp pour interagir avec le matériel connecté)

const char* hostname = "ESP_meteo_unified"; // Nom de l'ESP
const char* serverUrl = "http://10.1.8.93:8080/recuperer_infos"; // URL du serveur
const char* ssid = "HexIOT";
const char* password = "H3xag0nePriv4te";


void connectToWiFi() {
  WiFi.begin(ssid, password); // Etablie la connexion au WiFi avec le SSID(identifiant) et le mot de passe fournie plus haut
  while (WiFi.status() != WL_CONNECTED) { // Tant que la connexion WiFi n'est pas établie
    delay(3000);
    Serial.println("Connecting to WiFi..."); 
  }
  Serial.println("Connected to WiFi!"); 
}


void initializeBMP280() {
  if (!bmp.begin(0x76)) { // Si le capteur BMP280 n'est pas trouvé
    Serial.println("Where is the BMP 280, seems like it's not connected yet");
    while (1); // Reste bloqué dans cette boucle tant que le BMP280 n'est pas connecté
  } else {
    Serial.println("BMP280 is connected and initialized");
    bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Mode de fonctionnement. */
                    Adafruit_BMP280::SAMPLING_X2,     /* Suréchantillonnage de la température. */
                    Adafruit_BMP280::SAMPLING_X16,    /* Suréchantillonnage de la pression. */
                    Adafruit_BMP280::FILTER_X16,      /* Filtrage. */
                    Adafruit_BMP280::STANDBY_MS_500); /* Temps de veille. */
  }
}


void initializeMDNS() {
  if (!MDNS.begin(hostname)) { // Si le service mDNS ne peut pas être initialisé en fonction du nom de l'ESP
    Serial.println("Error initializing mDNS");
  } else { 
    Serial.println("mDNS is active !");
  }
}


void setup() {
  Serial.begin(115200);
  connectToWiFi(); // Appelle la fonction pour se connecter au WiFi
  initializeBMP280(); // Appelle la fonction pour initialiser le capteur BMP280
  initializeMDNS(); // Appelle la fonction pour initialiser le service mDNS
}



void loop() {
  DynamicJsonDocument data(1024); // Création d'un document JSON dynamique
  collectData(data); // Appel de la fonction pour collecter les données
  sendData(data); // Appel de la fonction pour envoyer les données
  delay(10000); // Pause de 10 secondes avant la prochaine itération
}

// Fonction pour collecter les données
void collectData(DynamicJsonDocument& data) { // Mise en place du "&" pour préciser que data doit être sauvegardé dans la mémoire pour être réuitilisé dans la fonction d'en bas
  data["temperature"] = readTemperature(); // Lecture de la température
  data["qualite"] = qualiteAir(); // Lecture de la qualité de l'air
  data["pressure"] = readPressure(); // Lecture de la pression
  data["ip"] = WiFi.localIP(); // Lecture de l'adresse IP locale
  data["mac"] = WiFi.macAddress(); // Lecture de l'adresse MAC
}

// Fonction pour envoyer les données
void sendData(DynamicJsonDocument& data) { 
  String jsonData; // Création d'une chaîne de caractères pour stocker les données JSON
  serializeJson(data, jsonData); // Convertit data qui est en json en string et stocke la valeur de date dans jsonData

  HTTPClient http; // Cette ligne de code crée un objet http et est utilisé pour envoyer des requêtes HTTP à un serveur
  http.begin(serverUrl); // Début de la connexion au serveur
  http.addHeader("Content-Type", "application/json"); // Ajout d'une en-tête à la requête HTTP en précisant qu'on envoie du JSON

  int httpResponseCode = http.POST(jsonData); // Envoi de la requête POST et récupération du code de réponse

  if (httpResponseCode > 0) { // Si la requête a réussi
    String response = http.getString(); // Récupération de la réponse
  }

  http.end(); // Fin de la connexion
}

// Fonction pour lire la température
float readTemperature() {
  return bmp.readTemperature(); // Lecture de la température à l'aide du capteur BMP
}

// Fonction pour mesurer la qualité de l'air
int qualiteAir() {
  int tauxAir = analogRead(AIR_SENSOR_PIN); // Lecture de la qualité de l'air à l'aide du capteur d'air
  return tauxAir;
}

// Fonction pour lire la pression
float readPressure() {
  return bmp.readPressure(); // Lecture de la pression à l'aide du capteur BMP
}