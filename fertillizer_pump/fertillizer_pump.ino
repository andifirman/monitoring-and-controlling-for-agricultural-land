const int nitrogen_pump   = 22;
const int phosphorus_pump = 21;
const int kalium_nitrogen = 19;

void setup() {
  pinMode(kalium_nitrogen, OUTPUT);
  digitalWrite(kalium_nitrogen, LOW);
  delay(60000);
  digitalWrite(kalium_nitrogen, HIGH);
  
}

void loop() {
}
