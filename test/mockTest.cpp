/**
 * @file mockTest.cpp
 * @brief This file containts definitions for functions
 *        declared in header file.    
 * @author     : Arjun Gupta
 * @created on : November 24, 2019
 * @copyright  : This code is written for ENPM808X. Please
 *               cite if code is used.
 */
#include <iostream>
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "mockGeneralPidController.hpp"
#include "../include/generalPidController.hpp"
#include "../include/pidController.hpp"

using ::testing::AtLeast;
using ::testing::Return;
using ::testing::_;

TEST(GeneralPidControllerTest, setGainValuesTest) {
    mockGeneralPidController gpid;
    pidController pid;
    EXPECT_CALL(gpid, setGainValues(_, _, _)).Times(1).WillOnce(Return(true));
    gpid.setGainValues(1.0, 2.0, 3.0);
    EXPECT_EQ(true, pid.setGainValues(1.0, 2.0, 3.0));
}

TEST(GeneralPidControllerTest, setThresholdTest) {
    mockGeneralPidController gpid;
    pidController pid;
    EXPECT_CALL(gpid, setThreshold(_)).Times(1).WillOnce(Return(true));
    gpid.setThreshold(10);
    EXPECT_EQ(true, pid.setThreshold(10));
}

TEST(GeneralPidControllerTest, computePidErrorTest) {
    mockGeneralPidController gpid;
    pidController pid;
    EXPECT_CALL(gpid, computePidError(_, _, _)).Times(1).WillOnce(Return(true));
    gpid.computePidError(9, 4, 2);
    pid.setGainValues(1, 2, 4);
    pid.setThreshold(10.0);
    EXPECT_EQ(10, pid.computePidError(9, 4, 2));
}


