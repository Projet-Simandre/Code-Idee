#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>

const char* ssid = "Sinandre";
const char* password = "12345678";
const int serverPort = 80;

WebServer server(serverPort);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connexion au réseau WiFi en cours...");
  }

  Serial.println("Connecté au réseau WiFi");

  server.on("/", HTTP_GET, [](){
    String hello = server.arg("hello");
    String value = server.arg("value");
    
    Serial.println("Données reçues :");
    Serial.println("hello: " + hello);
    Serial.println("value: " + value);

    server.send(200, "text/plain", "Données reçues avec succès");
  });

  server.begin();
  Serial.println("Serveur Web démarré");
}

void loop() {
  server.handleClient();
}
