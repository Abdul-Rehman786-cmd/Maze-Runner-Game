#pragma once
#include "Graphics.h"
#include "player.h"

class target {
    int x;
    int y;
    int r;
    int g;
    int b;

public:
    void set(int a, int b, int red, int green, int blue) {
        x = a;
        y = b;
        r = red;
        g = green;
        b = blue;
    }

    void drawtarget(Graphics& gfx) {
        for (int i = 0; i <= 5; ++i) {
            for (int j = -i; j <= i; ++j) {
                gfx.PutPixel(x + j, y - i, r, g, b);
            }
        }

        // Draw the lower half of the diamond
        for (int i = 1; i <= 5; ++i) {
            for (int j = -5 + i; j <= 5 - i; ++j) {
                gfx.PutPixel(x + j, y + i, r, g, b);
            }
        }
    }

    int getX() { return x; }
    int getY()  { return y; }
    int getSize()  { return 5; } // Return the size of the diamond (half of the side length)
};