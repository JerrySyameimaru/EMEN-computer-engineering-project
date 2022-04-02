#include "Wire.h"
#include "PS2X_lib.h"
#include "Adafruit_MotorShield.h"
#include "Adafruit_MS_PWMServoDriver.h"
#include "QGPMaker_Encoder.h"
#include "QGPMaker_MotorShield.h"
#define PS2_DAT 10
#define PS2_CMD 11
#define PS2_CS 12
#define PS2_CLK 13
PS2X ps2x;

long ARM_MIN[]={0, 40, 45, 0};
long ARM_MAX[]={180, 105, 135, 180};
QGPMaker_MotorShield AFMS = QGPMaker_MotorShield();
QGPMaker_Servo *servo_base = AFMS.getServo(0);
QGPMaker_Servo * servo_big_arm = AFMS.getServo(1);
QGPMaker_Servo *servo_small_arm = AFMS.getServo(2);
QGPMaker_Servo *servo_catch = AFMS.getServo(3);

void setup(){
  AFMS.begin(50);
  
  int error = 0;
  do{
    error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_CS, PS2_DAT, true, true);
    if(error == 0){
      break;
    }else{
      delay(100);
    }
  }while(1);
  for(size_t i = 0; i < 50; i++)
  {
        ps2x.read_gamepad(false, 0);
        delay(10);
}
void loop(){
  ps2x.read_gamepad(false, 0);
  delay(3);
  
  if (ps2x.Button(PSB_CROSS)) {
    ps2x.read_gamepad(true, 200);
    delay(300);
    ps2x.read_gamepad(false, 0);//按X震动手柄

  }
  if (ps2x.Analog(PSS_LX) > 240) {
    if (servo_base->readDegrees() > ARM_MIN[(int)(0)]) {
      servo_base->writeServo((servo_base->readDegrees() - 1));
    }

  } else if (ps2x.Analog(PSS_LX) < 10) {
    if (servo_base->readDegrees() < ARM_MAX[(int)(0)]) {
      servo_base->writeServo((servo_base->readDegrees() + 1));
    }
  }
  if (ps2x.Analog(PSS_LY) > 240) {
    if ( servo_big_arm->readDegrees() > ARM_MIN[(int)(1)]) {
       servo_big_arm->writeServo(( servo_big_arm->readDegrees() - 1));
    }

  } else if (ps2x.Analog(PSS_LY) < 10) {
    if ( servo_big_arm->readDegrees() < ARM_MAX[(int)(1)]) {
       servo_big_arm->writeServo(( servo_big_arm->readDegrees() + 1));
    }
  }
  if (ps2x.Analog(PSS_RY) > 240) {
    if (servo_small_arm->readDegrees() > ARM_MIN[(int)(2)]) {
      servo_small_arm->writeServo((servo_small_arm->readDegrees() - 1));
    }

  } else if (ps2x.Analog(PSS_RY) < 10) {
    if (servo_small_arm->readDegrees() < ARM_MAX[(int)(2)]) {
      servo_small_arm->writeServo((servo_small_arm->readDegrees() + 1));
    }
  }
  if (ps2x.Analog(PSS_RX) > 240) {
    if (servo_catch->readDegrees() > ARM_MIN[(int)(3)]) {
      servo_catch->writeServo((servo_catch->readDegrees() - 1));
    }

  } else if (ps2x.Analog(PSS_RX) < 10) {
    if (servo_catch->readDegrees() < ARM_MAX[(int)(3)]) {
      servo_catch->writeServo((servo_catch->readDegrees() + 1));
    }
  }
  delay(10);

}


