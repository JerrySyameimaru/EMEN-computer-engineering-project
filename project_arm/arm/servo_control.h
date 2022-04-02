#ifndef SERVO_CONTROL_H
#define SERVO_CONTRL_H

#include "Adafruit_MotorShield.h"         //for controlling step motor 
#include "Adafruit_MS_PWMServoDriver.h" 
/** this file is for controlling servo motors
 
 * and the range of 4 servo motors are: 
 *   Big arm 40 -135
 *   small arm 45 -105
 *   catch 0 - 180
 *   base 0 - 180  */
char MIN[4];
char MAX[4];
MIN[big_arm_pin] = 40;
MIN[small_arm_pin] = 45;
MIN[catch_pin] = 0;
MIN[base_pin] = 0;
MAX[big_arm_pin] = 135;
MAX[small_arm_pin] = 105;
MAX[catch_pin] = 180;
MAX[base_pin] = 180;


write_servo(servo_num,pin,angle){
    if(angle > MAX[servo_num] or angle < MIN[servo_num]){
        Serial.println("angle out of range");
        return;
    }
    double real_angle = angle*0.922222;
    double pulse = real_angle/90.0 + 0.5;
    double pulselength;
    pulselength = 1000000;      
    pulselength /= 50;          
    pulselength /= 4096;       
    pulse *= 1000;              
    pulse /= pulselength;
    AFMS.setPWM( n, pulse );
}







#endif