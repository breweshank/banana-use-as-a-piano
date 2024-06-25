const int bananaPin1 = A0; // Pin connected to the first banana
const int bananaPin2 = A1; // Pin connected to the second banana
const int bananaPin3 = A2; // Pin connected to the third banana
const int buzzerPin = 9; // Pin connected to the buzzer

// Threshold values for detecting touch
const int threshold = 30;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int sensorValue1 = touchRead(bananaPin1);
  int sensorValue2 = touchRead(bananaPin2);
  int sensorValue3 = touchRead(bananaPin3);

  // Debugging prints
  Serial.print("Banana 1: ");
  Serial.print(sensorValue1);
  Serial.print("  Banana 2: ");
  Serial.print(sensorValue2);
  Serial.print("  Banana 3: ");
  Serial.println(sensorValue3);

  if (sensorValue1 > threshold) {
    playTone(262); // C note
  } else if (sensorValue2 > threshold) {
    playTone(294); // D note
  } else if (sensorValue3 > threshold) {
    playTone(330); // E note
  } else {
    noTone(buzzerPin);
  }

  delay(100);
}

// Function to read touch sensor value
int touchRead(int pin) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  delay(1);

  pinMode(pin, INPUT);
  int value = analogRead(pin);
  return value;
}

// Function to play a tone
void playTone(int frequency) {
  tone(buzzerPin, frequency);
}
