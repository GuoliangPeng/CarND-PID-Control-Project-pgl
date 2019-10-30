#include <limits>
#include <iostream>
#include "PID.h"

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
    parameter.push_back(Kp_);
    parameter.push_back(Ki_);
    parameter.push_back(Kd_);

    this->p_error = 0.0;
    this->d_error = 0.0;
    this->i_error = 0.0;


}


void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
    if(step == 1){
        p_error = cte;
    }
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
    step++;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
    return -parameter[0] * p_error - parameter[1] * i_error - parameter[2] * d_error;
}
