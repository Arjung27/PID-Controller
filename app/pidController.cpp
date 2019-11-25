/**
 * @file pidController.cpp
 * @brief This file containts definitions for functions
 *        declared in header file.    
 * @author     : Arjun Gupta
 * @created on : Sep 27, 2019
 * @copyright  : This code is written for ENPM808X. Please
 *               cite if code is used.
 */

#include "../include/pidController.hpp"
#include "../include/generalPidController.hpp"

pidController::pidController() {
    Kp = 0;
    Ki = 0;
    Kd = 0;
    controlError = 0;
    cumulativeError = 0;
    threshold = 0;
}

vector<float> pidController::getGainValues() {
    vector<float> gains = {Kp, Ki, Kd};
    return gains;
}

float pidController::computePidError(float setPointVel,
                                    float inputVel,
                                    float prevError) {
    auto currentError = setPointVel - inputVel;
    cumulativeError+=currentError;
    controlError = Kp*currentError + Kd*(currentError - prevError)
     + Ki*(cumulativeError);
    if (controlError > threshold)
        controlError = threshold;
    else
        std::cout << "Control error is:" << controlError;
    cout << "New velocity is: " << controlError + inputVel << endl;
    return controlError;
}
pidController::~pidController() {
}
