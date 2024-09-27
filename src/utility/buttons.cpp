#include "main.h"
#include "utility/buttons.h"
#include "robot-config.h"

int autonpick() {
  while(1) {
    if (Brain.Screen.pressing()){
      int X = Brain.Screen.xPosition();
      int Y = Brain.Screen.xPosition();
      if ((Y >= 120)){
        Brain.Screen.clearScreen();
        Brain.Screen.drawRectangle(0,0,480,272);
        Brain.Screen.setFillColor(red);
        Brain.Screen.printAt(180,136, "Close Auton");
        return 2;
      } else if(Y <= 120){
        Brain.Screen.clearScreen();
        Brain.Screen.drawRectangle(0,0,480,272);
        Brain.Screen.setFillColor(red);
        Brain.Screen.printAt(190,136, "Far Auton");
        return 1;
      }
    }
  }
}

GuiButton::GuiButton(int x, int y, int width, int height, color background_color, color selected_color, char *text) {
  (*this).x = x;
  this -> y = y;
  this -> width = width;
  this -> height = height;
  this -> background_color = background_color;
  this -> selected_color = selected_color;
  this -> display_color = background_color;
  this -> text = text;
}

bool GuiButton::containsPosition(int posX, int posY) {
  if (posX < x || posX > x + width) return false;
  if (posY < y || posY > y + height) return false;
  return true;
}

bool GuiButton::isPressing() {
  return containsPosition(Brain.Screen.xPosition(), Brain.Screen.yPosition());
}

void GuiButton::draw() {
  Brain.Screen.drawRectangle(x, y, width, height, display_color);
  Brain.Screen.setPenColor(white);
  Brain.Screen.printAt(x + width / 2, y + height / 2, false, text);
}

void GuiButton::setSelected(bool state) {
  if (state) display_color = selected_color;
  else display_color = background_color;
}
