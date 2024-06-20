#pragma once
#pragma once
#include "Graphics.h"
class MazeSagment
{
public:
    int x;
    int y;
    int r;
    int g;
    int b;
    bool isWall = false;

    void Sagment(int x_axis, int y_axis, int red, int green, int blue)
    {
        x = x_axis;
        y = y_axis;
        r = red;
        g = green;
        b = blue;
    }

    void DrawSagment(Graphics& gfx)
    {
        for (int i = -5; i < 5; i++)
        {
            for (int j = -5; j < 5; j++)
            {
                gfx.PutPixel(x + j, y + i, r, g, b);
            }
        }
    }
};
