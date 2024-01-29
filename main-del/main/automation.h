long lastTime = 0;
long minutes = 0;

const int pumpPin = 26;



void sprinkling() {
  if (millis() - lastTime > 289000) {
    digitalWrite(pumpPin, HIGH);
    minutes++;
    lastTime = millis();
  }

  if (minutes > 289) {
    digitalWrite(pumpPin, LOW);
    minutes = 0;
  }
  Serial.println(minutes);
}
