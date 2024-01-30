const int nitrogen_pump   = 22;
const int phosphorus_pump = 21;
const int kalium_nitrogen = 19;

void setup() {
  pinMode(nitrogen_pump, OUTPUT);
  
  digitalWrite(nitrogen_pump, LOW);
  delay(60000);
  digitalWrite(nitrogen_pump, HIGH);

}

void loop() {
}
