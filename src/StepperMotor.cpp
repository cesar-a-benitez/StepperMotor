/**
 * @file StepperMotor.cpp
 * @author Cesar Augusto Benitez Barbosa (cesar.augusto@ecomp.ufsm.br)
 * @brief
 * @version 1.0
 * @date 2019-03-08
 *
 * @copyright Copyright (c) 2019
 *
 */

#include "StepperMotor.h"
//#define DebugMode

/**
 * @brief Construct a single Cubetto Motor:: Cubetto Motor object
 *
 * @param in1
 * @param in2
 * @param in3
 * @param in4
 */
StepperMotor::StepperMotor(int in1, int in2, int in3, int in4) {
    _in1 = in1;
    _in2 = in2;
    _in3 = in3;
    _in4 = in4;

    _delay = defaultDelay;
} // end constructor StepperMotor for individual motor

/**
 * @brief Construct a dual Cubetto Motor:: Cubetto Motor object
 *
 * @param in1
 * @param in2
 * @param in3
 * @param in4
 * @param in5
 * @param in6
 * @param in7
 * @param in8
 */
StepperMotor::StepperMotor(int in1, int in2, int in3, int in4, int in5, int in6, int in7, int in8) {
    _in1 = in1;
    _in2 = in2;
    _in3 = in3;
    _in4 = in4;
    _in5 = in5;
    _in6 = in6;
    _in7 = in7;
    _in8 = in8;

    dualMotor = true;
    _delay = defaultDelay + 1;
} // end constructor StepperMotorfor dual motor

/**
 * @brief Initialize the motor module
 *
 */
void StepperMotor::init() {
    pinMode(_in1, OUTPUT);
    pinMode(_in2, OUTPUT);
    pinMode(_in3, OUTPUT);
    pinMode(_in4, OUTPUT);

    if (dualMotor) {
        pinMode(_in5, OUTPUT);
        pinMode(_in6, OUTPUT);
        pinMode(_in7, OUTPUT);
        pinMode(_in8, OUTPUT);
    }

    #ifdef DebugMode
        if (dualMotor) {
            SerialDebug.println("\nMotor 1:\nin1, port: " + String(_in1) + " defined as OUTPUT....");
            SerialDebug.println("in2, port: " + String(_in2) + " defined as OUTPUT....");
            SerialDebug.println("in3, port: " + String(_in3) + " defined as OUTPUT....");
            SerialDebug.println("in4, port: " + String(_in4) + " defined as OUTPUT....");
            SerialDebug.println("\n\nMotor2:\nin1, port: " + String(_in5) + " defined as OUTPUT....");
            SerialDebug.println("in2, port: " + String(_in6) + " defined as OUTPUT....");
            SerialDebug.println("in3, port: " + String(_in7) + " defined as OUTPUT....");
            SerialDebug.println("in4, port: " + String(_in8) + " defined as OUTPUT....");
        }else {
            SerialDebug.println("\nin1, port: " + String(_in1) + " defined as OUTPUT....");
            SerialDebug.println("in2, port: " + String(_in2) + " defined as OUTPUT....");
            SerialDebug.println("in3, port: " + String(_in3) + " defined as OUTPUT....");
            SerialDebug.println("in4, port: " + String(_in4) + " defined as OUTPUT....");
        }
    #endif
} // end init function

/**
 * @brief Set delay between the steps Function
 *
 * @param delayTime
 */
void StepperMotor::setDelay(int delayTime) {
    if (delayTime >= 2) {
        _delay = delayTime;
        SerialDebug.println("Delay defined to: " + String(_delay));
    }else {
        SerialDebug.println("Invalid delay time for step (<2)");
    }
} // end setDelay function

/**
 * @brief Set Default Delay function
 *
 */
void StepperMotor::setDefaultDelay() {
    if(dualMotor) {
        _delay = defaultDelay + 1;
    }else {
        _delay = defaultDelay;
    }
} // end setDefaultDelay function

/**
 * @brief Get delay between the steps Function
 *
 * @return int
 */
int StepperMotor::getDelay() {
    return _delay;
} // end getDelay function

/**
 * @brief Set Wheel Diameter Function
 *
 * @param diameter
 */
void StepperMotor::setWheelDiameter(float diameter) {
    wheelDiameter = diameter;
} // end setWheelDiameter function

/**
 * @brief Get wheel diameter Function
 *
 * @return float
 */
float StepperMotor::getWheelDiameter() {
    return wheelDiameter;
} // end getWheelDiameter function

/**
 * @brief Set default wheel diameter function
 *
 */
void StepperMotor::setDefaultWheelDiameter() {
    wheelDiameter = defaultWheel;
} // end setDefaultWheelDiameter function

/**
 * @brief Set square distance Function
 *
 * @param distance
 */
void StepperMotor::setSqrDistance(float distance) {
    _defaultDistance = distance;
} // end setSqrDistance function

/**
 * @brief Get square distance Function
 *
 * @return float
 */
float StepperMotor::getSqrDistance() {
    return _defaultDistance;
} // end getSqrDistance function

/**
 * @brief Set default square distance function
 *
 */
void StepperMotor::setDefaultSqrDistance() {
    _defaultDistance = defaultDistance;
} // end setDefaultSqrDistance function

/**
 * @brief Set Distance Between Wheels Function
 *
 * @param distance
 */
void StepperMotor::setDistanceBtwWheels(float distance) {
    distanceBtwWheels = distance;
} // end setDistanceBtwWheels function

/**
 * @brief Get Distance Between Wheels Function
 *
 */
float StepperMotor::getDistanceBtwWheels(){
    return distanceBtwWheels;
} // end getDistanceBtwWheels function

/**
 * @brief Set Default Distance Between Wheels Function
 *
 */
void StepperMotor::setDefaultDistanceBtwWheels() {
    distanceBtwWheels = defaultWheelDistance;
}

/**
 * @brief Step Forward Function
 *
 */
void StepperMotor::stepForward() {
    //* Function that do a step using the base delay

    if (dualMotor) {
        digitalWrite(_in1, HIGH);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
        digitalWrite(_in5, LOW);
        digitalWrite(_in6, LOW);
        digitalWrite(_in7, LOW);
        digitalWrite(_in8, HIGH);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, HIGH);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
        digitalWrite(_in5, LOW);
        digitalWrite(_in6, LOW);
        digitalWrite(_in7, HIGH);
        digitalWrite(_in8, LOW);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, HIGH);
        digitalWrite(_in4, LOW);
        digitalWrite(_in5, LOW);
        digitalWrite(_in6, HIGH);
        digitalWrite(_in7, LOW);
        digitalWrite(_in8, LOW);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, HIGH);
        digitalWrite(_in5, HIGH);
        digitalWrite(_in6, LOW);
        digitalWrite(_in7, LOW);
        digitalWrite(_in8, LOW);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
        digitalWrite(_in5, LOW);
        digitalWrite(_in6, LOW);
        digitalWrite(_in7, LOW);
        digitalWrite(_in8, LOW);
        //delay(_delay);
    }else {
        digitalWrite(_in1, HIGH);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, HIGH);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, HIGH);
        digitalWrite(_in4, LOW);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, HIGH);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
        //delay(_delay);
    }
} // end stepForward function

/**
 * @brief Step Backward Function
 *
 */
void StepperMotor::stepBackward() {
    //* Function that do a step using a delay given as parameter

    if (dualMotor) {
        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, HIGH);
        digitalWrite(_in5, HIGH);
        digitalWrite(_in6, LOW);
        digitalWrite(_in7, LOW);
        digitalWrite(_in8, LOW);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, HIGH);
        digitalWrite(_in4, LOW);
        digitalWrite(_in5, LOW);
        digitalWrite(_in6, HIGH);
        digitalWrite(_in7, LOW);
        digitalWrite(_in8, LOW);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, HIGH);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
        digitalWrite(_in5, LOW);
        digitalWrite(_in6, LOW);
        digitalWrite(_in7, HIGH);
        digitalWrite(_in8, LOW);
        delay(_delay);

        digitalWrite(_in1, HIGH);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
        digitalWrite(_in5, LOW);
        digitalWrite(_in6, LOW);
        digitalWrite(_in7, LOW);
        digitalWrite(_in8, HIGH);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
        digitalWrite(_in5, LOW);
        digitalWrite(_in6, LOW);
        digitalWrite(_in7, LOW);
        digitalWrite(_in8, LOW);
        //delay(_delay);
    }else {
        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, HIGH);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, HIGH);
        digitalWrite(_in4, LOW);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, HIGH);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
        delay(_delay);

        digitalWrite(_in1, HIGH);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
        //delay(_delay);
    }
} // end stepBackward function

/**
 * @brief Step Forward Motor 1 Function (For Dual Motor Config)
 *
 */
void StepperMotor::stepForwardMotor1(){
    if(dualMotor) {
        digitalWrite(_in1, HIGH);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, HIGH);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, HIGH);
        digitalWrite(_in4, LOW);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, HIGH);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
        //delay(_delay);
    }else {
        SerialDebug.println("\n~> Function available only in Dual Motor Mode <~\n");
    }
} // end stepForwardMotor1 function

/**
 * @brief Step Backward Motor 2 Function (For Dual Motor Config)
 *
 */
void StepperMotor::stepBackwardMotor1(){
    if(dualMotor) {
        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, HIGH);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, HIGH);
        digitalWrite(_in4, LOW);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, HIGH);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
        delay(_delay);

        digitalWrite(_in1, HIGH);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
    }else {
        SerialDebug.println("\n~> Function available only in Dual Motor Mode <~\n");
    }
} // end stepBackwardMotor1 function

/**
 * @brief Step Forward Motor 2 Function (For Dual Motor Config)
 *
 */
void StepperMotor::stepForwardMotor2(){
    if(dualMotor) {
        digitalWrite(_in5, HIGH);
        digitalWrite(_in6, LOW);
        digitalWrite(_in7, LOW);
        digitalWrite(_in8, LOW);
        delay(_delay);

        digitalWrite(_in5, LOW);
        digitalWrite(_in6, HIGH);
        digitalWrite(_in7, LOW);
        digitalWrite(_in8, LOW);
        delay(_delay);

        digitalWrite(_in5, LOW);
        digitalWrite(_in6, LOW);
        digitalWrite(_in7, HIGH);
        digitalWrite(_in8, LOW);
        delay(_delay);

        digitalWrite(_in5, LOW);
        digitalWrite(_in6, LOW);
        digitalWrite(_in7, LOW);
        digitalWrite(_in8, HIGH);
        delay(_delay);

        digitalWrite(_in5, LOW);
        digitalWrite(_in6, LOW);
        digitalWrite(_in7, LOW);
        digitalWrite(_in8, LOW);
        //delay(_delay);
    }else {
        SerialDebug.println("\n~> Function available only in Dual Motor Mode <~\n");
    }
} // end stepForwardMotor2 function

/**
 * @brief Step Backward Motor 2 Function (For Dual Motor Config)
 *
 */
void StepperMotor::stepBackwardMotor2(){
    if(dualMotor) {
        digitalWrite(_in5, LOW);
        digitalWrite(_in6, LOW);
        digitalWrite(_in7, LOW);
        digitalWrite(_in8, HIGH);
        delay(_delay);

        digitalWrite(_in5, LOW);
        digitalWrite(_in6, LOW);
        digitalWrite(_in7, HIGH);
        digitalWrite(_in8, LOW);
        delay(_delay);

        digitalWrite(_in5, LOW);
        digitalWrite(_in6, HIGH);
        digitalWrite(_in7, LOW);
        digitalWrite(_in8, LOW);
        delay(_delay);

        digitalWrite(_in5, HIGH);
        digitalWrite(_in6, LOW);
        digitalWrite(_in7, LOW);
        digitalWrite(_in8, LOW);
        delay(_delay);

        digitalWrite(_in5, LOW);
        digitalWrite(_in6, LOW);
        digitalWrite(_in7, LOW);
        digitalWrite(_in8, LOW);
    }else {
        SerialDebug.println("\n~> Function available only in Dual Motor Mode <~\n");
    }
} // end stepBackwardMotor2 function

/**
 * @brief Turn Left Function (For Dual Motor Config)
 *
 */
void StepperMotor::turnLeft() {
    if (dualMotor) {
        digitalWrite(_in1, HIGH);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
        digitalWrite(_in5, HIGH);
        digitalWrite(_in6, LOW);
        digitalWrite(_in7, LOW);
        digitalWrite(_in8, LOW);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, HIGH);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
        digitalWrite(_in5, LOW);
        digitalWrite(_in6, HIGH);
        digitalWrite(_in7, LOW);
        digitalWrite(_in8, LOW);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, HIGH);
        digitalWrite(_in4, LOW);
        digitalWrite(_in5, LOW);
        digitalWrite(_in6, LOW);
        digitalWrite(_in7, HIGH);
        digitalWrite(_in8, LOW);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, HIGH);
        digitalWrite(_in5, LOW);
        digitalWrite(_in6, LOW);
        digitalWrite(_in7, LOW);
        digitalWrite(_in8, HIGH);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
        digitalWrite(_in5, LOW);
        digitalWrite(_in6, LOW);
        digitalWrite(_in7, LOW);
        digitalWrite(_in8, LOW);
        //delay(_delay);
    }else {
        SerialDebug.println("\n~> Function available only in Dual Motor Mode <~\n");
    }
} // end turnLeft function

/**
 * @brief Turn Right Function (For Dual Motor Config)
 *
 */
void StepperMotor::turnRight() {
    if (dualMotor) {
        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, HIGH);
        digitalWrite(_in5, LOW);
        digitalWrite(_in6, LOW);
        digitalWrite(_in7, LOW);
        digitalWrite(_in8, HIGH);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, HIGH);
        digitalWrite(_in4, LOW);
        digitalWrite(_in5, LOW);
        digitalWrite(_in6, LOW);
        digitalWrite(_in7, HIGH);
        digitalWrite(_in8, LOW);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, HIGH);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
        digitalWrite(_in5, LOW);
        digitalWrite(_in6, HIGH);
        digitalWrite(_in7, LOW);
        digitalWrite(_in8, LOW);
        delay(_delay);

        digitalWrite(_in1, HIGH);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
        digitalWrite(_in5, HIGH);
        digitalWrite(_in6, LOW);
        digitalWrite(_in7, LOW);
        digitalWrite(_in8, LOW);
        delay(_delay);

        digitalWrite(_in1, LOW);
        digitalWrite(_in2, LOW);
        digitalWrite(_in3, LOW);
        digitalWrite(_in4, LOW);
        digitalWrite(_in5, LOW);
        digitalWrite(_in6, LOW);
        digitalWrite(_in7, LOW);
        digitalWrite(_in8, LOW);
        //delay(_delay);
    }else {
        SerialDebug.println("\n~> Function available only in Dual Motor Mode <~\n");
    }
} // end turnRight function

/**
 * @brief Step Degrees Function
 *
 * @param degrees
 */
void StepperMotor::stepDegrees(float degrees) {
    int step = round(turn360 / 360 * degrees);

    #ifdef DebugMode
        SerialDebug.println("~> " + String(step) + " steps to a " + String(degrees) + " degrees step\n~> " + String(turn360) + " steps to 360 degrees");
        SerialDebug.println("\nStep calc:\n~> (" + String(turn360) + " / 360) * " + String(degrees) + " = " + String(step));
    #endif

    while(step != 0){
        if(step > 0){
            stepForward();
            step --;
        }else {
            stepBackward();
            step ++;
        }
    }
} // end stepDegrees function

/**
 * @brief Step Degrees Motor 1 Function (For Dual Motor Config)
 *
 * @param degrees
 */
void StepperMotor::stepDegreesMotor1(float degrees) {
    if (dualMotor) {
        int step = round(turn360 / 360 * degrees);

        #ifdef DebugMode
            SerialDebug.println("~> " + String(step) + " steps to a " + String(degrees) + " degrees step\n~> " + String(turn360) + " steps to 360 degrees");
            SerialDebug.println("\nStep calc:\n~> (" + String(turn360) + " / 360) * " + String(degrees) + " = " + String(step));
        #endif

        while(step != 0){
            if(step > 0){
                stepForwardMotor1();
                step --;
            }else {
                stepBackwardMotor1();
                step ++;
            }
        }
    }else {
        SerialDebug.println("\n~> Function available only in Dual Motor Mode <~\n");
    }
} // end stepDegreesMotor1 function

/**
 * @brief Step Degrees Motor 2 (For Dual Motor Config)
 *
 * @param degrees
 */
void StepperMotor::stepDegreesMotor2(float degrees) {
    if (dualMotor) {
        int step = round(turn360 / 360 * degrees);

        #ifdef DebugMode
            SerialDebug.println("~> " + String(step) + " steps to a " + String(degrees) + " degrees step\n~> " + String(turn360) + " steps to 360 degrees");
            SerialDebug.println("\nStep calc:\n~> (360 / " + String(turn360) + ") * " + String(degrees) + " = " + String(step));
        #endif

        while(step != 0){
            if(step > 0){
                stepForwardMotor2();
                step --;
            }else {
                stepBackwardMotor2();
                step ++;
            }
        }
    }else {
        SerialDebug.println("\n~> Function available only in Dual Motor Mode <~\n");
    }
} // end stepDegreesMotor2 function

/**
 * @brief Turn Wheel Degrees Function (For Dual Motor Config)
 *
 * @param degrees
 */
void StepperMotor::turnWheelDegrees(float degrees){
    if (dualMotor) {
        int step = round(turn360 / 360 * degrees);

        #ifdef DebugMode
            SerialDebug.println("~> " + String(step) + " steps to a " + String(degrees) + " degrees step\n~> " + String(turn360) + " steps to 360 degrees");
            SerialDebug.println("\nStep calc:\n~> (360 / " + String(turn360) + ") * " + String(degrees) + " = " + String(step));
            SerialDebug.println("\n~~> Starting steps");
        #endif

        while(step != 0){
            if(step > 0){
                turnLeft();
                step --;
            }else {
                turnRight();
                step ++;
            }
        }

        #ifdef DebugMode
            SerialDebug.println("~~> Done");
        #endif

    }else {
        SerialDebug.println("\n~> Function available only in Dual Motor Mode <~\n");
    }
} // end turnWheelDegrees function

/**
 * @brief Forward Distance
 *
 * @param distance
 */
void StepperMotor::forwardDistance(float distance) {
    float perimeter = wheelDiameter * pi;
    float degrees = 360 / (perimeter / distance);

    #ifdef DebugMode
        SerialDebug.println("~> Perimeter: " + String(perimeter) + " cm\n~> Angle to step: " + String(degrees) + "\n");
    #endif

    stepDegrees(degrees);
} // end forwardDistance function

/**
 * @brief Turn degrees Function
 *
 * @param degrees
 */
void StepperMotor::turnDegrees(float degrees) {
    float perimeter = distanceBtwWheels * pi;
    float wheelPerimeter = wheelDiameter * pi;
    float distanceToTurn = perimeter / 360 * degrees;
    float turnDegrees = 360 / (wheelPerimeter / distanceToTurn);

    #ifdef DebugMode
        SerialDebug.println("~> Perimeter = " + String(distanceBtwWheels) + " * " + String(pi) + " = " + String(perimeter) + " Distance to Turn: " + String(distanceToTurn));
        SerialDebug.println("~> Turn Degrees = " + String(perimeter) + " / 360 * " + String(degrees) + " = " + String(turnDegrees));
    #endif

    turnWheelDegrees(turnDegrees);
} // end turnDegrees function

/**
 * @brief Forward default Function
 */
void StepperMotor::forwardDefault() {
    forwardDistance(getSqrDistance());
} // end forwardDefault function

/**
 * @brief Backward default Function
 */
void StepperMotor::backwardDefault() {
    forwardDistance(-getSqrDistance());
} // end backwardDefault function

/**
 * @brief Turn right default Function
 */
void StepperMotor::turnRightDefault() {
    turnDegrees(90);
} // end turnRightDefault  function

/**
 * @brief Turn left default Function
 */
void StepperMotor::turnLeftDefault() {
    turnDegrees(-90);
} // end turnLeftDefault function
