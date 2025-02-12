/*******************************************************************************
 * Robo Uno Shield - Out-Of-The-Box (OOTB) Demo Code
 *
 * Welcome to the world of the Robo Uno Shield!
 * This program demonstrates the core features of the Robo Uno Shield, including:
 * 1. Happy Birthday melody on the buzzer
 * 2. Sequential LED blinking (D0-D3, A0-A5), followed by all LEDs blinking
 * 3. RGB LED color cycling
 * 4. Servo motor sweeping between 0° and 180° with RGB feedback
 * 5. Motor running forward and backward using Cytron Motor Driver library
 * 6. Button-triggered buzzer and RGB LED color changes
 *
 * Author: Cytron Technologies Sdn Bhd
 * Company: Cytron Technologies Sdn. Bhd.
 * Website: www.cytron.io
 *******************************************************************************/

#include <Servo.h>
#include "CytronMotorDriver.h"
#include <Adafruit_NeoPixel.h>

// Pin Definitions
#define BUZZER 8
#define RGB_PIN 13
#define BUTTON1 2  // Button on D2
#define BUTTON2 3  // Button on D3

//LED
#define LED_D0 0
#define LED_D1 1
#define LED_D2 2
#define LED_D3 3

// Motor Driver
CytronMD motor1(PWM_DIR, 5, 4);  // Motor 1: PWM = Pin 5, DIR = Pin 4
CytronMD motor2(PWM_DIR, 6, 7);  // Motor 2: PWM = Pin 6, DIR = Pin 7

// Servo
Servo servo1;
Servo servo2;

// RGB LED
Adafruit_NeoPixel rgb(2, RGB_PIN, NEO_GRB + NEO_KHZ800);

// Buzzer Melody
int melody_note[] = { 392, 392, 440, 392, 523, 494, 392, 392, 440, 392, 587, 523 };
int melody_duration[] = { 130, 130, 230, 230, 230, 300, 130, 130, 230, 230, 230, 300 };
int melody_length = sizeof(melody_note) / sizeof(melody_note[0]);

// Function Prototypes
void playHappyBirthday();
void blinkAllLEDs();
void demoRGB();
void servoDemo();
void motorDemo();
void buttonAction(int note1, int note2, int note3);
void setRGBColor(int r, int g, int b, int r2 = 0, int g2 = 0, int b2 = 0);

void setup() {
  // Initialize Serial
  Serial.begin(9600);
  Serial.println("Robo Uno Shield OOTB Demo");

  // Set all LED pins as outputs
  pinMode(LED_D0, OUTPUT);
  pinMode(LED_D1, OUTPUT);
  pinMode(LED_D2, OUTPUT);
  pinMode(LED_D3, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);

  // Initialize all pins to LOW
  digitalWrite(LED_D0, LOW);
  digitalWrite(LED_D1, LOW);
  digitalWrite(LED_D2, LOW);
  digitalWrite(LED_D3, LOW);


  // Initialize Buzzer
  pinMode(BUZZER, OUTPUT);

  // Initialize Buttons
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);

  // Initialize RGB
  rgb.begin();
  rgb.setBrightness(25);  // 10% brightness (out of 255)
  rgb.show();

  // Initialize Servo
  servo1.attach(9);   // Servo on Pin 9
  servo2.attach(10);  // Servo on Pin 10


  /* =====START ROUTINE===== */

  // Play Happy Birthday on Buzzer
  playHappyBirthday();
  // delay(500);

  // Blink LEDs Individually
  blinkAllLEDs();
  // delay(500);

  // RGB Demo (R, G, B + Spectral Colors)
  demoRGB();
  delay(500);

  // Servo Demo (0° ↔ 180°)
  servoDemo();
  delay(500);

  // Motor Demo (Forward ↔ Reverse)
  motorDemo();
  delay(500);
}

void loop() {
  // Check Button 1 (D2)
  if (digitalRead(BUTTON1) == LOW) {
    setRGBColor(0, 255, 255, 255, 0, 255);  // Cyan (LED 0) + Magenta (LED 1)
    buttonAction(262, 659, 784);            // Play C, E, G
  }

  // Check Button 2 (D3)
  if (digitalRead(BUTTON2) == LOW) {
    setRGBColor(255, 255, 0, 0, 255, 128);  // Yellow (LED 0) + Emerald Green (LED 1)
    buttonAction(784, 659, 262);            // Play G, E, C
  }
  setRGBColor(0, 0, 0, 0, 0, 0);  // off RGB
}

// Function Definitions (as before)
void playHappyBirthday() {
  for (int i = 0; i < melody_length; i++) {
    tone(BUZZER, melody_note[i], melody_duration[i]);
    delay(melody_duration[i] + 50);
  }
  noTone(BUZZER);
}

void blinkAllLEDs() {
  // Clear all LEDs first
  // Digital pins D0-D3
  for (int pin = 0; pin <= 3; pin++) {
    digitalWrite(pin, LOW);
  }
  // Analog pins A0-A5
  for (int pin = A0; pin <= A5; pin++) {
    digitalWrite(pin, LOW);
  }
  delay(10);

  // Sequence through D0-D3
  for (int pin = 0; pin <= 3; pin++) {
    digitalWrite(pin, HIGH);
    delay(500);
    digitalWrite(pin, LOW);
    delay(100);
  }

  // Sequence through A0-A5
  for (int pin = A0; pin <= A5; pin++) {
    digitalWrite(pin, HIGH);
    delay(500);
    digitalWrite(pin, LOW);
    delay(100);
  }

  delay(200);

  // All LEDs on
  for (int pin = 0; pin <= 3; pin++) {
    digitalWrite(pin, HIGH);
  }
  for (int pin = A0; pin <= A5; pin++) {
    digitalWrite(pin, HIGH);
  }
  delay(500);

  // All LEDs off
  for (int pin = 0; pin <= 3; pin++) {
    digitalWrite(pin, LOW);
  }
  for (int pin = A0; pin <= A5; pin++) {
    digitalWrite(pin, LOW);
  }
  delay(500);

  // All LEDs on again
  for (int pin = 0; pin <= 3; pin++) {
    digitalWrite(pin, HIGH);
  }
  for (int pin = A0; pin <= A5; pin++) {
    digitalWrite(pin, HIGH);
  }
  delay(500);

  // All LEDs off
  for (int pin = 0; pin <= 3; pin++) {
    digitalWrite(pin, LOW);
  }
  for (int pin = A0; pin <= A5; pin++) {
    digitalWrite(pin, LOW);
  }
  delay(500);
  // All LEDs ON at end
  for (int pin = 0; pin <= 3; pin++) {
    digitalWrite(pin, HIGH);
  }
  for (int pin = A0; pin <= A5; pin++) {
    digitalWrite(pin, HIGH);
  }
  delay(100);
}

void demoRGB() {
  // Step 1: Both LEDs Red
  rgb.setPixelColor(0, rgb.Color(255, 0, 0));  // LED 0: Red
  rgb.setPixelColor(1, rgb.Color(255, 0, 0));  // LED 1: Red
  rgb.show();
  delay(500);

  // Step 2: Both LEDs Green
  rgb.setPixelColor(0, rgb.Color(0, 255, 0));  // LED 0: Green
  rgb.setPixelColor(1, rgb.Color(0, 255, 0));  // LED 1: Green
  rgb.show();
  delay(500);

  // Step 3: Both LEDs Blue
  rgb.setPixelColor(0, rgb.Color(0, 0, 255));  // LED 0: Blue
  rgb.setPixelColor(1, rgb.Color(0, 0, 255));  // LED 1: Blue
  rgb.show();
  delay(500);

  // Step 4: Both LEDs Yellow
  rgb.setPixelColor(0, rgb.Color(255, 255, 0));  // LED 0: Yellow
  rgb.setPixelColor(1, rgb.Color(255, 255, 0));  // LED 1: Yellow
  rgb.show();
  delay(500);

  // Step 5: LED 0 Cyan, LED 1 Magenta
  rgb.setPixelColor(0, rgb.Color(0, 255, 255));  // LED 0: Cyan
  rgb.setPixelColor(1, rgb.Color(255, 0, 255));  // LED 1: Magenta
  rgb.show();
  delay(500);

  // Step 6: LED 0 Red, LED 1 Green
  rgb.setPixelColor(0, rgb.Color(255, 0, 0));  // LED 0: Red
  rgb.setPixelColor(1, rgb.Color(0, 255, 0));  // LED 1: Green
  rgb.show();
  delay(500);

  // Step 7: Turn off both LEDs
  rgb.clear();
  rgb.show();
  delay(500);
}


void setRGBColor(int r, int g, int b, int r2, int g2, int b2) {
  rgb.setPixelColor(0, rgb.Color(r, g, b));     // First LED
  rgb.setPixelColor(1, rgb.Color(r2, g2, b2));  // Second LED
  rgb.show();
}

void servoDemo() {
  for (int i = 180; i >= 0; i--) {
    servo1.write(i);
    servo2.write(i);
    rgb.setPixelColor(0, rgb.Color(0, 255, 0));  // LED 0: Green
    rgb.setPixelColor(1, rgb.Color(0, 255, 0));  // LED 1: Green
    rgb.show();
    delay(10);
  }
  for (int i = 0; i <= 180; i++) {
    servo1.write(i);
    servo2.write(i);
    rgb.setPixelColor(0, rgb.Color(255, 0, 0));  // LED 0: Red
    rgb.setPixelColor(1, rgb.Color(255, 0, 0));  // LED 1: Red
    rgb.show();
    delay(10);
  }
  delay(500);
  rgb.setPixelColor(0, rgb.Color(0, 0, 0));  // LED 0: Green
  rgb.setPixelColor(1, rgb.Color(0, 0, 0));  // LED 1: Green
  rgb.show();
}

void motorDemo() {
  for (int i = 0; i < 2; i++) {
    motor1.setSpeed(128);  // Forward at 50% speed
    motor2.setSpeed(128);
    tone(BUZZER, melody_note[i % melody_length], 300);
    delay(1000);

    motor1.setSpeed(-128);  // Reverse at 50% speed
    motor2.setSpeed(-128);
    tone(BUZZER, melody_note[(i + 1) % melody_length], 300);
    delay(1000);
  }
  motor1.setSpeed(0);
  motor2.setSpeed(0);
  noTone(BUZZER);
}

void buttonAction(int note1, int note2, int note3) {
  tone(BUZZER, note1, 100);
  delay(100);
  tone(BUZZER, note2, 100);
  delay(100);
  tone(BUZZER, note3, 100);
  delay(100);
  noTone(BUZZER);
  delay(100);
}
