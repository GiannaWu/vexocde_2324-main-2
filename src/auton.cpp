#include "robot-config.h"
#include "autons/auton.h"
#include "main.h"
#include "autons/auton_functions.h"
using namespace vex;
using namespace auton;

void close_qua(){

    //75% 5 pts POV red

    // setHeading(270);

    driveAndTurn(-1.1, 0);
    clip.set(true);

    inta.spin(reverse, 80, pct);
    turnToAngle(-106);
    driveAndTurn(1, -90);
    turnToAngle(60);
    intakeLift.set(true);
    inta.spin(reverse, 80, pct);

    driveAndTurn(2.1, 63, 80, 80);
    // driveAndTurn(1.7, 63, 80, 80);
    // driveAndTurn(0.4, 63);
    intakeLift.set(false);
    inta.spin(reverse, 80, pct);
    turnToAngle(150);

    driveAndTurn(0.7, 150);
    intakeLift.set(true);
    clip.set(false);
    inta.stop(brake);

    ///////////////////////////////////////

    //100% 7pts POV red 

    // setHeading(290);
    // driveAndTurn(-2.28, 0);
    // clip.set(true);
    // inta.spin(reverse, 80, pct);
    // turnToAngle(-40);
    // driveAndTurn(0.46, 0);
    // clip.set(false);

    // driveAndTurn(1.7, 63, 80, 80);
    // driveAndTurn(0.4, 63);
    // intakeLift.set(false);
    // turnToAngle(150);
    // intakeLift.set(true);
    // turnToAngle(0); //change value

    // inta.stop(brake);
    // driveAndTurn(0.9, 128);
    // clip.set(true);
    // inta.spin(reverse, 80, pct);

    // driveAndTurn(0.7, 0); //change value

    ///////////////////////////////////////

    //75% 5 pts POV blue

    setHeading(90);

    driveAndTurn(-1.1, 0);
    clip.set(true);

    inta.spin(reverse, 80, pct);
    turnToAngle(106);
    driveAndTurn(1, 90);
    turnToAngle(-60);
    intakeLift.set(true);
    inta.spin(reverse, 80, pct);

    driveAndTurn(2.1, -63, 80, 80);
    intakeLift.set(false);
    inta.spin(reverse, 80, pct);
    turnToAngle(-150);

    driveAndTurn(0.35, -150);
    intakeLift.set(true);
    clip.set(false);
    inta.stop(brake);

    ///////////////////////////////////////

    // turnToAngle(30);
    // driveAndTurn(-0.43, 30);
    // clip.set(true);
    // turnToAngle(-20);
    // inta.spin(reverse, 100, pct);
    // driveAndTurn(0.7, 0);
    // clip.set(true);

    // driveAndTurn(0.2, 0);
    // turnToAngle(80);
    // driveAndTurn(1, 0);

    // driveAndTurn(0.35,270);
    // driveAndTurn(2,340);

    // pner.spin(fwd,100,pct);
    // wait(1000, msec);
    // pner.stop(hold);

    // inta.spin(fwd,100,pct);
    // driveAndTurn(2.3, 28,100,50);
    // turnToAngle(0);
    // driveAndTurn(-3, 43,55,100);
    // turnToAngle(135);

    // clip.set(true);
    // turnToAngle(-270);
    // turnToAngle(135);
    // clip.set(false);
    // driveAndTurn(1.3, 90, 100, 87);
    // inta.stop(brake);
    // driveAndTurn(0.8,90);
    // inta.spin(reverse,100,pct);

    ///////////////////////////////////////

    //75% 6pts POV red 
    //write in far_qua later

    setHeading(270);

    driveAndTurn(-1.1, 0);
    clip.set(true);

    inta.spin(reverse, 80, pct);
    turnToAngle(148);
    driveAndTurn(1, 150);
    turnToAngle(88, 100);
    driveAndTurn(1, 90, 100, 100);

    inta.spin(reverse, 80, pct);
    driveAndTurn(-1.2, 110);
    
    turnToAngle(55);
    inta.spin(reverse, 80, pct);
    driveAndTurn(0.7, 55, 100, 100);

    turnToAngle(-135);
    clip.set(false);
    intakeLift.set(true);
    driveAndTurn(0.75, -130);
    inta.stop(brake);
}

