#include <WiFi.h>

const char* ssid = "Sinandre";
const char* password = "12345678";
const char* serverIP = "192.168.1.100"; // Adresse IP statique du serveur
const int serverPort = 80;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connexion au réseau WiFi en cours...");
  }

  Serial.println("Connecté au réseau WiFi");
}

void loop() {
  WiFiClient client;
  if (client.connect(serverIP, serverPort)) {
    Serial.println("Connecté au serveur");

    client.print("hello");
    delay(100);
    client.print("12.3");

    client.stop();
    Serial.println("Données envoyées au serveur");
  } else {
    Serial.println("Échec de la connexion au serveur");
  }

  delay(10000);  // Attendez 10 secondes avant d'envoyer à nouveau les données
}
