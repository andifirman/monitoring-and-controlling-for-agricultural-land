const int soilMoisturePin = 34;
//const int soilMoisturePin = A0;

int soilMoisturePercent;
float tegangan;


void readSoilMoisture() {
  int adc = (analogRead(soilMoisturePin) + 1)/4;
//  int adc = analogRead(soilMoisturePin);

  tegangan = adc * (5.0 / 1023.0);
//  int soilMoisturePercent = (adc / 1023) * 100;
  soilMoisturePercent = (100 - ((adc/1023.00)*100));
  
  Serial.print("ADC:");
  Serial.print(adc);
  Serial.print(" || Kelembaban: ");
  Serial.print(soilMoisturePercent);
  Serial.println("%");

//  delay(1000);
}
