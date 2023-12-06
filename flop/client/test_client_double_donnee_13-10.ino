#include <WiFi.h>

const char* ssid = "SimAndré";
const char* password = "12345678";

IPAddress server(192, 168, 4, 1);

void setup()
{
  Serial.begin(115200);
  
	Serial.println("\n");

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


void loop() {

  WiFiClient client;
    Serial.println("Connecté au serveur");
    client.connect(server, 80);

    String message1="1.20";
    String message2="2.80";

    String message = message1+message2;

    client.println(message);
    
    client.stop();
    Serial.println("Données envoyées au serveur");

    Serial.println(WiFi.localIP());
    Serial.println(message);
    Serial.println("------------------------------");
}