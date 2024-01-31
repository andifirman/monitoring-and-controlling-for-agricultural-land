#include "serverTime.h"
#include "time.h"
#include "connection.h"

const int pumpPin                            = 23;

#define ENABLED                                HIGH
#define DISABLED                               LOW

#define OPEN_WATER_PUMP_GATE                   LOW
#define CLOSE_WATER_PUMP_GATE                  HIGH

bool IS_WATER_GATE_OPEN                      = DISABLED;

unsigned long currentTime = 0;

// For reading time every 1 second
unsigned long timeInterval                   = 1000; // the time we need to wait
unsigned long previousTime                   = 0; // millis() returns an unsigned long.

// For turning on water pump in 1 minutes
unsigned long timeInterval_pump              = 60000; // the time we need to wait
unsigned long previousTime_pump              = 0; // millis() returns an unsigned long.



void setup() {
  Serial.begin(9600);
  initWiFi();

  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();

  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, HIGH);
}

void loop() {
  currentTime = millis();

  printNtpTime();

  turningOnWaterPump();






}


void turningOnWaterPump() {
  if (IS_WATER_GATE_OPEN == ENABLED && currentTime - previousTime_pump >= timeInterval_pump) {
    digitalWrite(pumpPin, CLOSE_WATER_PUMP_GATE);

    IS_WATER_GATE_OPEN = DISABLED;
  }

// First watering
  if (myHour == 21 && myMinute == 44 && mySecond == 00) {
    if (IS_WATER_GATE_OPEN == DISABLED) {
      digitalWrite(pumpPin, OPEN_WATER_PUMP_GATE);

      IS_WATER_GATE_OPEN = ENABLED;
      previousTime_pump = currentTime;
    }
  }

// Second watering
  if (myHour == 19 && myMinute == 54 && mySecond == 00) {
    if (IS_WATER_GATE_OPEN == DISABLED) {
      digitalWrite(pumpPin, OPEN_WATER_PUMP_GATE);

      IS_WATER_GATE_OPEN = ENABLED;
      previousTime_pump = currentTime;
    }
  }
}



void printNtpTime() {
  if (currentTime - previousTime >= timeInterval) {
    previousTime = currentTime;
    printLocalTime();

    Serial.print(myHour);
    Serial.print(":");
    Serial.print(myMinute);
    Serial.print(":");
    Serial.println(mySecond);
  }
}
