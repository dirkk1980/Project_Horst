#include <Arduino.h>
#include <HCSR04.h>
#include <DRV8871.h>
#include <DRV8871Dual.h>

//pin configuration ultrasonic front sensor
#define FRONT_SENSOR_TRIGGER_PIN   12
#define FRONT_SENSOR_ECHO_PIN      13


//pin configuration motor left
#define MOTOR_LEFT_IN_1           5
#define MOTOR_LEFT_IN_2            6

//pin configuration motor right
#define MOTOR_RIGHT_IN_1           9
#define MOTOR_RIGHT_IN_2            10

HCSR04 frontSensor (FRONT_SENSOR_TRIGGER_PIN, FRONT_SENSOR_ECHO_PIN);
DRV8871 motor_left (MOTOR_LEFT_IN_1, MOTOR_LEFT_IN_2);
DRV8871 motor_right (MOTOR_RIGHT_IN_1, MOTOR_RIGHT_IN_2);
DRV8871Dual motorController (&motor_left, &motor_right);

void setup() {                          

}

void loop() {
  if (frontSensor.getObstacle(750
  ))
  {
    motorController.turn(200, motorController.TURN_RIGHT);
  } else {
    motorController.drive(200, motorController.DIRECTION_FORWARD);
  }
  
  delay(100);
}
