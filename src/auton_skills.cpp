#include "robot-config.h"
#include "autons/auton.h"
#include "main.h"
#include "autons/auton_functions.h"
using namespace vex;
using namespace auton;

void auton_skills(){
    
    //implement lift the arm
    driveAndTurn(0, 0);
    intamo.spin(fwd, 100, pct);
    //implement lower the arm
    driveAndTurn(-0, 0);

    turnToAngle(0);
    driveAndTurn(-0, 0);
    clamp.set(true);
    turnToAngle(0);
    
    intamo.spin(reverse, 100, pct);
    driveAndTurn(0, 0);
    turnToAngle(0);
    driveAndTurn(0, 0);
    turnToAngle(0);
    driveAndTurn(0, 0);
    turnToAngle(-0);
    driveAndTurn(0, 0);
    turnToAngle(0);
    driveAndTurn(0, 0);
    turnToAngle(0);
    driveAndTurn(-0, 0);
    clamp.set(false);

    driveAndTurn(0, 0);
    turnToAngle(180);
    driveAndTurn(-0, 0);
    clamp.set(true);

    turnToAngle(-0);
    driveAndTurn(0, 0);
    turnToAngle(-0);
    driveAndTurn(0, 0);
    turnToAngle(-0);
    driveAndTurn(0, 0);
    turnToAngle(0);
    driveAndTurn(0, 0);
    turnToAngle(0);
    driveAndTurn(0, 0);
    turnToAngle(0, 0);
    driveAndTurn(-0, 0);
    clamp.set(false);

    turnToAngle(-0);
    driveAndTurn(0, 0);
    intamo.stop(brake);

    turnToAngle(-0);
    driveAndTurn(-0, 0);
    clamp.set(true);
    turnToAngle(-0);

    driveAndTurn(0, 0);
    turnToAngle(-0);
    driveAndTurn(0, 0);
    turnToAngle(-0);
    driveAndTurn(0, 0);
    turnToAngle(90);
    driveAndTurn(0, 90);
    turnToAngle(0);
    driveAndTurn(0, 0);
    turnToAngle(0);
    driveAndTurn(0, 0);
    //implement go to the corner and remove the blue ring 
    clamp.set(false);

    //if enough time, go score another wall stake ring
    
    //hang
    turnToAngle(0);
    driveAndTurn(0, 0);
    //implement hang
    //finish
}
