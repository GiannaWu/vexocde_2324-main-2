#include "botcontrol.h"
#include "main.h"
#include "robot-config.h"
using namespace vex;

  // if (fabs(input)<width){
  //   return(0);
  // }
  // return(input);
int pxpos = 480/2;
int pypos = 240/2;
int turningCurve = 5;
int x = 1;
int push = 0;
int y = 1;
int push1 = 0;
bool turningRed = false;

int forwardCurve = 10;
bool forwardRed = false;

bool intaReverse = false;
bool intaForward = false;

int curveJoystick(bool red, int input, double t){
  int val = 0;
  if(red){
    val = (std::exp(-t/10)+std::exp((std::abs(input)-100)/10)*(1-std::exp(-t/10))) * input;
  }else{
    //blue
    val = std::exp(((std::abs(input)-100)*t)/1000) * input;
  }
  return val;
}

void intakeThread() {
  while (1) {
    
    if(con.ButtonR1.pressing()) {
        // Debounce button press
        while(con.ButtonR1.pressing()) {
            wait(10, msec);
        }

        // Toggle reverse spinning state
        if(intaReverse) {
            intamo.stop(brake);
            intaReverse = false;
        } else {
            intamo.spin(reverse, 80, pct);
            intaReverse = true;
            intaForward = false;  // Ensure forward spin is stopped
        }
    } else if(con.ButtonR2.pressing()) {
        // Debounce button press
        while(con.ButtonR2.pressing()) {
            wait(10, msec);
        }

        // Toggle forward spinning state
        if(intaForward) {
            intamo.stop(brake);
            intaForward = false;
        } else {
            intamo.spin(fwd, 80, pct);
            intaForward = true;
            intaReverse = false;  // Ensure reverse spin is stopped
        }
    } else {
        // Stop the intake motor if neither button is pressed
        if(!intaForward && !intaReverse) {
            intamo.stop(brake);
        }
    }
    wait(10, msec);
  }
}

void driver(){
  task intakeTask([] () -> int { intakeThread(); return 1; });

  while(1){
    Brain.Screen.printAt(180, 136, "L1 Temp: %.2f C", l1.temperature(temperatureUnits::celsius));
    Brain.Screen.printAt(180, 156, "L2 Temp: %.2f C", l2.temperature(temperatureUnits::celsius));
    Brain.Screen.printAt(180, 176, "L3 Temp: %.2f C", l3.temperature(temperatureUnits::celsius));

    Brain.Screen.printAt(180, 196, "R1 Temp: %.2f C", r1.temperature(temperatureUnits::celsius));
    Brain.Screen.printAt(180, 216, "R2 Temp: %.2f C", r2.temperature(temperatureUnits::celsius));
    Brain.Screen.printAt(180, 236, "R3 Temp: %.2f C", r3.temperature(temperatureUnits::celsius));

    Brain.Screen.printAt(180, 256, "Intake Temp: %.2f C", intamo.temperature(temperatureUnits::celsius));

      // double turnVal = curveJoystick(false, con.Axis1.position(percent), turningCurve); //Get curvature according to settings [-100,100]
      // double forwardVal = curveJoystick(false, con.Axis3.position(percent), forwardCurve); //Get curvature according to settings [-100,100]

      // double turnVolts = turnVal * 0.12; //Converts to voltage
      // double forwardVolts = forwardVal * 0.12; //Converts to voltage

      // leftmo.spin(forward, forwardVolts + turnVolts, voltageUnits::volt); //Apply Via Voltage
      // rightmo.spin(forward, forwardVolts - turnVolts, voltageUnits::volt);

      // vex::task::sleep(20);

      // if(con.ButtonL2.pressing()){
      //   inta.spin(reverse, 100, pct);
      //  } else if(con.ButtonL1.pressing()){
      //    inta.spin(fwd, 100, pct);
      // } else{
      //   inta.stop(brake);
      // }



    // if(con.ButtonX.pressing()){
    //   pner.spin(reverse, 30, pct);
    // } else if(con.ButtonB.pressing()){
    //   pner.spin(fwd, 30, pct);
    // } else{
    //   pner.stop(hold);
    // }

/////////////////////////////////////////////////////////////////

    //distance sensor
    /*double distance = tim.objectDistance(mm);
    if(distance < 10){
      hood.set(false);
    } else{
      hood.set(true);
    }*/
   

/////////////////////////////////////////////////////////////////

    //elevation button need to change
    // if(con.ButtonDown.pressing() == true)
    //   {
    //     x++;
    //   }
    // else
    //   {
    //     x = 0 ;
    //   }
    // if(x == 1)
    //   {
    //     if(push == 0)
    //     {
    //       elevation.set(true);
    //       push = 1;
    //     }
    //     else if (push == 1)
    //     {
          
    //       elevation.set(false);
          
    //       push = 0;
    //     }
    //   }

    //clamp
    if(con.ButtonA.pressing() == true)
      {
        y++;
      }
    else
      {
        y = 0 ;
      }
    if(y == 1)
      {
        waitUntil(!con.ButtonA.pressing());
        if(push1 == 0)
        {
          clamp.set(true);
          push1 = 1;
        }
        else if (push1 == 1)
        {
          clamp.set(false);
          push1 = 0;
        }
      }

      //intakeLift 
      if(con.ButtonL2.pressing() == true)
      {
        y++;
      }
      else
      {
        y = 0 ;
      }
      if(y == 1)
      {
        waitUntil(!con.ButtonL2.pressing());
        if(push1 == 0)
        {
          intakeLift.set(true);
          push1 = 1;
        }
        else if (push1 == 1)
        {
          intakeLift.set(false);
          push1 = 0;
        }
      }

/////////////////////////////////////////////////////////////////

    double axis3 = con.Axis3.position(pct);
    double axis1 = -con.Axis1.position(pct);
    double leftVolt = axis3 - axis1;
    double rightVolt = axis3 + axis1;
    double scale = 12.0 / fmax(12.0, fmax(fabs(leftVolt), fabs(rightVolt)));
    leftVolt *= scale;
    rightVolt *= scale;
    if (fabs(leftVolt) < 0.1){
        leftmo.stop(brake);
    } 
    else{
        leftmo.spin(forward, leftVolt, volt);
    }
    if(fabs(rightVolt) < 0.1){
        rightmo.stop(brake);
    }
    else{
        rightmo.spin(forward, rightVolt, volt);
    }

//////////////////////////////////////////////////////////////////////////////


    wait(20, msec);
  }
}
