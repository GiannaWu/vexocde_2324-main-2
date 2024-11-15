#include "vex.h"

PID::PID(float error, float kp, float ki, float kd, float starti) :
  error(error),
  kp(kp),
  ki(ki),
  kd(kd),
  starti(starti)
{};

PID::PID(float error, float kp, float ki, float kd, float starti, float settle_error, float settle_time, float timeout) :
  error(error),
  kp(kp),
  ki(ki),
  kd(kd),
  starti(starti),
  settle_error(settle_error),
  settle_time(settle_time),
  timeout(timeout)
{};

float PID::compute(float error){
  // Update accumulated error if the error is within a certain range
  if (fabs(error) < starti){ // StartI is used to prevent integral windup.
    accumulated_error+=error;
  }
  // Reset accumulated error if the error changes sign 
  if ((error>0 && previous_error<0)||(error<0 && previous_error>0)){ 
    accumulated_error = 0; 
  } // This if statement checks if the error has crossed 0, and if it has, it eliminates the integral term.

  output = kp*error + ki*accumulated_error + kd*(error-previous_error);

  previous_error=error;

  if(fabs(error)<settle_error){
    time_spent_settled+=10;
  } else {
    time_spent_settled = 0;
  }

  time_spent_running+=10;

  return output;
}

// Function to check if the system controlled by the PID has settled 
bool PID::is_settled(){
  // Check for timeout or if the system has settled for a certain duration
  if (time_spent_running>timeout && timeout != 0){
    return(true);
  } // If timeout does equal 0, the move will never actually time out. Setting timeout to 0 is the 
    // equivalent of setting it to infinity.
  if (time_spent_settled>settle_time){
    return(true);
  }
  return(false);
}