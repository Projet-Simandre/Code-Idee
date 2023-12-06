#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFi.h>
const char* ssid ="SimAndré";
const char* password = "12345678";
char Lclient;

WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  // ----------------------------------------- Connexion WiFi ----------------------------------------------
    Serial.println("\n[*] Creation de la zone WiFi");
    WiFi.mode(WIFI_AP);
    WiFi.softAP(ssid, password);
    Serial.print("[+] AP Created with IP Gateway ");
    Serial.println(WiFi.softAPIP());
    // -----------------------------------------------------------------------------------------------------
     // initialize serial:

  WiFi.begin(ssid, password);
 
    server.begin();
    
    



}


void loop() {
  // put your main code here, to run repeatedly:
  // listen for incoming clients
  WiFiClient client = server.available();

   if (client) {

    if (client.connected()) {
      Serial.println("Connected to client");
     
      Lclient = client.read();
      
  Serial.println(Lclient);
    }

  
}




}
