#include "mbed.h"
#include "PID.h"
#define P 2
#define I 0.0
#define D 0.5
#define desirePosition 4800
float pidValue;
int encoderPos;
//Init for Motor
PwmOut PwmMotor(PB_5);
DigitalOut directionMotor(PB_10);

//Init for encoders
InterruptIn EncoderA(PA_1);
DigitalIn EncoderB(PC_1);
//*************************
Ticker timerPID;
PID pid(P,I,D);

void encoderInterruptRoutine(){
        if(EncoderB == 0) encoderPos--;   
        else encoderPos++;
        pid.positionSet(encoderPos);        
    }
void timeInterruptRoutine(){
        pidValue = pid.calculation(desirePosition);
        if(pid.errorGet() !=0){
        if(pidValue < 100.0f) PwmMotor.write(0.05f);
        else PwmMotor = pidValue/1000;
        }
        else if(pid.errorGet() == 0) PwmMotor.write(0.0f);
    }
int main() {
    PwmMotor.period(0.00005); //sets PWM to 20KHz 
    EncoderA.rise(&encoderInterruptRoutine); //it will jump in encoderInterruptRoutine everytime digital pin gets rising edge
    timerPID.attach(&timeInterruptRoutine,0.01); //it will jump in timeInterruptRoutine every 0.01 seconds
    while(1) {
        if(encoderPos > desirePosition) directionMotor = 1;
        else directionMotor = 0;       
    }
}
