/**
 * @file generalPidController.hpp
 * @brief  This file contains declarations for the
 *          general PID controller class    
 * @author     : Arjun Gupta
 * @created on : November 24, 2019
 * @copyright  : This code is written for ENPM808X. Please
 *               cite if code is used.
 */
#ifndef INCLUDE_GENERALPIDCONTROLLER_HPP_
#define INCLUDE_GENERALPIDCONTROLLER_HPP_

#include <iostream>

class generalPidController {
 protected:
    /** Declares the variables for proportional gain, integral gain, 
     * differential gain and the threshold limit for saturation, in 
     * the same order.
      */
    float Kp, Ki, Kd, threshold;
    // Cumulative error for the controller
    double cumulativeError;
    // control error for the controller
    float controlError;

 public:
    /**
    * @brief default constructor
    */
    generalPidController();
    /**
     * @brief Default Destructor
     */
    virtual ~generalPidController();
    /**
     * @brief This function sets the required gain values for 
     * the PID controller.
     * @param _kp - This is the proportional controller gain to be set.
     * @param _ki - This is the integral controller gain to be set. 
     * @param _kd - This is the differential controller gain to be set. 
     */
    virtual bool setGainValues(float _kp, float _ki, float _kd);
    /**
     * @brief This function sets the threshold value for the control error 
     * beyond which the PID controller outputs the saturation value.
     * @param _threshold This is a float type threshold value for the 
     * controller. 
     */
    virtual bool setThreshold(float _threshold);
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
    virtual float computePidError(float setPointVel, \
                  float inputVel, float prevError) = 0;
};

#endif  // INCLUDE_GENERALPIDCONTROLLER_HPP_
