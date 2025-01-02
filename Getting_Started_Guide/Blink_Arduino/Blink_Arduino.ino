/*
DESCRIPTION:
This example code uses the Robo Uno Shield to test the functionality of the IO LEDs.
Initially, all LEDs will be off. The LEDs will then blink alternately every 0.5 seconds, and finally, all LEDs will remain on.
This test ensures the LEDs on the Robo Uno Shield are functioning correctly.

AUTHOR   : Cytron Technologies Sdn Bhd
WEBSITE  : www.cytron.io
EMAIL    : support@cytron.io
*/

// Pin assignments for LEDs
const int led1 = 0;    // LED connected to pin D0
const int led2 = 1;    // LED connected to pin D1
const int led3 = 2;    // LED connected to pin D2
const int led4 = 3;    // LED connected to pin D3
const int led5 = A0;   // LED connected to analog pin A0
const int led6 = A1;   // LED connected to analog pin A1
const int led7 = A2;   // LED connected to analog pin A2
const int led8 = A3;   // LED connected to analog pin A3
const int led9 = A4;   // LED connected to analog pin A4
const int led10 = A5;  // LED connected to analog pin A5

// Define unused pins (D4-D14) to keep them off
int unusedPins[] = { 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };

void setup() {
  // Initialize unused pins as output and set them to LOW (off)
  for (int i = 0; i < sizeof(unusedPins) / sizeof(unusedPins[0]); i++) {
    pinMode(unusedPins[i], OUTPUT);
    digitalWrite(unusedPins[i], LOW);  // Keep unused pins off
  }

  // Initialize LED pins as output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
}

void loop() {
  // OFF all led
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  digitalWrite(led9, LOW);
  digitalWrite(led10, LOW);
  delay(10);

  // Alternating blinking pattern for all LEDs
  digitalWrite(led1, HIGH);
  delay(500);
  digitalWrite(led1, LOW);
  delay(500);
  digitalWrite(led2, HIGH);
  delay(500);
  digitalWrite(led2, LOW);
  delay(500);
  digitalWrite(led3, HIGH);
  delay(500);
  digitalWrite(led3, LOW);
  delay(500);
  digitalWrite(led4, HIGH);
  delay(500);
  digitalWrite(led4, LOW);
  delay(500);
  digitalWrite(led5, HIGH);
  delay(500);
  digitalWrite(led5, LOW);
  delay(500);
  digitalWrite(led6, HIGH);
  delay(500);
  digitalWrite(led6, LOW);
  delay(500);
  digitalWrite(led7, HIGH);
  delay(500);
  digitalWrite(led7, LOW);
  delay(500);
  digitalWrite(led8, HIGH);
  delay(500);
  digitalWrite(led8, LOW);
  delay(500);
  digitalWrite(led9, HIGH);
  delay(500);
  digitalWrite(led9, LOW);
  delay(500);
  digitalWrite(led10, HIGH);
  delay(500);
  digitalWrite(led10, LOW);
  delay(1000);  // Pause before next sequence

  // Set a new blinking pattern
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
  digitalWrite(led9, HIGH);
  digitalWrite(led10, HIGH);
  delay(500);
}
