#include <VarSpeedServo.h>

const int SERVO = 9;

VarSpeedServo servo;   

void setup() {
  // put your setup code here, to run once:
  servo.attach(SERVO, 0, 150);
  servo.slowmove(167, 200);
}

void loop() {
  // put your main code here, to run repeatedly:

}
