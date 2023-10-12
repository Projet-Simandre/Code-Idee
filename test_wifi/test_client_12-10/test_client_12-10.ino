#include <WiFi.h>

const char* ssid = "SimAndré";
const char* password = "12345678";

IPAddress server(192, 168, 4, 1);

void setup()
{
  Serial.begin(9600);
  
  
	delay(1000);
	Serial.println("\n");
	
  
	WiFi.begin(ssid, password);
	Serial.print("Tentative de connexion...");
	
	while(WiFi.status() != WL_CONNECTED)
	{
		Serial.print(".");
		delay(100);
	}
	
	Serial.println("\n");
	Serial.println("Connexion etablie!");
	Serial.print("Adresse IP: ");
	Serial.println(WiFi.localIP());
}

void loop() {

  WiFiClient client;
    Serial.println("Connecté au serveur");
    client.connect(server, 80);
    String message="hello";
    client.print(message.c_str());

    client.stop();
    Serial.println("Données envoyées au serveur");

    Serial.println(WiFi.localIP());
  delay(10000);  // Attendez 10 secondes avant d'envoyer à nouveau les données
}