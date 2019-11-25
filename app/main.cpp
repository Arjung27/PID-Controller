/**@file main.cpp
 * @brief This file containts definitions for functions
 * declared in header file.    
 * @author     : Arjun Gupta
 * @created on : Sep 27, 2019
 * @copyright  : This code is written for ENPM808X. Please
 *               cite if code is used.
 */

#include "../include/pidController.hpp"
#include "../include/generalPidController.hpp"

int main() {
    pidController pid;
    pid.setGainValues(1, 2, 4);
    pid.setThreshold(10.0);
    vector<float> pidVector = pid.getGainValues();
    vector<string> gainNames = {"Kp", "Ki", "Kd"};
    int i = 0;
    cout << "Value of your gain variables is: " << endl;
    for (auto &values : pidVector) {
        cout << gainNames[i] << ": " << values << endl;
        ++i;
    }
    std::cout << "The control error is:" << pid.computePidError(9, 4, 2)
              << std::endl;
    // pid.printNewVelocity(pid.getControlError() , 4);
    return 0;
}
