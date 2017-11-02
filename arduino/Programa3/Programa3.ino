#include <VarSpeedServo.h>

#define LDR A2
const int BUTTON = 8;
const int SERVO = 9;
const int LED = 13;
const int COUNTER_MAX = 7;

VarSpeedServo servo;               

int angle = 100 ;
int velocity = 75;
int light;
int light_init = 0;
int counter = 0;
int attention_level = 1;
bool flag1 = 0;
bool flag2 = 0;
unsigned long time0 = 0;
unsigned long time1 = 0;


void setup() {
    pinMode(LDR, INPUT);         
    pinMode(BUTTON, INPUT);           
    pinMode(LED, OUTPUT);           

    delay(1000);
    light_init = analogRead(LDR);   
    servo.attach(SERVO, 0, 150);

    time0 = millis();
}

void loop() {
    if(counter < COUNTER_MAX) {                 
        velocity += (counter * 25);
    } else {
        velocity = 200;   
        light = analogRead(LDR);           
        if(light < (light_init - (0.1*light_init))) {  
            angle = map(light, 0, light_init, 5, 70); 
            servo.slowmove(angle, velocity);
            flag2 = 1;
        } else {
            flag2 = 0;
        }
    }
    
    if(digitalRead(BUTTON)) {  
        flag1 = 1;                        
        digitalWrite(LED, HIGH);
        time0 = millis();
        angle = 0;                             
    } else {      
        if(flag1) {                               
          counter = counter + 1;
          flag1 = 0;
        }
        digitalWrite(LED, LOW);
        angle = 167;                                
    }  
    if(!flag2) {
      servo.slowmove(angle, velocity);
      velocity = 75;
    }
      
    time1 = millis();
    if((time1 - time0) > 3000 && counter < COUNTER_MAX) {
        entertainment();
    }
}

void entertainment() {   
    if(attention_level == 3) {
        attention_level = 1;
    }
    
    switch(attention_level) {                     
        case 1:
            move_servo(15, 35, 1500, 0);
            move_servo(167, 200, 500 , 1);
            break;
        case 2:
            delay(1500);
            for(int i=0; i<4; i++) {
                move_servo(115, 255, 150, 0);
                move_servo(167, 255, 150, 0);
                servo.slowmove(angle, velocity);
            }
            attention_level = attention_level + 1;
            time0 = millis();
            break;
        default: 
            break;
    }
}

void move_servo(int a, int b, int c, int d) {
    servo.slowmove(a, b);
    delay(c);
    
    if(d == 1) {
        servo.slowmove(angle, velocity);
        attention_level = attention_level + 1;
    }
}


