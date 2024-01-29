unsigned long previousMillis = 0; // millis() returns an unsigned long.

bool pumpPinState = false; // state variable for the LED
const int pumpPin = 23;


void setup() {
  pinMode(pumpPin, OUTPUT);
  digitalWrite(pumpPin, pumpPinState);
}

void loop() {
//  npkValueDelay();
}

// Menghidupkan pompa selama satu menit
void oneMinutePump() {
  unsigned long currentMillis = millis(); // grab current time
  unsigned long interval = 60000; // the time we need to wait

  // check if "interval" time has passed (60000 milliseconds)
  if ((unsigned long)(currentMillis - previousMillis) >= interval) {

    pumpPinState = !pumpPinState; // "toggles" the state
    digitalWrite(pumpPin, pumpPinState); // sets the LED based on ledState

    // save the "current" time
    previousMillis = millis();
  }
}

void oneMinuteDelay() {
  unsigned long currentMillis = millis(); // grab current time
  unsigned long interval = 60000; // the time we need to wait

  // check if "interval" time has passed (60000 milliseconds)
  if ((unsigned long)(currentMillis - previousMillis) >= interval) {
    // save the "current" time
    previousMillis = millis();
  }
}

void oneSecondDelay() {
  unsigned long currentMillis = millis(); // grab current time
  unsigned long interval = 1000; // the time we need to wait

  // check if "interval" time has passed (1000 milliseconds)
  if ((unsigned long)(currentMillis - previousMillis) >= interval) {
    // save the "current" time
    previousMillis = millis();
  }
}

void threeSecondDelay() {
  unsigned long currentMillis = millis(); // grab current time
  unsigned long interval = 3000; // the time we need to wait

  // check if "interval" time has passed (3000 milliseconds)
  if ((unsigned long)(currentMillis - previousMillis) >= interval) {
    // save the "current" time
    previousMillis = millis();
  }
}

void npkValueDelay() {
  unsigned long currentMillis = millis(); // grab current time
  unsigned long interval = 250; // the time we need to wait

  // check if "interval" time has passed (250 milliseconds)
  if ((unsigned long)(currentMillis - previousMillis) >= interval) {
    pumpPinState = !pumpPinState; // "toggles" the state
    digitalWrite(pumpPin, pumpPinState); // sets the LED based on ledState

    // save the "current" time
    previousMillis = millis();
  }
}
