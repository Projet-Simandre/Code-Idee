#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#define humidite 36

const char* ssid = "HexIOT";
const char* password = "H3xag0nePriv4te";
const char* serverUrl = "http://10.1.6.105:8080/recuperer_infos"; // Remplacez par l'adresse IP et le port de votre serveur Flask

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connexion au WiFi en cours...");
    }

    Serial.println("Connecté au WiFi !");
}

int tauxHumidite(){
  int tauxHumidite = analogRead(humidite);
  int humide = map(tauxHumidite, 1024, 4060, 0, 100);
  return humide;
}


void loop() {
    // Créez un objet JSON pour les données
    DynamicJsonDocument data(1024);
    data["valeur"] = tauxHumidite(); // Exemple de valeur
    data["temps"] = 0;

    // Convertissez l'objet JSON en une chaîne
    String jsonData;
    serializeJson(data, jsonData);

    // Configurez la requête HTTP POST
    HTTPClient http;
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/json");

    // Envoyez les données JSON
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

    delay(5000); // Attendez un moment avant de renvoyer des données
}
