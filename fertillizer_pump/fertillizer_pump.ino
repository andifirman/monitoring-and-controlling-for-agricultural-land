const int nitrogen_pump   = 22;
const int phosphorus_pump = 21;
const int kalium_nitrogen = 19;

void setup() {
  pinMode(phosphorus_pump, OUTPUT);
  digitalWrite(phosphorus_pump, LOW);
  delay(60000);
  digitalWrite(phosphorus_pump, HIGH);
  
}

void loop() {
}
