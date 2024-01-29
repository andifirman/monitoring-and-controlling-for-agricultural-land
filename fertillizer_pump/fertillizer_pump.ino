const int pompa_nitrogen = 22;

void setup() {
  pinMode(pompa_nitrogen, OUTPUT);
  
  digitalWrite(pompa_nitrogen, LOW);
  delay(60000);
  digitalWrite(pompa_nitrogen, HIGH);
}

void loop() {
}
