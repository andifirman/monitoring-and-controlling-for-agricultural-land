const int phosphorus_pump   = 19;

void setup() {
  pinMode(phosphorus_pump, OUTPUT);
  
  digitalWrite(phosphorus_pump, LOW);
  delay(1452);
  digitalWrite(phosphorus_pump, HIGH); 
}

void loop() {
}
