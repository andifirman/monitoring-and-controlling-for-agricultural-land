//#include <SoftwareSerial.h>
#include <Wire.h>

#include "serverTime.h"
#include "connection.h"
#include "soilMoisture.h"
#include "automation.h"

#define RE 4
#define DE 2

const byte nitro[] = {0x01, 0x03, 0x00, 0x1e, 0x00, 0x01, 0xe4, 0x0c};
const byte phos[] = {0x01, 0x03, 0x00, 0x1f, 0x00, 0x01, 0xb5, 0xcc};
const byte pota[] = {0x01, 0x03, 0x00, 0x20, 0x00, 0x01, 0x85, 0xc0};


byte values[11];
// RO 15 GPIO 16
// DI 16 GPIO 17
#define RO 16
#define DI 17

// ------------------------------------------- //
String farmerId = "8adb6027-a7ef-4b11-afa7-2c221965013c";
String farmLandId = "1142f86d-1c70-4cca-81ba-194157b16631";

String soilMoisturePath = farmerId + "/" + farmLandId + "/npk_sensor/soilMoisture";
String nitrogenPath = farmerId + "/" + farmLandId + "/npk_sensor/nitrogen";
String phosphorusPath = farmerId + "/" + farmLandId + "/npk_sensor/phosphorus";
String kaliumPath = farmerId + "/" + farmLandId + "/npk_sensor/kalium";
// ------------------------------------------- //

void setup() {
  Serial.begin(9600);
  Serial2.begin(4800, SERIAL_8N1, RO, DI);

  initWiFi();

  // Initiation for NPK sensor
  pinMode(RE, OUTPUT);
  pinMode(DE, OUTPUT);
  
//  pinMode(pompa_nitrogen, OUTPUT);
//  pinMode(pompa_phosphorus, OUTPUT);
//  pinMode(pompa_kalium, OUTPUT);

  // Starting network time protocol
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  //  printLocalTime();

  // put RS-485 into receive Serial2e
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);

//  digitalWrite(pompa_nitrogen, LOW);
//  digitalWrite(pompa_phosphorus, LOW);
//  digitalWrite(pompa_kalium, LOW);
  
  


  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")) {
    Serial.println("ok");
    signupOK = true;
  }
  else {
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h

  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  delay(500);
}

void loop() {
  readSoilMoisture();
  printLocalTime();

  byte val1, val2, val3;

  val1 = nitrogen();
  //  delay(250);
  val2 = phosphorous();
  //  delay(250);
  val3 = potassium();
  //  delay(250);

  Serial.print(myHour);
  Serial.print(":");
  Serial.print(myMinute);
  Serial.print(":");
  Serial.println(mySecond);

  Serial.print("Nitrogen: ");
  Serial.print(val1);
  Serial.println(" mg/kg");
  Serial.print("Phosphorous: ");
  Serial.print(val2);
  Serial.println(" mg/kg");
  Serial.print("Potassium: ");
  Serial.print(val3);
  Serial.println(" mg/kg");


  if (myHour == 17 && myMinute == 38 && mySecond == 00) {
    if (soilMoisturePercent <= 80) {
      digitalWrite(23, LOW);
      //      delay(300000);
      delay(364000);
    }
  } else {
    digitalWrite(23, HIGH);
  }


  if (myHour == 9 && myMinute == 45 && mySecond == 00 && soilMoisturePercent <= 80) {
    //    if (soilMoisturePercent <= 80) {
    digitalWrite(23, LOW);
    delay(364000);
    //    }
  } else {
    digitalWrite(23, HIGH);
  }


  //millis() - sendDataPrevMillis > 15000
  if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 60000 || sendDataPrevMillis == 0)) {
    sendDataPrevMillis = millis();
    //    // Soil Moisture
    if (Firebase.RTDB.setInt(&fbdo, soilMoisturePath, soilMoisturePercent)) {
      Serial.println("PASSED");
      //      Serial.println("PATH: " + fbdo.dataPath());
      //      Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      Serial.println("FAILED");
      //      Serial.println("REASON: " + fbdo.errorReason());
    }

    // Nitrogen
    if (Firebase.RTDB.setInt(&fbdo, nitrogenPath, val1)) {
      //      Serial.println("PASSED");
      //      Serial.println("PATH: " + fbdo.dataPath());
      //      Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      //      Serial.println("FAILED");
      //      Serial.println("REASON: " + fbdo.errorReason());
    }
    //
    //    // Phosphorus
    if (Firebase.RTDB.setInt(&fbdo, phosphorusPath, val2)) {
      //      Serial.println("PASSED");
      //      Serial.println("PATH: " + fbdo.dataPath());
      //      Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      //      Serial.println("FAILED");
      //      Serial.println("REASON: " + fbdo.errorReason());
    }
    //
    //    // Kalium
    if (Firebase.RTDB.setInt(&fbdo, kaliumPath, val3)) {
      //      Serial.println("PASSED");
      //      Serial.println("PATH: " + fbdo.dataPath());
      //      Serial.println("TYPE: " + fbdo.dataType());
    }
    else {
      //      Serial.println("FAILED");
      //      Serial.println("REASON: " + fbdo.errorReason());
    }
  }

  delay(1000);

}




byte nitrogen() {
  Serial2.flush();

  digitalWrite(DE, HIGH);
  digitalWrite(RE, HIGH);
  delay(10);
  if (Serial2.write(nitro, sizeof(nitro)) == 8) {
    Serial2.flush();
    digitalWrite(DE, LOW);
    digitalWrite(RE, LOW);
    for (byte i = 0; i < 7; i++) {
      //Serial.print(Serial2.read(),HEX);
      values[i] = Serial2.read();
      //Serial.print(values[i],HEX);
    }
    //Serial.println();
  }
  return values[4];
}

byte phosphorous() {
  Serial2.flush();

  digitalWrite(DE, HIGH);
  digitalWrite(RE, HIGH);
  delay(10);
  if (Serial2.write(phos, sizeof(phos)) == 8) {
    Serial2.flush();
    digitalWrite(DE, LOW);
    digitalWrite(RE, LOW);
    for (byte i = 0; i < 7; i++) {
      //Serial.print(Serial2.read(),HEX);
      values[i] = Serial2.read();
      //Serial.print(values[i],HEX);
    }
    //Serial.println();
  }
  return values[4];
}

byte potassium() {
  Serial2.flush();

  digitalWrite(DE, HIGH);
  digitalWrite(RE, HIGH);
  delay(10);
  if (Serial2.write(pota, sizeof(pota)) == 8) {
    Serial2.flush();
    digitalWrite(DE, LOW);
    digitalWrite(RE, LOW);
    for (byte i = 0; i < 7; i++) {
      //Serial.print(Serial2.read(),HEX);
      values[i] = Serial2.read();
      //Serial.print(values[i],HEX);
    }
    Serial.println();
  }
  return values[4];
}
