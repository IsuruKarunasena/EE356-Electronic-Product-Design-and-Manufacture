// include libraries;

#define BLYNK_TEMPLATE_ID "TMPL1Ftdj8tr"
#define BLYNK_TEMPLATE_NAME "iot smart monitoring"
#define BLYNK_AUTH_TOKEN "-LebQYAVDxv2BIoqgo0RkYXz9wlAqg_p"


char pass[] = "Eng-Student";  // WIFI Password
char ssid[] = "3nG5tuDt";  // WIFI SSID

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <dht.h>
#define soil A0  // Soil moisture sensor is A0 pin
#define DHT11_PIN D0  // humiity sensor is D0 pin

int threshold =800;


dht DHT;
//const int LED D2;

void setup() {
  Serial.begin(57600); 
  pinMode(D0,INPUT);
  pinMode(A0,INPUT);
  pinMode(D2,OUTPUT);

  BlynkTimer timer;
  Serial.begin(57600);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  Blynk.connect();
  
}

void loop() {
  Blynk.run();
  delay(5000);
  DHT.read11(DHT11_PIN);
  int humidity = DHT.humidity;

  Serial.print(humidity);
  Serial.print("/")  ;
  int temperature = DHT.temperature;

  Serial.println(temperature);
  
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, humidity);

  int value = analogRead(A0);
  Serial.println(value);
  Blynk.virtualWrite(V2, value);
  
 /* if(value > 800){
    digitalWrite(D2,HIGH);
   // digitalWrite(D2, HIGH);
   // Serial.println(2);
    }

  else{
    digitalWrite(D2,LOW);
    //Serial.println(2);
    }
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V1, humidity);
  Blynk.virtualWrite(V3, value);
  Blynk.virtualWrite(V2, D2);
  //Serial.println(value);*/

  

  if (value < 800){
    if(humidity <60){
       digitalWrite(D2,HIGH);
       Blynk.virtualWrite(V4, D2);

       
      }

     else{
       digitalWrite(D2,LOW);
       //Serial.println(D2);
       Blynk.virtualWrite(V4, D2);
      
      }
    
    
    }
  else {
    
    digitalWrite(D2,HIGH);
    Blynk.virtualWrite(V4, D2);
    
    }
 
}
