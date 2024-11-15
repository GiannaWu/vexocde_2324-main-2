#include "vex.h"
#include "botcontrol.h"
#include "basic_control.h"
#include "robot-config.h"
#include "main.h"
#include "autons/auton.h"
#include "autons/auton_functions.h"
using namespace vex;
using namespace auton;
competition Competition;

int originX = 0;
int width = 240;

bool intawing = 0;

// int conlef = con.Axis1.position()+con.Axis3.position();

int endX = originX + width;

int autonoption = 0;

bool isAutonRunning = false;

// float deadband(float input, float width){
//   if (fabs(input)<width){
//     return(0);
//   }
//   return(input);
// }
Drive chassis(

//Pick your drive setup from the list below:
//ZERO_TRACKER_NO_ODOM
//ZERO_TRACKER_ODOM
//TANK_ONE_FORWARD_ENCODER
//TANK_ONE_FORWARD_ROTATION
//TANK_ONE_SIDEWAYS_ENCODER
//TANK_ONE_SIDEWAYS_ROTATION
//TANK_TWO_ENCODER
//TANK_TWO_ROTATION
//HOLONOMIC_TWO_ENCODER
//HOLONOMIC_TWO_ROTATION
//
//Write it here:
TANK_TWO_ROTATION, 

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(l1, l2, l3),

//Right Motors:
motor_group(r1, r2, r3),

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT14,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
3.25,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
0.75,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
PORT12,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2.0*0.333,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
-0.197,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
PORT11,

//Sideways tracker diameter (reverse to make the direction switch):
-2.0*0.333,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
1.772

);

void pre_auton(void) {
  vexcodeInit();
  bob.startCalibration();
  while(bob.isCalibrating()){
    wait(10, msec);
  }
  // heading_convert(bob.heading());
  while(1){
  if (Brain.Screen.pressing()){
    int X = Brain.Screen.xPosition();
    int Y = Brain.Screen.xPosition();
    if ((Y >= 120)){
      Brain.Screen.clearScreen();
      Brain.Screen.setFillColor(red);
      Brain.Screen.printAt(180,136, "Close Auton");
      autonoption = 1;

    } else if(Y <= 120){
      Brain.Screen.clearScreen();
      Brain.Screen.drawRectangle(0,0,480,272);
      Brain.Screen.setFillColor(red);
      Brain.Screen.printAt(190,136, "Far Auton");
      autonoption = 2;
    }
  }
    wait(20, msec);

  }
}


void autonomous(void) {
  isAutonRunning = true;
  // test();
  Brain.Screen.clearScreen();
  Brain.Screen.setFillColor(red);
  Brain.Screen.printAt(((480/2)-36), (240/2), "Auton Start!");
  // if(autonoption == 2){
  //   far();
  // } else if(autonoption == 1){

  // }
  // blue_left();
  red_left();
  // blue_right();
  // red_right();
  // drive_test();
}

void usercontrol(void) {
  isAutonRunning = false;
  driver();

}
int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
}
