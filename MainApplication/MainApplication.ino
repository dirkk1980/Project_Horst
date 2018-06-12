#include <Arduino.h>

#define FRONT_SENSOR_TRIGGER_PIN   11
#define FRONT_SENSOR_ECHO_PIN      10
#define MAX_DISTANCE_FRONT         200
#define SONIC_SPEED                0.0343

void setup() {
  //Serial.begin(9600);                         
  pinMode(FRONT_SENSOR_TRIGGER_PIN, OUTPUT);              
  pinMode(FRONT_SENSOR_ECHO_PIN, INPUT);               
  //Serial.println("Setup finished");
}

void loop() {
  //distance is measured in centimeter
  int distance = getDistance();
  //Serial.println("Measured distance: "+ distance);
  //wait one second
  delay(1000);
}

int getDistance() {

  //disable trigger for x miliseconds to get a clear signal
  digitalWrite(FRONT_SENSOR_TRIGGER_PIN, LOW);
  delayMicroseconds(5);
  
  //sending and receiving new measurement
  noInterrupts();
  digitalWrite(FRONT_SENSOR_TRIGGER_PIN, HIGH); 
  delayMicroseconds(10);
  digitalWrite(FRONT_SENSOR_TRIGGER_PIN, LOW);
  long echoTime = pulseIn(FRONT_SENSOR_ECHO_PIN, HIGH); 
  interrupts();

  echoTime = (echoTime / 2); 
  //return distance in cm
  return (echoTime * SONIC_SPEED);
}
