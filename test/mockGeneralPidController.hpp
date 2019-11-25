/**
 * @file mockGeneralPidController.hpp
 * @brief  This file contains declarations for the
 *          mock test of PID controller class    
 * @author     : Arjun Gupta
 * @created on : November 24, 2019
 * @copyright  : This code is written for ENPM808X. Please
 *               cite if code is used.
 */

#ifndef TEST_MOCKGENERALPIDCONTROLLER_HPP_
#define TEST_MOCKGENERALPIDCONTROLLER_HPP_

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../include/generalPidController.hpp"

class mockGeneralPidController : public generalPidController {
 public:
  /**
   * @brief setGainValues mock, Initializes the mock.
   * @param kp kp proportional gain value
   * @param ki ki integral gain value
   * @param kd kd derivative gain value
   * @return bool
   */
  MOCK_METHOD3(setGainValues, bool(float kp, float ki, float kd));

  /**
   * @brief setThreshold mock, initializes the mock
   * @param float threshold set the cut-off threshold for PID
   * @return bool
   */
  MOCK_METHOD1(setThreshold, bool(float));

  /**
   * @brief compute PID mock, initializes the mock
   * 
   * @param setPointVel This is the reference velocity to be tracked by the 
   *                    controller.
   * @param inputVel  This is the input velocity to the controller.
   * @param prevError This is the error from the previous instant at which
   *                  PID controller error was calculated.
   */
  MOCK_METHOD3(computePidError, float(float setPointVel, float inputVel, \
                                     float prevError));
};

#endif  // TEST_MOCKGENERALPIDCONTROLLER_HPP_
