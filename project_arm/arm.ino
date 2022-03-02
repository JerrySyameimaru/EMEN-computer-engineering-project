#include "pid.h"

void setup(){
  


}

void loop(){



}

float PID_cal(PID_Controller* pid_x, int Now_value, int Aim_value, char flag){
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