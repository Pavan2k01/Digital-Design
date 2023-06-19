//----------------------Skeleton Code--------------------//
#include <WiFi.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

//    Can be client or even host   //
#ifndef STASSID
#define STASSID "pavan"  // Replace with your network credentials
#define STAPSK  "123456789"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;


void OTAsetup() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    delay(5000);
    ESP.restart();
  }
  ArduinoOTA.begin();
}

void OTAloop() {
  ArduinoOTA.handle();
}

//-------------------------------------------------------//
int x = 2;
int y = 3;
int z = 4;
int f = 13;
void setup()
{
  OTAsetup();

  //pinMode(2, OUTPUT);
 // pinMode(4, OUTPUT);
 // pinMode(5, OUTPUT);

pinMode(2,INPUT);
pinMode(3,INPUT);
pinMode(4,INPUT);
pinMode(13,OUTPUT);
}

void loop() 
{
  OTAloop();
  delay(10);  // If no custom loop code ensure to have a delay in loop
  //-------------------//
  // Custom loop code  //
  //-------------------//
  //digitalWrite(2, HIGH);
  //digitalWrite(4, HIGH);
  //digitalWrite(5, HIGH);
  //delay(100);
  //digitalWrite(2, LOW);
  //digitalWrite(4, LOW);
  //digitalWrite(5, LOW);
  //delay(100);

x = digitalRead(2);
y = digitalRead(3);
z = digitalRead(4);
digitalWrite(13,LOW);

f = (!x&&!z)||(y&&!z);

if(f == 1)
{
digitalWrite(13,HIGH);
}
else
{
digitalWrite(13,LOW);
}
}




