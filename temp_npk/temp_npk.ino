//#include <SoftwareSerial.h>
#include <Wire.h>

#define RE 4
#define DE 2

const byte nitro[] = {0x01, 0x03, 0x00, 0x1e, 0x00, 0x01, 0xe4, 0x0c};
const byte phos[] = {0x01, 0x03, 0x00, 0x1f, 0x00, 0x01, 0xb5, 0xcc};
const byte pota[] = {0x01, 0x03, 0x00, 0x20, 0x00, 0x01, 0x85, 0xc0};


byte values[11];
#define RO 16
#define DI 17



void setup() {
  Serial.begin(9600);
  Serial2.begin(4800, SERIAL_8N1, RO, DI);
  //  Serial2.begin(4800);

  // Initiation for NPK sensor
  pinMode(RE, OUTPUT);
  pinMode(DE, OUTPUT);

  // Starting network time protocol

  // put RS-485 into receive Serial2e
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);
}

void loop() {

  byte val1, val2, val3;

  val1 = nitrogen();
  delay(250);
  val2 = phosphorous();
  delay(250);
  val3 = potassium();
  delay(250);

  Serial.print("Nitrogen: ");
  Serial.print(val1);
  Serial.println(" mg/kg");
  Serial.print("Phosphorous: ");
  Serial.print(val2);
  Serial.println(" mg/kg");
  Serial.print("Potassium: ");
  Serial.print(val3);
  Serial.println(" mg/kg");
  delay(3000);

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
