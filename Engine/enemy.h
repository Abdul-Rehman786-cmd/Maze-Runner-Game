#pragma once
#pragma once
#pragma once
#include "Graphics.h"
#include"MazeSquare.h"
class enemy {
public:
    int x;
    int  y;
    int vx;
    int vy;
    int radius = 7;
    bool horizontal_checker = true;
    bool vertical_checker = true;
    enemy() {

    }
    enemy(int a, int b, int ux, int uy)
    {
        x = a;
        y = b;
        vx = ux;
        vy = uy;
    }
    void drawEnemy(Graphics& gfx) {
        for (int dy = -radius; dy <= radius; dy++) {
            for (int dx = -radius; dx <= radius; dx++) {
                if (dx * dx + dy * dy <= radius * radius) {
                    gfx.PutPixel(x + dx, y + dy, 255, 255, 255);
                }
            }
        }

        int mouthWidth = 3;
        int mouthY = y + 3;
        for (int i = -mouthWidth; i <= mouthWidth; i++) {
            gfx.PutPixel(x + i, mouthY, 255, 0, 0);
            if (i % 2 == 0) {
                gfx.PutPixel(x + i, mouthY + 1, 255, 0, 0);
            }
        }

        for (int dy = -1; dy <= 1; dy++) {
            for (int dx = -1; dx <= 1; dx++) {
                if (dx * dx + dy * dy <= 1) {
                    gfx.PutPixel(x - 2 + dx, y - 1 + dy, 0, 0, 0);
                    gfx.PutPixel(x + 2 + dx, y - 1 + dy, 0, 0, 0);
                }
            }
        }



    }
    void horizontal_movement_forward()
    {

        x = x + vx;

    }
    void horizontal_movement_backward()
    {

        x = x - vx;

    }
    void vertical_movement_downward()
    {
        y = y + vy;

    }
    void vertical_movement_upward()
    {
        y = y - vy;

    }

};
