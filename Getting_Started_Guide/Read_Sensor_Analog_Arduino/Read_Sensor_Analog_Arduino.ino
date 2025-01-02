/*
DESCRIPTION:
This example code will use Robo Uno Sield to read the analog input from Maker Soil Module
and then show the result on serial monitor. This code also applicable to any analog sensor.

CONNECTION:

-GROVE 1-      | Maker Soil
Robo Uno Sield | 
---------------------------
GND            | GND
VCC            | VCC
A0             | DIS
A1             | OUT

AUTHOR   : Cytron Technologies Sdn Bhd
WEBSITE  : www.cytron.io
EMAIL    : support@cytron.io
*/

int sensorPin = A0;    // select the "OUT" pin for the Maker Soil
int raw_value = 0; 
float voltage_value = 0; 

void setup() {
  // declare the sensorPin as an INPUT:
  pinMode(sensorPin, INPUT);
  Serial.begin(9600);
}

void loop() {

  // read the value from the sensor:
  raw_value = analogRead(sensorPin);

  // Convert the raw ADC value to voltage (3.3V is the board's voltage reference)
  voltage_value = (raw_value * 5.0) / 1023;
  
  Serial.print("Raw Value : ");
  Serial.println(raw_value);
  Serial.print("Voltage Value : ");
  Serial.println(voltage_value);
  Serial.println("---------------------------");
  
  delay(1000);
}

