#define fertilizer_nitrogen 19
#define fertilizer_phosphorus 21
#define fertilizer_kalium 23

void setup() {
  Serial.begin(9600);

  pinMode(fertilizer_nitrogen, OUTPUT);
  pinMode(fertilizer_phosphorus, OUTPUT);
  pinMode(fertilizer_kalium, OUTPUT);

  digitalWrite(fertilizer_nitrogen, HIGH);
  digitalWrite(fertilizer_phosphorus, HIGH);
  digitalWrite(fertilizer_kalium, HIGH);
}

void loop() {
  digitalWrite(fertilizer_nitrogen, LOW);
  digitalWrite(fertilizer_phosphorus, LOW);
  digitalWrite(fertilizer_kalium, LOW);

}
