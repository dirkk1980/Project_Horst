#include <Arduino.h>

//global debug flag
#define DEBUG

//pin configuration
#define FRONT_SENSOR_TRIGGER_PIN   13
#define FRONT_SENSOR_ECHO_PIN      12
//sensor specifications
#define SENSOR_MAX_DISTANCE        450
#define SENSOR_MIN_DISTANCE        2
//sonic speed in centimeter/microsecond
#define SONIC_SPEED                0.0343

void setup() {                       
  pinMode(FRONT_SENSOR_TRIGGER_PIN, OUTPUT);              
  pinMode(FRONT_SENSOR_ECHO_PIN, INPUT);               
  #ifdef DEBUG
  Serial.begin(9600);  
  Serial.println("Setup finished");
  #endif
}

void loop() {
  //distance is measured in centimeter
  float distance = getDistance();
  #ifdef DEBUG
  Serial.println("\nMeasured distance:");
  Serial.print(distance);
  Serial.print(" cm");
  #endif
  //wait one second
  delay(1000);
}

float getDistance() {

  //disable trigger for x miliseconds to get a clear signal
  digitalWrite(FRONT_SENSOR_TRIGGER_PIN, LOW);
  delayMicroseconds(3);
  
  //sending and receiving new measurement
  noInterrupts();
  digitalWrite(FRONT_SENSOR_TRIGGER_PIN, HIGH); 
  delayMicroseconds(20);
  digitalWrite(FRONT_SENSOR_TRIGGER_PIN, LOW);
  //reading echo with a timeout calculated by the max distance of the sensor
  unsigned long echoTime = pulseIn(FRONT_SENSOR_ECHO_PIN, HIGH, SENSOR_MAX_DISTANCE / SONIC_SPEED); 
  interrupts();

  echoTime = (echoTime / 2); 

  //return distance in cm
  return (echoTime * SONIC_SPEED);
}
