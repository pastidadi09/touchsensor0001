const int touchSensorPin = 2;
const int greenLedPin = 7;
const int redLedPin = 8;
int touchCount = 0;

void setup() {
  pinMode(touchSensorPin, INPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  digitalWrite(greenLedPin, LOW);
  digitalWrite(redLedPin, LOW);

  // Inisialisasi komunikasi dengan Serial Monitor
  Serial.begin(9600);
  Serial.println("Touch Counter Started");
}

void loop() {
  int touchValue = digitalRead(touchSensorPin);

  if (touchValue == HIGH) {
    delay(50);
    if (digitalRead(touchSensorPin) == HIGH) {
      touchCount++;
      if (touchCount == 1) {

        digitalWrite(greenLedPin, HIGH);
        digitalWrite(redLedPin, LOW);
        delay(500);
        Serial.print("Led Hijau Menyala");
      } else if (touchCount == 2) {

        digitalWrite(greenLedPin, LOW);
        digitalWrite(redLedPin, HIGH);
        delay(500);
        Serial.print("Led Merah Menyala");
      } else if (touchCount == 3) {

        digitalWrite(greenLedPin, HIGH);
        digitalWrite(redLedPin, HIGH);
        delay(500);
        Serial.print("Led Hijau Dan Merah Menyala");
      } else if (touchCount == 4) {

        digitalWrite(greenLedPin, LOW);
        digitalWrite(redLedPin, LOW);
        touchCount = 0;
        delay(500);
        Serial.print("Led Tidak Menyala");
      }
      Serial.print(" : ");
      Serial.println(touchCount);
    }
  }
}
