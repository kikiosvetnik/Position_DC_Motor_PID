#pragma once
class PID{
    private:
        int error;
        int errorPrevious;
        float kp;
        float ki;
        float kd;
        float proportional;
        float integral;
        float derivative;    
        int position;
    public:
        int EncoderPosition;
        PID(float kp,float ki,float kd); //constructor
        float calculation(int Goal);
        void Reset();
        void positionSet(int pos);
        int positionGet();
        int errorGet();
        void setPidParameters(float kp, float ki,float kd);
    };
