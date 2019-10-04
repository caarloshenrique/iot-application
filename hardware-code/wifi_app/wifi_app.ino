
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "oficinaiot-5638d.firebaseio.com"
#define FIREBASE_AUTH "TWLTup0Ff1AJ0PyaN3Z7RAW5QgoTtq2uUHUQ2i0X"
#define WIFI_SSID "Casa"
#define WIFI_PASSWORD "12345678"



void setup() {
  Serial.begin(9600);
  pinMode(D0,OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  String estado= Firebase.getString("oficinaiot/estado");
  Serial.println(estado);
  if(estado=="\"0\""){
    digitalWrite(D0,LOW);  
  }else if(estado=="\"1\""){
    digitalWrite(D0,HIGH);  
  }
}
