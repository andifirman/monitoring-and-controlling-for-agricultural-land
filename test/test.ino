const int pumpPin = 23;

void setup() {
  // put your setup code here, to run once:
  pinMode(pumpPin, OUTPUT);

  digitalWrite(pumpPin, LOW);
  delay(60000);
  digitalWrite(pumpPin, HIGH);
}

void loop() {
}
