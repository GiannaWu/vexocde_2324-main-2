#pragma once

#include "main.h"

int autonpick();

class GuiButton {
    public:
        GuiButton(int x, int y, int width, int height, color background_color, color selected_color, char *text);
        bool containsPosition(int posX, int posY);
        bool isPressing();
        void setSelected(bool state);
        void draw();
    private:
        int x, y;
        int width, height;
        color background_color, selected_color;
        color display_color;
        char *text;
};
