#pragma once
#include "Graphics.h"
#include "MazeSquare.h"  // Include MazeSquare header for Square class

class player
{
public:
    int x;
    int y;
   
    player() {}

    player(int a, int b)
        : x(a), y(b)
    {
    }

    void DrawPlayer(Graphics& gfx) const {
       
        for (int dy = -5; dy <= 5; dy++) {
            for (int dx = -5; dx <= 5; dx++) {
                if (dx * dx + dy * dy <= 5 * 5) {
                    gfx.PutPixel(x + dx, y + dy, 255, 224, 189); // Skin color for the head
                }
            }
        }

        // Eyes
        gfx.PutPixel(x - 2, y - 2, 0, 0, 0); // Left eye
        gfx.PutPixel(x + 2, y - 2, 0, 0, 0); // Right eye

        // Body
        for (int dy = 6; dy <= 12; dy++) {
            for (int dx = -4; dx <= 4; dx++) {
                gfx.PutPixel(x + dx, y + dy, 0, 0, 255); // Blue color for the body
            }
        }
    }

    void move(int deltaX, int deltaY) {
        x = x + deltaX;
        y = y + deltaY;
        
    }
};
