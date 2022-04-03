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
const char num_servos = 4;
const char catch_pin = 0;
const char small_arm_pin = 1;
const char big_arm_pin = 2;
const char base_pin = 3;

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
char MIN[4];
char MAX[4];
void set_limits(){
    MIN[big_arm_pin] = 40;
    MIN[small_arm_pin] = 45;
    MIN[catch_pin] = 0;
    MIN[base_pin] = 0;
    MAX[big_arm_pin] = 135;
    MAX[small_arm_pin] = 105;
    MAX[catch_pin] = 180;
    MAX[base_pin] = 180;  
}


void write_servo(char servo_num,char angle){
    set_limits();
    if(angle > MAX[servo_num] || angle < MIN[servo_num]){
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
    AFMS.setPWM( servo_num, pulse );
}
void back_to_original_angle(){
    write_servo(catch_pin,90);
    write_servo(small_arm_pin,45);
    write_servo(big_arm_pin,45);
    write_servo(base_pin,90);
}






#endif