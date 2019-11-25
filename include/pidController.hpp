/**
 * @file pidController.hpp
 * @brief This file contains declarations for the
 *        PID controller class    
 * @author     : Arjun Gupta
 * @created on : November 24, 2019
 * @copyright  : This code is written for ENPM808X. Please
 *               cite if code is used.
 */
#ifndef INCLUDE_PIDCONTROLLER_HPP_
#define INCLUDE_PIDCONTROLLER_HPP_

#include <iostream>
#include <vector>
#include <string>
#include "generalPidController.hpp"

using std::cout;
using std::vector;
using std::string;
using std::endl;
using std::flush;

class pidController : public generalPidController {
 public:
    /**
    * @brief default constructor
    */
    pidController();
    /**
     * @brief This function returns the gain values set by the user.
     * @return A float vector that contains the gain values
     * in the order Kp,Ki and Kd in the vector.
     */
    vector<float> getGainValues();
    /**
     * @brief This function implements the error formula for the PID controller
     * for a given set point and the input. This is calculated at a particular 
     * time instant. If the control error is beyond a certain limit then the 
     * controller sets the control error to the value set by the setThreshold() 
     * function.
     * @param setPointVel This is the reference velocity to be tracked by the
     *                    controller.
     * @param inputVel  This is the input velocity to the controller.
     * @param prevError This is the error from the previous instant at which 
     *                  PID controller error was calculated. 
     */
    float computePidError(float setPointVel, float inputVel, float prevError);
    /**
     * @brief Default Destructor
     */
    ~pidController();
};

#endif  // INCLUDE_PIDCONTROLLER_HPP_
