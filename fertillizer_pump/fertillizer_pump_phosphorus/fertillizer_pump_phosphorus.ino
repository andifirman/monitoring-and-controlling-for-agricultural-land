const int kalium_pump   = 19;

void setup() {
  pinMode(kalium_pump, OUTPUT);
  
  digitalWrite(kalium_pump, LOW);
  delay(1452);
  digitalWrite(kalium_pump, HIGH); 
}

void loop() {
}
