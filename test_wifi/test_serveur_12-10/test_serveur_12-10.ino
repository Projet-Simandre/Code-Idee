#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "SimAndré";
const char* password = "12345678";
char Lclient;

WiFiServer server(80);

void setup()
{
  server.begin();
	Serial.begin(9600);
	delay(1000);
	Serial.println("\n");
	
	Serial.println("Creation du point d'acces...");
	WiFi.softAP(ssid, password);
	
	Serial.print("Adresse IP: ");
	Serial.println(WiFi.softAPIP());

}

void loop()
{

  WiFiClient client = server.available();

  Lclient=client.read();
	Serial.println(Lclient);
  delay(5000);
}