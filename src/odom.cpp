#include "vex.h"

float X_position=0;
float Y_position=0;
float orientation_deg=0;

float ForwardTracker_center_distance = -0.197* 0.3937008;
float SidewayTracker_center_distance = 1.772 * 0.3937008;
// void set_physical_distances(float ForwardTracker_center_distance, float SidewayTracker_center_distance){
//   ForwardTracker_center_distance = -0.197;
//   SidewayTracker_center_distance = 1.772;
// }


float to_rad(float angle_deg){
  return(angle_deg/(180.0/M_PI));
}

double prev_ForwardTracker_position;
double prev_SideWayTracker_position;
double prev_X_position; 
double prev_Y_position;
double prev_orientation_deg;
// double ForwardTracker_position;
// double SidewayTracker_position;

void set_position(float X_position_, float Y_position_, float orientation_deg, float ForwardTracker_position_, float SidewayTracker_position_){
  // ForwardTracker_position = ForwardTracker_position_;
  // SidewayTracker_position = SidewayTracker_position_;
  X_position = X_position_;
  Y_position = Y_position_;
  orientation_deg = orientation_deg;
}


float global_polar_angle;
void update_position(float ForwardTracker_position, float SidewayTracker_position, float orientation_deg){
  // this-> always refers to the old version of the variable, so subtracting this->x from x gives delta x.
  float Forward_delta = ForwardTracker_position - prev_ForwardTracker_position;
  float Sideway_delta = SidewayTracker_position - prev_SideWayTracker_position;
  prev_ForwardTracker_position=ForwardTracker_position;
  prev_SideWayTracker_position=SidewayTracker_position;
  float orientation_rad = to_rad(orientation_deg);
  float prev_orientation_rad = to_rad(prev_orientation_deg);
  float orientation_delta_rad = orientation_rad-prev_orientation_rad;
  float prev_orientation_deg=orientation_deg;

  float local_X_position;
  float local_Y_position;

  if (orientation_delta_rad == 0) {
    local_X_position = Sideway_delta;
    local_Y_position = Forward_delta;
  } else {
    local_X_position = (2*sin(orientation_delta_rad/2))*((Sideway_delta/orientation_delta_rad)+SidewayTracker_center_distance); 
    local_Y_position = (2*sin(orientation_delta_rad/2))*((Forward_delta/orientation_delta_rad)+ForwardTracker_center_distance);
  }

  float local_polar_angle;
  float local_polar_length;

  if (local_X_position == 0 && local_Y_position == 0){
    local_polar_angle = 0;
    local_polar_length = 0;
  } else {
    local_polar_angle = atan2(local_Y_position, local_X_position); 
    local_polar_length = sqrt(pow(local_X_position, 2) + pow(local_Y_position, 2)); 
  }

  float global_polar_angle = local_polar_angle - prev_orientation_rad - (orientation_delta_rad/2);

  float X_position_delta = local_polar_length*cos(global_polar_angle); 
  float Y_position_delta = local_polar_length*sin(global_polar_angle);

  X_position+=X_position_delta;
  Y_position+=Y_position_delta;
  
}