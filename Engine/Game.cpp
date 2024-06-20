#include "MainWindow.h"
#include "Game.h"
#include "MazeSquare.h"
#include <random>
#include <ctime>
#include<fstream>
Game::Game(MainWindow& wnd)
    : wnd(wnd),
    gfx(wnd), p(px, py), e0(25, 25, 2, 2), e1(25, 560, 2, 2), e2(65, 65, 2, 2), e3(520, 65, 2, 2), e4(105, 105, 2, 2), e5(105, 480, 2, 2),
    e6(145, 145, 2, 2), e7(440, 145, 2, 2), e8(185, 185, 1, 1), e9(185, 400, 1, 1), e10(225, 225, 1, 1), e11(225, 360, 2, 2)
{
    s0.setsquare(x0, y0, size0, width, height, 60, 60, 60);
    s1.setsquare(x1, y1, size1, width, height, 60, 60, 60);
    s2.setsquare(x2, y2, size2, width, height, 60, 60, 60);
    s3.setsquare(x3, y3, size3, width, height, 60, 60, 60);
    s4.setsquare(x4, y4, size4, width, height, 60, 60, 60);
    s5.setsquare(x5, y5, size5, width, height, 60, 60, 60);
    s6.setsquare(x6, y6, size6, width, height, 60, 60, 60);
    m0.set(25, 25, 560, 560, e0);
    m0.p = &p;
    m1.set(25, 25, 560, 560, e1);
    m1.p = &p;
    m2.set(65, 65, 520, 520, e2);
    m2.p = &p;
    m3.set(65, 65, 520, 520, e3);
    m3.p = &p;
    m4.set(105, 105, 480, 480, e4);
    m4.p = &p;
    m5.set(105, 105, 480, 480, e5);
    m5.p = &p;
    m6.set(145, 145, 440, 440, e6);
    m6.p = &p;
    m7.set(145, 145, 440, 440, e7);
    m7.p = &p;
    m8.set(185, 185, 400, 400, e8);
    m8.p = &p;
    m9.set(185, 185, 400, 400, e9);
    m9.p = &p;
    m10.set(225, 225, 360, 360, e10);
    m10.p = &p;
    m11.set(225, 225, 360, 360, e11);
    m11.p = &p;
    t0.set(105, random_y(105, 480), 0, 255, 255);
    t1.set(random_x(65, 520), 520, 0, 255, 255);
    t2.set(440, random_y(145, 440), 0, 255, 255);
    t3.set(random_x(225, 360), 225, 0, 255, 255);
    t4.set(random_x(185, 400), 185, 0, 255, 255);
    t5.set(random_x(25, 560), 560, 0, 255, 255);
    t6.set(400, random_y(185, 400), 0, 255, 255);
    t7.set(520, random_x(65, 520), 0, 255, 255);

    // Generate random numbers for the array
    generateRandomNumbers(a, 7);
}

void Game::Go()
{
    gfx.BeginFrame();
    UpdateModel();
    ComposeFrame();
    gfx.EndFrame();
}

void Game::UpdateModel()
{
    int deltaX = 0;
    int deltaY = 0;
    const int playerWidth = 10;  // Assuming player width is 10
    const int playerHeight = 10; // Assuming player height is 10

    if (wnd.kbd.KeyIsPressed(VK_UP)) {
        deltaY = -2;
    }
    if (wnd.kbd.KeyIsPressed(VK_DOWN)) {
        deltaY = 2;
    }
    if (wnd.kbd.KeyIsPressed(VK_LEFT)) {
        deltaX = -2;
    }
    if (wnd.kbd.KeyIsPressed(VK_RIGHT)) {
        deltaX = 2;
    }

    if (!s0.CheckCollision(p.x + deltaX, p.y + deltaY, playerWidth, playerHeight) &&
        !s1.CheckCollision(p.x + deltaX, p.y + deltaY, playerWidth, playerHeight) &&
        !s2.CheckCollision(p.x + deltaX, p.y + deltaY, playerWidth, playerHeight) &&
        !s3.CheckCollision(p.x + deltaX, p.y + deltaY, playerWidth, playerHeight) &&
        !s4.CheckCollision(p.x + deltaX, p.y + deltaY, playerWidth, playerHeight) &&
        !s5.CheckCollision(p.x + deltaX, p.y + deltaY, playerWidth, playerHeight) &&
        !s6.CheckCollision(p.x + deltaX, p.y + deltaY, playerWidth, playerHeight)) {
        p.move(deltaX, deltaY);
    }

    m0.moveClockWise(gfx);
    m1.moveAntiClockWise(gfx);
    m2.vertical_movement(gfx);
    m3.vertical_movement(gfx);
    m4.horizontal_movement(gfx);
    m5.horizontal_movement(gfx);
    m6.vertical_movement(gfx);
    m7.vertical_movement(gfx);
    m8.moveClockWise(gfx);
    m9.moveAntiClockWise(gfx);
    m10.horizontal_movement(gfx);
    m11.horizontal_movement(gfx);

    if (m0.checkcollision() || m1.checkcollision() || m2.checkcollision() ||
        m3.checkcollision() || m4.checkcollision() || m5.checkcollision() ||
        m6.checkcollision() || m7.checkcollision() || m8.checkcollision() ||
        m9.checkcollision() || m10.checkcollision() || m11.checkcollision()) {
        lives--;
        p.x = 295;
        p.y = 300;
    }

    if (lives == 0 && !endgame)
    {
        playerVisible = false;
        DrawGameOver(600, 250, gfx);
    }
    

    if (CheckCollision(p, t0))
    {
        checker0 = false;
        alternate0 = true;
    }
    else if (CheckCollision(p, t1))
    {
        checker1 = false;
        alternate1 = true;
    }
    else if (CheckCollision(p, t2))
    {
        checker2 = false;
        alternate2 = true;
    }
    else if (CheckCollision(p, t3))
    {
        checker3 = false;
        alternate3 = true;
    }
    else if (CheckCollision(p, t4))
    {
        checker4 = false;
        alternate4 = true;
    }
    else if (CheckCollision(p, t5))
    {
        checker5 = false;
        alternate5 = true;
    }
    else if (CheckCollision(p, t6))
    {
        checker6 = false;
        alternate6 = true;
    }
    else if (CheckCollision(p, t7))
    {
        checker7 = false;
        alternate7 = true;
    }
    int startX = 580;
    int incrementX = 30; 
    int currentX = startX;

    if (n1)
    {
        DrawNumber(currentX, 50, a[0], gfx);
        currentX += incrementX;
    }
    if (n2)
    {
        DrawNumber(currentX, 50, a[1], gfx);
        currentX += incrementX;
    }
    if (n3)
    {
        DrawNumber(currentX, 50, a[2], gfx);
        currentX += incrementX;
    }
    if (n4)
    {
        DrawNumber(currentX, 50, a[3], gfx);
        currentX += incrementX;
    }
    if (n5)
    {
        DrawNumber(currentX, 50, a[4], gfx);
        currentX += incrementX;
    }
    if (n6)
    {
        DrawNumber(currentX, 50, a[5], gfx);
        currentX += incrementX;
    }
    if (n7)
    {
        DrawNumber(currentX, 50, a[6], gfx);
        currentX += incrementX;
    }
}

void Game::ComposeFrame()
{
    s0.DrawSquare(gfx);
    s1.DrawSquare(gfx);
    s2.DrawSquare(gfx);
    s3.DrawSquare(gfx);
    s4.DrawSquare(gfx);
    s5.DrawSquare(gfx);
    s6.DrawSquare(gfx);

    if (playerVisible  && !endgame) {
        p.DrawPlayer(gfx);
        DrawMessage(600, 300, gfx);
        DrawWelcomeMessage(600, 100, gfx);
    }
    if (endgame)
    {
        playerVisible = false;
        DrawYouWon(600, 300, gfx);
       

    }

    if (playerVisible && checker0 && !endgame)
    {
        t0.drawtarget(gfx);
    }
    else if (playerVisible && checker1 && alternate0 && !endgame)
    {
        t1.drawtarget(gfx);
        n1 = true;
    }
    else if (playerVisible && checker2 && alternate1 && !endgame)
    {
        t2.drawtarget(gfx);
        n2 = true;
    }
    else if (playerVisible && checker3 && alternate2 && !endgame)
    {
        t3.drawtarget(gfx);
        n3 = true;
    }
    else if (playerVisible && checker4 && alternate3 && !endgame)
    {
        t4.drawtarget(gfx);
        n4 = true;
    }
    else if (playerVisible && checker5 && alternate4 && !endgame)
    {
        t5.drawtarget(gfx);
        n5 = true;
    }
    else if (playerVisible && checker6 && alternate5&& !endgame)
    {
        t6.drawtarget(gfx);
        n6 = true;
    }
    else if(playerVisible && checker7 && alternate6 && !endgame)
    {
        t7.drawtarget(gfx);
        n7 = true;
        endgame = true;
    }
    else
    {

    }
   
   
    
}

void Game::DrawGameOver(int x, int y, Graphics& gfx) {
    // Define the pixel patterns for "GAME OVER"
    const int letterWidth = 5;
    const int letterHeight = 7;
    const int scale = 5; // Scaling factor to make the letters smaller
    const int spacing = 3;

    // G
    int g[letterHeight][letterWidth] = {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
    };

    // A
    int a[letterHeight][letterWidth] = {
        {0, 1, 1, 1, 0},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
    };

    // M
    int m[letterHeight][letterWidth] = {
        {1, 0, 0, 0, 1},
        {1, 1, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
    };

    // E
    int e[letterHeight][letterWidth] = {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1},
    };

    // O
    int o[letterHeight][letterWidth] = {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
    };

    // V
    int v[letterHeight][letterWidth] = {
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
    };

    // R
    int r[letterHeight][letterWidth] = {
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
    };

    // Draw the letters
    int offsetX = 0;
    int offsetY = 0;

    auto drawLetter = [&](int letter[letterHeight][letterWidth], int offsetX, int offsetY) {
        for (int i = 0; i < letterHeight; ++i) {
            for (int j = 0; j < letterWidth; ++j) {
                if (letter[i][j] == 1) {
                    for (int sy = 0; sy < scale; ++sy) {
                        for (int sx = 0; sx < scale; ++sx) {
                            gfx.PutPixel(x + j * scale + sx + offsetX, y + i * scale + sy + offsetY, 255, 255, 255); // Red color for the letters
                        }
                    }
                }
            }
        }
        };

    drawLetter(g, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(a, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(m, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(e, offsetX, offsetY);

    offsetX = 0;
    offsetY += (letterHeight * scale) + spacing;

    drawLetter(o, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(v, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(e, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(r, offsetX, offsetY);
}

void Game::DrawMessage(int x, int y, Graphics& gfx) {
    
    const int letterWidth = 5;
    const int letterHeight = 7;
    const int scale = 5; 
    const int spacing = 3;

    // W
    int w[letterHeight][letterWidth] = {
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 1},
        {0, 1, 0, 1, 0}
    };

    // I
    int i[letterHeight][letterWidth] = {
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1}
    };

    // C
    int c[letterHeight][letterWidth] = {
        {0, 1, 1, 1, 0},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    // K
    int k[letterHeight][letterWidth] = {
        {1, 0, 0, 0, 1},
        {1, 0, 0, 1, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 0, 1}
    };

    // E
    int e[letterHeight][letterWidth] = {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };

    // D
    int d[letterHeight][letterWidth] = {
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 0}
    };

    // Space
    int space[letterHeight][letterWidth] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // G
    int g[letterHeight][letterWidth] = {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
    };

    // O
    int o[letterHeight][letterWidth] = {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1}
    };

    // S
    int s[letterHeight][letterWidth] = {
        {0, 1, 1, 1, 1},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 1},
        {1, 1, 1, 1, 0}
    };

    // Draw the letters
    int offsetX = 0;
    int offsetY = 0;

    auto drawLetter = [&](int letter[letterHeight][letterWidth], int offsetX, int offsetY) {
        for (int i = 0; i < letterHeight; ++i) {
            for (int j = 0; j < letterWidth; ++j) {
                if (letter[i][j] == 1) {
                    for (int sy = 0; sy < scale; ++sy) {
                        for (int sx = 0; sx < scale; ++sx) {
                            gfx.PutPixel(x + j * scale + sx + offsetX, y + i * scale + sy + offsetY, 255, 255, 255); // Red color for the letters
                        }
                    }
                }
            }
        }
        };

    // Draw "WICKED"
    drawLetter(w, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(i, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(c, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(k, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(e, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(d, offsetX, offsetY);

    // Draw "IS"
    offsetX = 0;
    offsetY += (letterHeight * scale) + spacing;
    drawLetter(i, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(s, offsetX, offsetY);

    // Draw "GOOD"
    offsetX = 0;
    offsetY += (letterHeight * scale) + spacing;
    drawLetter(g, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(o, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(o, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(d, offsetX, offsetY);
}

void Game::DrawWelcomeMessage(int x, int y, Graphics& gfx) {
    // Define the pixel patterns for "WELCOME TO MAZE"
    const int letterWidth = 5;
    const int letterHeight = 7;
    const int scale = 5; // Scaling factor to make the letters larger
    const int spacing = 3;

    // W
    int w[letterHeight][letterWidth] = {
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 1},
        {0, 1, 0, 1, 0}
    };

    // E
    int e[letterHeight][letterWidth] = {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };

    // L
    int l[letterHeight][letterWidth] = {
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };

    // C
    int c[letterHeight][letterWidth] = {
        {0, 1, 1, 1, 0},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    // O
    int o[letterHeight][letterWidth] = {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1}
    };

    // M
    int m[letterHeight][letterWidth] = {
        {1, 0, 0, 0, 1},
        {1, 1, 0, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1}
    };

    // T
    int t[letterHeight][letterWidth] = {
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0}
    };

    int a[letterHeight][letterWidth] = {
        {0, 1, 1, 1, 0},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
    };

    // Z
    int z[letterHeight][letterWidth] = {
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 1, 0, 0, 0},
        {1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1}
    };

    // Space
    int space[letterHeight][letterWidth] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    // Draw the letters
    int offsetX = 0;
    int offsetY = 0;

    auto drawLetter = [&](int letter[letterHeight][letterWidth], int offsetX, int offsetY) {
        for (int i = 0; i < letterHeight; ++i) {
            for (int j = 0; j < letterWidth; ++j) {
                if (letter[i][j] == 1) {
                    for (int sy = 0; sy < scale; ++sy) {
                        for (int sx = 0; sx < scale; ++sx) {
                            gfx.PutPixel(x + j * scale + sx + offsetX, y + i * scale + sy + offsetY, 255, 255, 255); // Red color for the letters
                        }
                    }
                }
            }
        }
        };

    // Draw "WELCOME"
    drawLetter(w, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(e, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(l, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(c, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(o, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(m, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(e, offsetX, offsetY);

    // Draw "TO"
    offsetX = 0;
    offsetY += (letterHeight * scale) + spacing;
    drawLetter(t, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(o, offsetX, offsetY);

    // Draw "MAZE"
    offsetX = 0;
    offsetY += (letterHeight * scale) + spacing;
    drawLetter(m, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(a, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(z, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(e, offsetX, offsetY);
}

bool Game::CheckCollision(player& p, target& t) {
    int playerHalfSize = 5; // Assuming the player size is 10x10
    int targetHalfSize = t.getSize();

    int playerLeft = p.x - playerHalfSize;
    int playerRight = p.x + playerHalfSize;
    int playerTop = p.y - playerHalfSize;
    int playerBottom = p.y + playerHalfSize;

    int targetLeft = t.getX() - targetHalfSize;
    int targetRight = t.getX() + targetHalfSize;
    int targetTop = t.getY() - targetHalfSize;
    int targetBottom = t.getY() + targetHalfSize;

    return !(playerRight < targetLeft ||
        playerLeft > targetRight ||
        playerBottom < targetTop ||
        playerTop > targetBottom);
}

int Game::random_x(int min_x, int max_x)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min_x, max_x);
    return distrib(gen);
}

int Game::random_y(int min_y, int max_y)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min_y, max_y);
    return distrib(gen);
}

void Game::DrawNumber(int x, int y, int number, Graphics& gfx) {
    const int letterWidth = 5;
    const int letterHeight = 7;
    const int scale = 5;
    const int spacing = 3;

   
    int numbers[8][letterHeight][letterWidth] = {
        {
            {0, 0, 1, 0, 0},
            {0, 1, 1, 0, 0},
            {1, 0, 1, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0},
            {0, 0, 1, 0, 0},
            {1, 1, 1, 1, 1}
        },
        {
            {1, 1, 1, 1, 1},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0},
            {1, 0, 0, 0, 0},
            {1, 1, 1, 1, 1}
        },
        {
            {1, 1, 1, 1, 1},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1}
        },
        {
            {1, 0, 0, 0, 1},
            {1, 0, 0, 0, 1},
            {1, 0, 0, 0, 1},
            {1, 1, 1, 1, 1},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 0, 1}
        },
        {
            {1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0},
            {1, 0, 0, 0, 0},
            {1, 1, 1, 1, 1},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 0, 1},
            {1, 1, 1, 1, 1}
        },
        {
            {1, 1, 1, 1, 1},
            {1, 0, 0, 0, 0},
            {1, 0, 0, 0, 0},
            {1, 1, 1, 1, 1},
            {1, 0, 0, 0, 1},
            {1, 0, 0, 0, 1},
            {1, 1, 1, 1, 1}
        },
        {
            {1, 1, 1, 1, 1},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 0, 1},
            {0, 0, 0, 0, 1}
        },

    };

    
    if (number < 1 || number > 8) {
        return; 
    }

   
    for (int i = 0; i < letterHeight; ++i) {
        for (int j = 0; j < letterWidth; ++j) {
            if (numbers[number - 1][i][j] == 1) {
                for (int sy = 0; sy < scale; ++sy) {
                    for (int sx = 0; sx < scale; ++sx) {
                        gfx.PutPixel(x + j * scale + sx, y + i * scale + sy, 255, 255, 255);
                    }
                }
            }
        }
    }
}

void Game::generateRandomNumbers(int array[], int size) {
    srand(time(0));

    for (int i = 0; i < size; ++i) {
        int randomNumber;
        bool unique = false;

        while (!unique) {
            randomNumber = rand() % 7 + 1;
            unique = true;

            for (int j = 0; j < i; ++j) {
                if (array[j] == randomNumber) {
                    unique = false;
                    break;
                }
            }
        }

        array[i] = randomNumber;
    }
}

void Game::DrawYouWon(int x, int y, Graphics& gfx) {
    // Define the pixel patterns for "YOU WON"
    const int letterWidth = 5;
    const int letterHeight = 7;
    const int scale = 5; // Scaling factor to make the letters smaller
    const int spacing = 3;

    // Y
    int y_letter[letterHeight][letterWidth] = {
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
    };

    // O
    int o[letterHeight][letterWidth] = {
        {1, 1, 1, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 1, 1, 1, 1},
    };

    // U
    int u[letterHeight][letterWidth] = {
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {0, 1, 1, 1, 0},
    };

    // W
    int w[letterHeight][letterWidth] = {
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 1},
        {0, 1, 0, 1, 0},
    };

    // N
    int n[letterHeight][letterWidth] = {
        {1, 0, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
        {1, 0, 0, 0, 1},
    };

    // Draw the letters
    int offsetX = 0;
    int offsetY = 0;

    auto drawLetter = [&](int letter[letterHeight][letterWidth], int offsetX, int offsetY) {
        for (int i = 0; i < letterHeight; ++i) {
            for (int j = 0; j < letterWidth; ++j) {
                if (letter[i][j] == 1) {
                    for (int sy = 0; sy < scale; ++sy) {
                        for (int sx = 0; sx < scale; ++sx) {
                            gfx.PutPixel(x + j * scale + sx + offsetX, y + i * scale + sy + offsetY, 255, 255, 255); // White color for the letters
                        }
                    }
                }
            }
        }
        };

    drawLetter(y_letter, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(o, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(u, offsetX, offsetY);

    offsetX = 0;
    offsetY += (letterHeight * scale) + spacing;

    drawLetter(w, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(o, offsetX, offsetY);
    offsetX += (letterWidth * scale) + spacing;
    drawLetter(n, offsetX, offsetY);
}
