#ifndef StepperMotor_h
#define StepperMotor_h

#define defaultDelay 2
#define defaultWheel 5
#define defaultDistance 10
#define defaultWheelDistance 9

#include "Arduino.h"
#include "string.h"
#define SerialDebug Serial

class StepperMotor {
    public:
        StepperMotor(int in1, int in2, int in3, int in4);
        StepperMotor(int in1, int in2, int in3, int in4, int in5, int in6, int in7, int in8);
        void  init();
        void  setDelay(int delayTime);
        int   getDelay();
        void  setDefaultDelay();
        void  setWheelDiameter(float diameter);
        void  setDefaultWheelDiameter();
        float getWheelDiameter();
        void  setSqrDistance(float distance);
        float getSqrDistance();
        void  setDefaultSqrDistance();
        void  setDistanceBtwWheels(float distance);
        void  setDefaultDistanceBtwWheels();
        float getDistanceBtwWheels();
        void  stepForward();
        void  stepForwardMotor1();
        void  stepForwardMotor2();
        void  stepBackward();
        void  stepBackwardMotor1();
        void  stepBackwardMotor2();
        void  turnLeft();
        void  turnRight();
        void  stepDegrees(float degrees);
        void  stepDegreesMotor1(float degrees);
        void  stepDegreesMotor2(float degrees);
        void  turnWheelDegrees(float degrees);
        void  turnDegrees(float degrees);
        void  forwardDistance(float distance);
        void  forwardDefault();
        void  backwardDefault();
        void  turnRightDefault();
        void  turnLeftDefault();

    private:
        int _in1, _in2, _in3, _in4, _delay;
        int _in5, _in6, _in7, _in8;
        bool dualMotor = false;
        float turn360 = 512;
        float wheelDiameter = defaultWheel;    // In Centimeters
        float pi = 3.141593;        // Aproxmated pi number
        float _defaultDistance = defaultDistance;
        float distanceBtwWheels = defaultWheelDistance;
        float wheelToTurn;
};

#endif
