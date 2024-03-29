#ifndef PID_H
#define PID_H

#include <cmath>
#include <vector>

class PID {
private:
  int step;
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients, the order is P, I, D
  */
  std::vector<double> parameter;

  /*
  * Constructor
  */
  PID();

   /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   */
  void Init(double Kp_, double Ki_, double Kd_);

  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  void UpdateError(double cte);

  /**
   * Calculate the total PID error.
   * @output The total PID error
   */
  double TotalError();
};

#endif  // PID_H