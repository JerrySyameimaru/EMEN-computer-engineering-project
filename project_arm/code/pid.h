#ifndef PID_H
#define PID_H


class PID_Controller{
private:
    float KI;
    float KP;
    float KD;
    float error_now;
    float error_pre;
    float integral;
    float integral_max;
    float output_max;

public:
    void set_error(float error){
        error_now = error;
    }
    void set_error_pre(float error){
        error_pre = error;
    }
    float get_error_now(){
        return error_now;
    }
    float get_error_pre(){
        return error_pre;
    }
    float get_KD(){
        return KD;
    }
    float get_KP(){
        return KP;
    }
    float get_max(){
        return output_max;
    }
    float start_integral(){
        integral += KI * error_now;
        integral = integral > integral_max ? integral_max : integral;
        integral = integral < -integral ? -integral_max : integral;
    }

};




#endif