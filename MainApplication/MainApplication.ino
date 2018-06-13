#include <Ultrasonic.h>

#include <Arduino.h>

//global debug flag
#define DEBUG

//pin configuration
#define FRONT_SENSOR_TRIGGER_PIN   13
#define FRONT_SENSOR_ECHO_PIN      12
//sensor specifications
#define SENSOR_MAX_DISTANCE        450
#define SENSOR_MIN_DISTANCE        2

Ultrasonic frontSensor (FRONT_SENSOR_TRIGGER_PIN,FRONT_SENSOR_ECHO_PIN,SENSOR_MAX_DISTANCE,SENSOR_MIN_DISTANCE);        

void setup() {                          
  #ifdef DEBUG
  Serial.begin(9600);  
  Serial.println("Setup finished");
  #endif
}

void loop() {
  #ifdef DEBUG
  Serial.println("\nMeasured distance:");
  Serial.print(frontSensor.getDistanceCM());
  Serial.print(" cm");
  #endif
  //wait one second
  delay(1000);
}
