#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <WiFi.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>

#define WLAN_SSID "SINANDRE"
#define WLAN_PASS "12345678"

/************************* Configuration pour utiliser MQTT Adafruit *********************************/

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME    "Alex"                         //Votre nom d'utilisateur
#define AIO_KEY         "aio_Uzxs488uNBAvsf6b9RU2tz7j781v"  //Votre clef AdafruitIO suivez ce tuto pour récupérer ces infos
                                                            //https://www.wikidebrouillard.org/wiki/Cr%C3%A9er_un_compte_chez_AdafruitIO_pour_envoyer_des_donn%C3%A9es_dans_le_web
void initWiFi() {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    Serial.print("Connecting to WiFi ..");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print('.');
        delay(1000);
    }
    Serial.println(""); // affichage des paramètres 
    Serial.println("WiFi connecté");
    Serial.print("Adresse IP du module ESP32 : ");
    Serial.println(WiFi.localIP());
    Serial.print("Adresse IP de la gateway : ");
    Serial.println(WiFi.gatewayIP());
    Serial.print("Adresse IP du DNS : ");
    Serial.println(WiFi.dnsIP());
}