/*************************************************************
Coding for pump and relay
By Maker's Hub Politeknik Kota Kinabalu 
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "f5ef71342ddf4da29c86c1a4c6eb0868";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "azlynn";
char pass[] = "Alynn121";

int relay = D4;
void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(relay,OUTPUT);
  Blynk.begin(auth, ssid, pass);
  digitalWrite(relay,HIGH);

}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V5){
  int val = param.asInt();
  if(val == HIGH)
  {
    digitalWrite(relay, LOW);
  }
  else{
    digitalWrite(relay, HIGH);
  }
  
}

