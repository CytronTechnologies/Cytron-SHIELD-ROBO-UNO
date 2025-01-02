/*******************************************************************************
 * THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTY AND SUPPORT
 * IS APPLICABLE TO THIS SOFTWARE IN ANY FORM. CYTRON TECHNOLOGIES SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR CONSEQUENTIAL
 * DAMAGES, FOR ANY REASON WHATSOEVER.
 ********************************************************************************
 * DESCRIPTION:
 *
 * This example shows how to drive 2 motors using 4 PWM pins (2 for each motor)
 * with 2-channel motor driver.
 * 
 * 
 * CONNECTIONS:
 * 
 * Arduino D4  - Motor Driver DIR 1 Input
 * Arduino D5  - Motor Driver PWM 1 Input
 * Arduino D6  - Motor Driver PWM 2 Input
 * Arduino D7  - Motor Driver DIR 2 Input
 * Arduino GND - Motor Driver GND
 *
 *
 * AUTHOR   : Kong Wai Weng
 * COMPANY  : Cytron Technologies Sdn Bhd
 * WEBSITE  : www.cytron.io
 * EMAIL    : support@cytron.io
 *
 *******************************************************************************/

 #include "CytronMotorDriver.h"


// Configure the motor driver.
CytronMD f1(PWM_DIR, 5, 4);   // PWM 1A = Pin 4, PWM 1B = Pin 5.
CytronMD f2(PWM_DIR, 6, 7); // PWM 2A = Pin 6, PWM 2B = Pin 7.


// The setup routine runs once when you press reset.
void setup() {
  
}


// The loop routine runs over and over again forever.
void loop() {
  f1.setSpeed(128);   // Motor 1 runs forward at 50% speed.
  f2.setSpeed(-128);  // Motor 2 runs backward at 50% speed.
  delay(1000);
  
  f1.setSpeed(255);   // Motor 1 runs forward at full speed.
  f2.setSpeed(-255);  // Motor 2 runs backward at full speed.
  delay(1000);

  f1.setSpeed(0);     // Motor 1 stops.
  f2.setSpeed(0);     // Motor 2 stops.
  delay(1000);

  f1.setSpeed(-128);  // Motor 1 runs backward at 50% speed.
  f2.setSpeed(128);   // Motor 2 runs forward at 50% speed.
  delay(1000);
  
  f1.setSpeed(-255);  // Motor 1 runs backward at full speed.
  f2.setSpeed(255);   // Motor 2 runs forward at full speed.
  delay(1000);

  f1.setSpeed(0);     // Motor 1 stops.
  f2.setSpeed(0);     // Motor 2 stops.
  delay(1000);
}