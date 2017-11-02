 #include <VarSpeedServo.h>

const int SERVO = 9;

VarSpeedServo servo;               

void setup() {
    servo.attach(SERVO, 0, 150);
    servo.slowmove(167, 200);
}

void loop() {
    ///////////////////////////////////
    // servo.slowmove(angle, velocity);
    // delay(milliseconds);
    ///////////////////////////////////
    servo.slowmove(15, 200);
    delay(1500);
    servo.slowmove(167, 200);  
    delay(3000);  
}



