//#include "PS2X_lib.h"                    //for connecting joypad
//#include "BTJoystick.h"
#include "pid.h"
#include "servo_control.h"
#include <SoftwareSerial.h> 
#include "Adafruit_MotorShield.h"         //for controlling step motor 
#include "Adafruit_MS_PWMServoDriver.h" 
#include <Wire.h>

// servo parameters
const char num_servos = 4;
const char catch_pin = 0;
const char small_arm_pin = 1;
const char big_arm_pin = 2;
const char base_pin = 3;




PID_Controller pid_base;
PID_Controller pid_big_arm;
PID_Controller pid_small_arm;
PID_Controller pid_catch;
float count = 0;
void setup(){
  Serial.begin( 57600 );  //串口通讯波特率57600
  //softSerial.begin(9600); //软串口通讯开启波特率9600，此项设置必须与蓝牙模块串口波特率一致
  //softSerial.listen();    //开启软串口数据监听
  delay( 2000 );  

  

}

void loop(){
  count = count+5;


}


void record(){    // is used to record the previous state when xxx button pressed



}
