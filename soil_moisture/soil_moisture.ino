const int soilMoisturePin = 34;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int adc = (analogRead(soilMoisturePin) + 1) / 4;
  float tegangan = adc * (5.0 / 1023.0);
  int soilMoisturePercent = (100 - ((adc / 1023.00) * 100));

  Serial.print("ADC:");
  Serial.print(adc);
  Serial.print(" | ");
  Serial.print("Kelembaban: ");
  Serial.print(soilMoisturePercent);
  Serial.println("%");

  delay(2000);
}
