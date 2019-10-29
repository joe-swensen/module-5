#include <ESP32Servo.h>
#include <Stepper.h>

const int stepsPerRevolution = 2048; //amount of steps per revolution in this motor
Stepper myStepper(stepsPerRevolution, 16, 17, 18, 19); //sets up a stepper on the channels we used
Servo myServo;  //sets up servo

int servoPosition = 0;
int increment = 10; //distance the servo moves per stepper rotation

void setup() { //set everything to original positions, begin serial connection
  myServo.write(servoPosition);
  myServo.attach(27);
  Serial.begin(115200);
  myStepper.setSpeed(10);
}

void loop(){

  // set motor positions
  myStepper.step(2048);
  servoPosition = servoPosition + increment;
  if (servoPosition >= 180) { //reset servo if neccesary
    servoPosition = 0;
  }
  myServo.write(servoPosition);
  
}
