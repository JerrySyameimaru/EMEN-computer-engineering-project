#include <SoftwareSerial.h> 
#include "pid.h"
#include <Servo.h>
#include <Wire.h>
#include "PS2X_lib.h"                     //调用库文件PS2X_lib，这个是无线手柄库
#include "BTJoystick.h" 


Servo servo_base;
Servo servo_big_arm;
Servo servo_small_arm;
Servo servo_catch;


PID_Controller pid_base;
PID_Controller pid_big_arm;
PID_Controller pid_small_arm;
PID_Controller pid_catch;
void setup(){
  Serial.begin( 57600 );  //串口通讯波特率57600
  softSerial.begin(9600); //软串口通讯开启波特率9600，此项设置必须与蓝牙模块串口波特率一致
  softSerial.listen();    //开启软串口数据监听
  delay( 2000 );  
  servo_base.attach(3,0,180);
  servo_big_arm.attach(2,40,135);
  servo_small_arm.attach(1,45,105);
  servo_catch.attach(0,0,180);


}

void loop(){



}

float PID_cal(PID_Controller* pid_x, int Now_value, int Aim_value, char flag){  // flag means using integral part
  float error = Now_value - Aim_value;
  pid_x->set_error(error);

  float output = pid_x->get_KD() * (pid_x->get_error_now() - pid_x->get_error_pre())+
  pid_x->get_KP()*pid_x->get_error_now();
  if(flag == 1){
    float integral = pid_x->start_integral();
    output = output + integral;
  }
  output = output > pid_x-> get_max() ? pid_x-> get_max() : output;
  output = output > -pid_x-> get_max() ? -pid_x-> get_max() : output;
  pid_x->set_error_pre(error);
  return output;
}

void record(){    // is used to record the previous state when xxx button pressed



}