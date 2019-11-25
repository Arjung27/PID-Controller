/**
 * @file generalPidController.cpp
 * @brief This file containts definitions for functions
 *        declared in header file.    
 * @author     : Arjun Gupta
 * @created on : November 24, 2019
 * @copyright  : This code is written for ENPM808X. Please
 *               cite if code is used.
 */

#include "../include/generalPidController.hpp"

generalPidController::generalPidController() {
    this->Kp = 0;
    this->Ki = 0;
    this->Kd = 0;
    this->controlError = 0;
    this->cumulativeError = 0;
    this->threshold = 0;
}
bool generalPidController::setGainValues(float _kp, float _ki, float _kd) {
    this->Kp = _kp;
    this->Ki = _ki;
    this->Kd = _kd;
    return true;
}

bool generalPidController::setThreshold(float _threshold) {
    this->threshold = _threshold;
    return true;
}
generalPidController::~generalPidController() {
}
