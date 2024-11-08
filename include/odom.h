/**
 * General-use odometry class with X_position, Y_position, and
 * orientation_deg being the relevant outputs. This works for one
 * and two-tracker systems, and needs a gyro to get input angle.
 */
    extern float X_position;
    extern float Y_position;
    extern float orientation_deg;

//   float ForwardTracker_center_distance;
//   float SidewaysTracker_center_distance;
  float ForwardTracker_position;
  float SideWayTracker_position;

//   void set_position(float X_position, float Y_position, float orientation_deg, float ForwardTracker_position, float SidewaysTracker_position);
//   void update_position(float ForwardTracker_position, float SidewaysTracker_position, float orientation_deg);
//   void set_physical_distances(float ForwardTracker_center_distance, float SidewaysTracker_center_distance);
  void set_physical_distances(float ForwardTracker_center_distance, float SidewayTracker_center_distance);
  void set_position(float X_position_, float Y_position_, float orientation_deg, float ForwardTracker_position, float SidewayTracker_position);
  void update_position(float ForwardTracker_position, float SidewayTracker_position, float orientation_deg);
