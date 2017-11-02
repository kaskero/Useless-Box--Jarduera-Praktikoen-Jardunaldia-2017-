#include <VarSpeedServo.h>

const int BUTTON = 8;
const int SERVO = 9;

VarSpeedServo servo;               

void setup() {
    servo.attach(SERVO, 0, 150);
    servo.slowmove(167, 200);
}

void loop() {
    bool botoia = digitalRead(BUTTON);
    if(botoia == true) {   
        servo.slowmove(0, 200);
        delay(100);
        servo.slowmove(167, 200); 
    }   
}



