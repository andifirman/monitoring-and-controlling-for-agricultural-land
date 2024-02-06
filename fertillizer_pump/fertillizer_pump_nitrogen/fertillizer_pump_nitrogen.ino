const int nitrogen_pump   = 22;

void setup() {
  pinMode(nitrogen_pump, OUTPUT);
  
  digitalWrite(nitrogen_pump, LOW);
  delay(1522);
  digitalWrite(nitrogen_pump, HIGH); 
}

void loop() {
}
