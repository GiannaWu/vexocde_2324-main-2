#include "vex.h"
#include "botcontrol.h"
#include "basic_control.h"
#include "robot-config.h"
#include "main.h"
#include "autons/auton.h"
#include "autons/auton_functions.h"
#include "utility/buttons.h"
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

int pick = 0;

float deadband(float input, float width){
  if (fabs(input)<width){
    return(0);
  }
  return(input);
}

void pre_auton(void) {
  vexcodeInit();
  bob.startCalibration();
  while(bob.isCalibrating()){
    wait(10, msec);
  }
  // heading_convert(bob.heading());

  GuiButton *pickAutonButtons[] = {
    // new GuiButton(0, 0, 480, 240, color(0, 0, 0), color(255, 0, 0)),
    new GuiButton(0, 0, 240, 120, color(0, 0, 0), color(255, 0, 0), "red left"),
    new GuiButton(240, 0, 240, 120, color(0, 0, 0), color(0, 255, 0), "red right"),
    new GuiButton(0, 120, 240, 120, color(0, 0, 0), color(0, 0, 255), "blue left"),
    new GuiButton(240, 120, 240, 120, color(0, 0, 0), color(255, 255, 0), "blue right"),
  };

  while(1) {
    
    // Detect
    for (int i = 0; i < 4; i++) {
      GuiButton *button = pickAutonButtons[i];
      // printf("press: %d\n", button -> isPressing());
      if (button -> isPressing()) {
        pick = i + 1;
        button -> setSelected(true);
      } else {
        button -> setSelected(false);
      }
    }

    // Draw
    for (GuiButton *button : pickAutonButtons) {
      button -> draw();
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
  if(pick == 1){
    red_left();
  }
  if(pick == 2){
    red_right();
  }
  if(pick == 3){
    blue_left();
  }
  if(pick == 4){
    blue_right();
  }
  blue_left();
  red_left();
  blue_right();
  red_right();
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
