#include "robot-config.h"
#include "autons/auton.h"
#include "main.h"
#include "autons/auton_functions.h"
#include "vex.h"

using namespace vex;
using namespace auton;

void default_constants(){
  // Each constant set is in the form of (maxVoltage, kP, kI, kD, startI).
  chassis.set_drive_constants(10, 1.5, 0, 10, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);

  // Each exit condition set is in the form (settle_error, settle_time, timeout).
  chassis.set_drive_exit_conditions(2.5, 180, 1500);
  chassis.set_turn_exit_conditions(2, 180, 500);
  chassis.set_swing_exit_conditions(2, 180, 500);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 12;
  chassis.drive_settle_error = 12;
  chassis.turn_settle_error = 11;
  chassis.turn_max_voltage = 12;
}

void drive_test(){
  chassis.drive_distance(6);
  chassis.drive_distance(12);
  chassis.drive_distance(18);
  chassis.drive_distance(-36);
}

void blue_left(){
    // robot 4 POV blue left side no wall
    
    driveAndTurn(-1.85, 0); //can delete later

    turnToAngle(34);
    driveAndTurn(-0.586, 30);
    clamp.set(true);
    wait(100, msec);

    inta1.spin(reverse, 100, pct);
    inta2.spin(reverse, 100, pct);
    turnToAngle(-20);
    driveAndTurn(0.70, -20, 60, 60);
    wait(750, msec);
    clamp.set(false);
    // wait(150, msec);
    driveAndTurn(0.15, 0, 0, 0, 500);
    turnToAngle(87);
    driveAndTurn(-0.644, 87, 80, 80); //0.9
    clamp.set(true);
    wait(200, msec);

    turnToAngle(-59);
    doinker.set(true);
    driveAndTurn(1.17, -59);
    turnToAngle(-95);
    driveAndTurn(0.5, -88);

    turnToAngle(-135);
    // driveAndTurn(0.75, -135);

     /////////////////////////////////////

    //robot 4 POV blue left with wallstake
        // turnToAngle(-15);
        // driveAndTurn(0.28, -15);
        // driveAndTurn(-1, -15);
        // turnToAngle(25);
        // driveAndTurn(-0.5, 25);
        // clamp.set(true);
        // inta1.spin(reverse, 100, pct);
        // inta2.spin(reverse, 100, pct);
        // turnToAngle(125);
        // driveAndTurn(1.2, 125);
        // turnToAngle(-90);
        // clamp.set(false);
        // wait(400, msec);
        // turnToAngle(33);       
        // driveAndTurn(-0.8, 25);
        // clamp.set(true);
        // turnToAngle(-30);
        // // inta1.spin(reverse, 100, pct);
        // // inta2.spin(reverse, 100, pct);
        // driveAndTurn(2.6, -18);
        // turnToAngle(45);
        // driveAndTurn(-0.4, 45);

}

/////////////////////////////////////

void red_right(){
//     //robot 4 POV red left side no wall 
//     //chasuturn(-85, -100, -35, 900); //the ms can be smaller 
    
    driveAndTurn(-1.75, 0); 

    turnToAngle(-28);
    driveAndTurn(-0.65, -23, 60, 60);
    clamp.set(true);
    wait(60, msec);


    inta1.spin(reverse, 100, pct);
    inta2.spin(reverse, 100, pct);
    turnToAngle(30);
    driveAndTurn(0.76, 20, 60, 60);
    wait(700, msec);
    clamp.set(false);
    driveAndTurn(0.9, 20);

    turnToAngle(-35);
    driveAndTurn(-0.495, -30, 60, 60);
    clamp.set(true);
    wait(200, msec);

    turnToAngle(35);
    doinker.set(true);
    driveAndTurn(1.1, 30);
    turnToAngle(100);
    turnToAngle(130);
    driveAndTurn(0.8, 130);
    turnToAngle(160);

    ///////////////////////////////////////

//     //robot 4 POV red right with wallstake

        // intakeLift.set(true);
        // wait(200, msec);
        // driveAndTurn(0.35, 0);
        // intakeLift.set(false);
        // wait(250, msec);
        // driveAndTurn(-0.5, -30);
        // turnToAngle(-20);

        // driveAndTurn(-1, -20);
        // clamp.set(true);
        // wait(100, msec);
        // inta1.spin(reverse, 100, pct);
        // inta2.spin(reverse, 100, pct);
        // turnToAngle(-150);
        // driveAndTurn(1.1, -150);
        // // wait(900, msec);
        // // clamp.set(false);
        // // driveAndTurn(0.6, -150);
        // turnToAngle(-70);
        // doinker.set(true);
        // driveAndTurn(1.35, -97);
        // turnToAngle(-150);
        // doinker.set(false);
        // // turnToAngle(-55);
        // // driveAndTurn(0.4, -55);
        // // wait(200, msec);
        // // driveAndTurn(-1.7, -70);
        
        // // inta1.spin(reverse, 100, pct);
        // // inta2.spin(reverse, 100, pct);
        // // turnToAngle(-125);
        // // driveAndTurn(1.2, -125);
        // // turnToAngle(90);
        // // clamp.set(false);
        // // wait(400, msec);
        // // turnToAngle(-33);       
        // // driveAndTurn(-0.8, -25);
        // // clamp.set(true);
        // // turnToAngle(30);
        // // // inta1.spin(reverse, 100, pct);
        // // // inta2.spin(reverse, 100, pct);
        // // driveAndTurn(2.6, 18);
        // // turnToAngle(-45);
        // // driveAndTurn(-0.4, -45);
}

/////////////////////////////////////

void blue_right(){
    //robot 4 POV blue right side no wall    
    
    driveAndTurn(-1.3, 0);
    clamp.set(true);
    inta1.spin(reverse, 100, pct);
    inta2.spin(reverse, 100, pct);
    wait(700, msec);
    
    turnToAngle(-69);
    driveAndTurn(0.95, -69, 45, 45);
    wait(200, msec);

    turnToAngle(-160);
    driveAndTurn(0.69, -160, 20, 20);
    wait(100, msec);
    driveAndTurn(-0.5, -140, 20, 20);  
    turnToAngle(-120);
    driveAndTurn(0.58, -120, 80, 80);
    driveAndTurn(-1.5, -120, 50, 50);
    turnToAngle(140);
    driveAndTurn(1.1, 140);

    // clamp.set(false);
    // wait(1000, msec);
    // clamp.set(true);
    // wait(500, msec);
    // turnToAngle(90, 50);
    // driveAndTurn(3, 90);

// //  /////////////////////////////////////

// //     //robot 4 POV blue right with wallstake
// //     turnToAngle(0);
// //     driveAndTurn(0, 0);
// //     //implement put down the ring
// //     driveAndTurn(-0, 0);
// //     turnToAngle(-0);
// //     driveAndTurn(0, 0);
// //     driveAndTurn(-0, 0);
// //     turnToAngle(0);
// //     driveAndTurn(-0, 0);
// //     clamp.set(true);
// //     turnToAngle(0);
// //     driveAndTurn(0, 0);
// //     driveAndTurn(-0, 0);
// //     turnToAngle(-0);
// //     driveAndTurn(0, 0);
// //     driveAndTurn(-0, 0);
// //     turnToAngle(-0);
// //     driveAndTurn(0, 0);
// //     turnToAngle(-0);
// //     driveAndTurn(-0, 0);
}

/////////////////////////////////////

void red_left(){
//     // robot 4 POV red right side no wall

    driveAndTurn(-1.26, 0, 78, 78);
    clamp.set(true);
    inta1.spin(reverse, 100, pct);
    inta2.spin(reverse, 100, pct);
    wait(1000, msec);
    
    turnToAngle(68);
    driveAndTurn(0.98, 68, 30, 30); //1
    wait(200, msec);

    turnToAngle(156);
    driveAndTurn(0.76, 154, 20, 20);
    wait(150, msec);

    driveAndTurn(-0.5, 164, 45, 45); //change value
    turnToAngle(132); //change value
    driveAndTurn(0.53, 132, 45, 45); //change value
    wait(100, msec);
    driveAndTurn(-1.5, 115, 50, 50);
    turnToAngle(-145);
    driveAndTurn(1.3, -145);
//  /////////////////////////////////////

//     //robot 4 POV red left with wallstake
//     turnToAngle(0);
//     driveAndTurn(0, 0);
//     //implement put down the ring
//     driveAndTurn(-0, 0);
//     turnToAngle(-0);
//     driveAndTurn(0, 0);
//     driveAndTurn(-0, 0);
//     turnToAngle(0);
//     driveAndTurn(-0, 0);
//     clamp.set(true);
//     turnToAngle(0);
//     driveAndTurn(0, 0);
//     driveAndTurn(-0, 0);
//     turnToAngle(-0);
//     driveAndTurn(0, 0);
//     driveAndTurn(-0, 0);
//     turnToAngle(-0);
//     driveAndTurn(0, 0);
//     turnToAngle(-0);
//     driveAndTurn(-0, 0);
}




/////////////////////////////////////






// void other(){
//     //75% 5 pts POV red

//     // setHeading(270);

//     // driveAndTurn(-1.1, 0);
//     // clip.set(true);

//     // inta1.spin(reverse, 80, pct);
//     // inta2.spin(reverse, 80, pct);
//     // turnToAngle(-106);
//     // driveAndTurn(1, -90);
//     // turnToAngle(60);
//     // intakeLift.set(true);
//     // inta1.spin(reverse, 80, pct);
//     // inta2.spin(reverse, 80, pct);

//     // driveAndTurn(2.1, 63, 80, 80);
//     // // driveAndTurn(1.7, 63, 80, 80);
//     // // driveAndTurn(0.4, 63);
//     // intakeLift.set(false);
//     // inta1.spin(reverse, 80, pct);
//     // inta2.spin(reverse, 80, pct);
//     // turnToAngle(150);

//     // driveAndTurn(0.7, 150);
//     // intakeLift.set(true);
//     // clip.set(false);
//     // inta.stop(brake);

//     ///////////////////////////////////////

//     //100% 7pts POV red 

//     // setHeading(290);
//     // driveAndTurn(-2.28, 0);
//     // clip.set(true);
//     // inta1.spin(reverse, 80, pct);
//     // inta2.spin(reverse, 80, pct);
//     // turnToAngle(-40);
//     // driveAndTurn(0.46, 0);
//     // clip.set(false);

//     // driveAndTurn(1.7, 63, 80, 80);
//     // driveAndTurn(0.4, 63);
//     // intakeLift.set(false);
//     // turnToAngle(150);
//     // intakeLift.set(true);
//     // turnToAngle(0); //change value

//     // inta.stop(brake);
//     // driveAndTurn(0.9, 128);
//     // clip.set(true);
//     // inta1.spin(reverse, 80, pct);
//     // inta2.spin(reverse, 80, pct);

//     // driveAndTurn(0.7, 0); //change value

//     ///////////////////////////////////////

//     //75% 5 pts POV blue

//     // setHeading(90);

//     // driveAndTurn(-1.1, 0);
//     // clip.set(true);

//     // inta1.spin(reverse, 80, pct);
//     // inta2.spin(reverse, 80, pct);
//     // turnToAngle(106);
//     // driveAndTurn(1, 90);
//     // turnToAngle(-60);
//     // intakeLift.set(true);
//     // inta1.spin(reverse, 80, pct);
//     // inta2.spin(reverse, 80, pct);

//     // driveAndTurn(2.1, -63, 80, 80);
//     // intakeLift.set(false);
//     // inta1.spin(reverse, 80, pct);
//     // inta2.spin(reverse, 80, pct);
//     // turnToAngle(-150);

//     // driveAndTurn(0.35, -150);
//     // intakeLift.set(true);
//     // clip.set(false);
//     // inta.stop(brake);

//     ///////////////////////////////////////

//     // turnToAngle(30);
//     // driveAndTurn(-0.43, 30);
//     // clip.set(true);
//     // turnToAngle(-20);
//     // inta1.spin(reverse, 100, pct);
//     // inta2.spin(reverse, 100, pct);
//     // driveAndTurn(0.7, 0);
//     // clip.set(true);

//     // driveAndTurn(0.2, 0);
//     // turnToAngle(80);
//     // driveAndTurn(1, 0);

//     // driveAndTurn(0.35,270);
//     // driveAndTurn(2,340);

//     // pner.spin(fwd,100,pct);
//     // wait(1000, msec);
//     // pner.stop(hold);

//     // inta1.spin(fwd,100,pct);
//     // inta2.spin(fwd,100,pct);
//     // driveAndTurn(2.3, 28,100,50);
//     // turnToAngle(0);
//     // driveAndTurn(-3, 43,55,100);
//     // turnToAngle(135);

//     // clip.set(true);
//     // turnToAngle(-270);
//     // turnToAngle(135);
//     // clip.set(false);
//     // driveAndTurn(1.3, 90, 100, 87);
//     // inta.stop(brake);
//     // driveAndTurn(0.8,90);
//     // inta1.spin(reverse,100,pct);
//     // inta2.spin(reverse,100,pct);

//     ///////////////////////////////////////

//     //75% 6pts POV red 
//     //write in far_qua later

//     // setHeading(270);

//     // driveAndTurn(-1.1, 0);
//     // clip.set(true);

//     // inta1.spin(reverse, 80, pct);
//     // inta2.spin(reverse, 80, pct);
//     // turnToAngle(148);
//     // driveAndTurn(1, 150);
//     // turnToAngle(88, 100);
//     // driveAndTurn(1, 90, 100, 100);

//     // inta1.spin(reverse, 80, pct);
//     // inta2.spin(reverse, 80, pct);
//     // driveAndTurn(-1.2, 110);

//     // turnToAngle(55);
//     // inta1.spin(reverse, 80, pct);
//     // inta2.spin(reverse, 80, pct);
//     // driveAndTurn(0.7, 55, 100, 100);

//     // turnToAngle(-135);
//     // clip.set(false);
//     // intakeLift.set(true);
//     // driveAndTurn(0.75, -130);
//     // inta.stop(brake);
// }
