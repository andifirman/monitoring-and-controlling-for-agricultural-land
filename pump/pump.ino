#include "serverTime.h"
#include "time.h"
#include "connection.h"

// ----------------------
long lastTime = 0;
long minutes = 0;
// ----------------------


unsigned long interval = 1000; // the time we need to wait
unsigned long previousMillis = 0; // millis() returns an unsigned long.



const int pumpPin = 23;

void setup() {
  Serial.begin(9600);
  initWiFi();

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();

  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, HIGH);
  delay(1000);
}

void loop() {
//  unsigned long currentMillis = millis(); // grab current time


  //  turningOnPump();
  printLocalTime();
  //
  //
  Serial.print(myHour);
  Serial.print(myMinute);
  Serial.println(mySecond);



  if (myHour == 19 && myMinute == 50 && mySecond == 00) {
    turningOnPump();
  } else {
    turningOffPump();
  }

  //  INI PAS BUAT TERMINAL YANG 3 COLOKANNYA
//  if (myHour == 20 && myMinute == 24 && mySecond == 00) {
//    digitalWrite(pumpPin, LOW);
//    delay(364000);
//  } else {
//    digitalWrite(pumpPin, HIGH);
//  }



  

}

void turningOnPump() {
  unsigned long currentMillis = millis(); // grab current time
  
  // check if "interval" time has passed (1000 milliseconds)
  if ((unsigned long)(currentMillis - previousMillis) >= interval) {
    digitalWrite(pumpPin, HIGH);
    // save the "current" time
    previousMillis = millis();
  }
}


//void turningOnPump() {
//  if (millis() - lastTime > 57800) {
//    digitalWrite(22, LOW);
//    minutes++;
//    lastTime = millis();
//  }
//
//  if (minutes > 6) {
//    digitalWrite(22, HIGH);
//    minutes = 0;
//  }
//  Serial.println(minutes);
//}

void turningOffPump() {
  digitalWrite(pumpPin, LOW);
}
