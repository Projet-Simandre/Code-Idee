#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFi.h>
const char* ssid ="SimAndré";
const char* password = "12345678";
char Lclient;
String n ="";
WiFiServer server(80);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
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
  String valeu1, valeur2; //Chaine qui va contenir les deux chiffres différents
   if (client) {

    
     
     while (client.connected()) {
       
    if (client.available()) {
      Lclient = client.read();
      n+= Lclient;
      for (int i = 0; i < n.length(); i++){
        if(i >= n.length()/2){
          valeur2 += n[i];
        }
        else{
          valeur1 += n[i];
        }
      }
    }
  }
  Serial.println(valeur1);
  Serial.println(valeur2);
   

  
}
n=""; 



}
