#include "PID.h"
#include "arm_math.h"
PID::PID(float kp,float ki,float kd){
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
    position = 0;
    }
float PID::calculation(int Goal){
    error = Goal - position;
    error = error > 0 ? error : -1*error;
    proportional = kp*error;
    integral = integral + ki*error;
    derivative = (error - errorPrevious)*kd;
    errorPrevious = error;
    
    return proportional + integral + derivative;
    }
void PID::Reset(){
    errorPrevious = 0;
    position = 0;
    integral = 0;
    }
void PID::positionSet(int pos){
    position = pos;
    }
int PID::positionGet(){
    return position;
    }
int PID::errorGet(){
    return error;
    }
void PID::setPidParameters(float kp, float ki, float kd){
    this->kp = kp;
    this->ki = ki;
    this->kd = kd;
    }
