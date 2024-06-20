#pragma once
#include "MazeSagment.h"
#include "player.h"

class Square {
public:
    MazeSagment** mazesagment;
    player p;
    int x, y, w, h, r, g, b;
    int size;
    void setsquare(int ax, int ay, int s, int width, int height, int red, int green, int blue)
    {
        x = ax;
        y = ay;
        size = s;
        w = width;
        h = height;
        r = red;
        g = green;
        b = blue;
        mazesagment = new MazeSagment * [size];
        for (int i = 0; i < size; i++) {
            mazesagment[i] = new MazeSagment[size];
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                mazesagment[i][j].Sagment(x + w, y, r, g, b);
                w += 10;
            }
            w = 0;
            h = 10;
            y += h;
        }
    }

    void DrawSquare(Graphics& gfx)
    {
        int doorWidth = 3;
        int doorStart1 = (size / 25) - (doorWidth / 2);
        int doorEnd1 = doorStart1 + doorWidth;
        int doorStart2 = (size / 6) - (doorWidth / 2);
        int doorEnd2 = doorStart2 + doorWidth;
        int doorStart3 = (size / 2) - (doorWidth / 2);
        int doorEnd3 = doorStart3 + doorWidth;
        int doorStart4 = (size / 5) - (doorWidth / 2);
        int doorEnd4 = doorStart4 + doorWidth;
        int doorStart5 = (size / 4) - (doorWidth / 2);
        int doorEnd5 = doorStart5 + doorWidth;
        int doorStart6 = (size / 5) - (doorWidth / 2);
        int doorEnd6 = doorStart6 + doorWidth;

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                bool isBoundary = (i == 0 || i == size - 1 || j == 0 || j == size - 1);
               bool isDoor1= size == 50 && (
                   (i == 0 || i == size - 1) && (j >= doorStart1 && j < doorEnd1) ||
                   (j == 0 || j == size - 1) && (i >= doorStart1 && i < doorEnd1)
                   );
               bool isDoor2 = size == 42 && (
                   //(i == 0 || i == size - 1) && (j >= doorStart2 && j < doorEnd2) ||
                   (j == 0 || j == size - 1) && (i >= doorStart2 && i < doorEnd2)
                   );
               bool isDoor3 = size == 34 && (
                   (i == 0 || i == size - 1) && (j >= doorStart3 && j < doorEnd3) //||
                   //(j == 0 || j == size - 1) && (i >= doorStart3 && i < doorEnd3)
                   );
               bool isDoor4 = size == 26 && (
                   (i == 0 || i == size - 1) && (j >= doorStart4 && j < doorEnd4) ||
                   (j == 0 || j == size - 1) && (i >= doorStart4 && i < doorEnd4)
                   );
               bool isDoor5 = size == 18 && (
                   //(i == 0 || i == size - 1) && (j >= doorStart5 && j < doorEnd5) ||
                   (j == 0 || j == size - 1) && (i >= doorStart5 && i < doorEnd5)
                   );
               bool isDoor6 = size == 10 && (
                   (i == 0 || i == size - 1) && (j >= doorStart6 && j < doorEnd6) //||
                   //(j == 0 || j == size - 1) && (i >= doorStart6 && i < doorEnd6)
                   );
                if (isBoundary &&!isDoor1&&!isDoor2 && !isDoor3&&!isDoor4&&!isDoor5&&!isDoor6) {
                    mazesagment[i][j].DrawSagment(gfx);
                }
            }
        }
    }
      

    bool CheckCollision(int px, int py, int playerWidth, int playerHeight) {
        int doorWidth = 3;
        int doorStart1 = (size / 25) - (doorWidth / 2);
        int doorEnd1 = doorStart1 + doorWidth;
        int doorStart2 = (size / 6) - (doorWidth / 2);
        int doorEnd2 = doorStart2 + doorWidth;
        int doorStart3 = (size / 2) - (doorWidth / 2);
        int doorEnd3 = doorStart3 + doorWidth;
        int doorStart4 = (size / 5) - (doorWidth / 2);
        int doorEnd4 = doorStart4 + doorWidth;
        int doorStart5 = (size / 4) - (doorWidth / 2);
        int doorEnd5 = doorStart5 + doorWidth;
        int doorStart6 = (size / 5) - (doorWidth / 2);
        int doorEnd6 = doorStart6 + doorWidth;

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                bool isBoundary = (i == 0 || i == size - 1 || j == 0 || j == size - 1);
                bool isDoor1 = size == 50 && (
                    (i == 0 || i == size - 1) && (j >= doorStart1 && j < doorEnd1) ||
                    (j == 0 || j == size - 1) && (i >= doorStart1 && i < doorEnd1)
                    );
                bool isDoor2 = size == 42 && (
                    //(i == 0 || i == size - 1) && (j >= doorStart2 && j < doorEnd2) ||
                    (j == 0 || j == size - 1) && (i >= doorStart2 && i < doorEnd2)
                    );
                bool isDoor3 = size == 34 && (
                    (i == 0 || i == size - 1) && (j >= doorStart3 && j < doorEnd3) //||
                    //(j == 0 || j == size - 1) && (i >= doorStart3 && i < doorEnd3)
                    );
                bool isDoor4 = size == 26 && (
                    (i == 0 || i == size - 1) && (j >= doorStart4 && j < doorEnd4) ||
                    (j == 0 || j == size - 1) && (i >= doorStart4 && i < doorEnd4)
                    );
                bool isDoor5 = size == 18 && (
                    //(i == 0 || i == size - 1) && (j >= doorStart5 && j < doorEnd5) ||
                    (j == 0 || j == size - 1) && (i >= doorStart5 && i < doorEnd5)
                    );
                bool isDoor6 = size == 10 && (
                    (i == 0 || i == size - 1) && (j >= doorStart6 && j < doorEnd6) //||
                    //(j == 0 || j == size - 1) && (i >= doorStart6 && i < doorEnd6)
                    );

                if (isBoundary && !isDoor1 && !isDoor2 && !isDoor3 && !isDoor4 && !isDoor5 && !isDoor6) {
                    if (px <= mazesagment[i][j].x+8 && px + playerWidth > mazesagment[i][j].x - 1 &&
                        py < mazesagment[i][j].y + 10 && py + playerHeight > mazesagment[i][j].y - 8) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
