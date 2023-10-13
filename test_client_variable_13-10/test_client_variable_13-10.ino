#include <WiFi.h>

#define humidite 36

const char* ssid = "SimAndré";
const char* password = "12345678";

IPAddress server(192, 168, 4, 1);

void setup()
{
  Serial.begin(115200);
  
	Serial.println("\n");
	
  pinMode(humidite, INPUT);
	WiFi.begin(ssid, password);
	Serial.print("Tentative de connexion...");
	
	while(WiFi.status() != WL_CONNECTED)
	{
		Serial.print(".");
	}
	
	Serial.println("\n");
	Serial.println("Connexion etablie!");
	Serial.print("Adresse IP: ");
	Serial.println(WiFi.localIP());
}
int tauxHumidite(){
  int tauxHumidite = analogRead(humidite);
  int humide = map(tauxHumidite, 1024, 4060, 0, 100);
  return humide;
}
void loop() {

  WiFiClient client;
    Serial.println("Connecté au serveur");
    client.connect(server, 80);

    int message=tauxHumidite();
    Serial.println(message);
    client.print(message);
    client.stop();
    Serial.println("Données envoyées au serveur");

    Serial.println(WiFi.localIP());
    Serial.println("------------------------------");
}