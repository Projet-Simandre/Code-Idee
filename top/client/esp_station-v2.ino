#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <ESPmDNS.h>//biblio de mdns

//Bon client normalement

#define air 36

const char* hostname = "ESP_meteo";//nom de l'esp
  const char* serverUrl = "http://10.1.6.106:8080/recuperer_infos";

void setup() {
  Serial.begin(115200);

  WiFi.begin("HexIOT", "H3xag0nePriv4te");//wifi

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connexion au WiFi en cours...");
  }
  Serial.println("Connecté au WiFi !");
  
  if (!MDNS.begin(hostname)) {//check mdns
    Serial.println("Erreur lors de l'initialisation de mDNS");
  } else {
    Serial.println("mDNS est actif !");
  }
}

int tauxHumidite(){
  int tauxHumidite = analogRead(air);
  int humide = map(tauxHumidite, 1024, 4060, 0, 100);
  return humide;
}
int qualiteAir(){
  int tauxAir = analogRead(air);
  return tauxAir;
}

void loop() {
  DynamicJsonDocument data(1024);
    data["temperature"] = 50; // Exemple de valeur
    data["humidite"] = 130;
    data["qualite"] = 4;
    data["ip"] = WiFi.localIP();
    Serial.println(WiFi.localIP());
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
    delay(10000); // Attendez un moment avant de renvoyer des données
}