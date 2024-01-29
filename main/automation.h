long lastTime = 0;
long minutes = 0;

//const int 22 = 26;

const int pompa_nitrogen = 22;
const int pompa_phosphorus = 21;
const int pompa_kalium = 19;



void sprinkling() {
  if (millis() - lastTime > 289000) {
    digitalWrite(22, HIGH);
    minutes++;
    lastTime = millis();
  }

  if (minutes > 289) {
    digitalWrite(22, LOW);
    minutes = 0;
  }
  Serial.println(minutes);
}
