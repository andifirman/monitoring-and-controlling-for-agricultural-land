const int pumpPin = 23;

const int n_pin = 22;
const int p_pin = 21;
const int k_pin = 19;

void setup() {
  // put your setup code here, to run once:
  pinMode(pumpPin, OUTPUT);
  
//  pinMode(n_pin, OUTPUT);
//  pinMode(p_pin, OUTPUT);
//  pinMode(k_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
//  digitalWrite(n_pin, HIGH);
//  digitalWrite(p_pin, HIGH);
//  digitalWrite(k_pin, HIGH);
//  delay(1000);
//  digitalWrite(n_pin, LOW);
//  digitalWrite(p_pin, LOW);
//  digitalWrite(k_pin, LOW);
//  delay(1000);

  digitalWrite(pumpPin, HIGH);
  delay(1000);
  digitalWrite(pumpPin, LOW);
  delay(1000);
}
