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


/* Two "independant" timed events */
const long eventTime_1_byte = 250; //in ms
const long eventTime_2_npk = 3000; //in ms

/* When did they start the race? */
unsigned long previousTime_byte = 0;
unsigned long previousTime_npk = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  /* Updates frequently */
  unsigned long currentTime = millis();

  byte val1, val2, val3;

  val1 = nitrogen();
  delay(250);
  val2 = phosphorous();
  delay(250);
  val3 = potassium();
  delay(250);

  /* This is my event_2 */
  if ( currentTime - previousTime_npk >= eventTime_2_npk) {

    Serial.print("Nitrogen: ");
    Serial.print(val1);
    Serial.println(" mg/kg");
    Serial.print("Phosphorous: ");
    Serial.print(val2);
    Serial.println(" mg/kg");
    Serial.print("Potassium: ");
    Serial.print(val3);
    Serial.println(" mg/kg");

    /* Update the timing for the next event*/
    previousTime_npk = currentTime;
  }

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
