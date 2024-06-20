/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.h																				  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include"MazeSagment.h"
#include"MazeSquare.h"
#include"player.h"
#include"enemy.h"
#include"enemyMovement.h"
#include"target.h"


class Game
{
public:
	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();
private:
	void ComposeFrame();
	void UpdateModel();
	/********************************/
	/*  User Functions              */
	void DrawGameOver(int x, int y, Graphics& gfx);	
	void DrawMessage(int x, int y, Graphics& gfx);
	void DrawWelcomeMessage(int x, int y, Graphics& gfx);
	bool CheckCollision(player& p, target& t);
	int  random_x(int min_x, int max_x);
	int  random_y(int min_y, int max_y);
	void DrawNumber(int x, int y, int number, Graphics& gfx);
	void generateRandomNumbers(int array[], int size);
	void DrawYouWon(int x, int y, Graphics& gfx);
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
    int size0=58;
	int size1 = 50;
	int size2 = 42;
	int size3 = 34;
	int size4 = 26;
	int size5 = 18;
	int size6 = 10;
	int width = 0;
	int height = 0;
	int x0 = 5;
	int y0= 5;
	int x1 = 45;
	int y1 = 45;
	int x2 = 85;
	int y2 = 85;
	int x3= 125;
	int y3= 125;
	int x4 = 165;
	int y4 = 165;
	int x5 = 205;
	int y5 = 205;
	int x6 = 245;
	int y6 = 245;
	int px = 295;
	int py = 295;
	int ex0 = 105;
	int ey0 = 105;
	Square s0, s1, s2, s3, s4, s5, s6;
	
	player p;
	enemy e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11;
	enemyMovement m0,m1,m2,m3,m4,m5,m6,m7,m8,m9,m10,m11;
	target t0,t1,t2,t3,t4,t5,t6,t7;
	bool checker0 = true;
	bool checker1 = true;
	bool checker2 = true;
	bool checker3 = true;
	bool checker4 = true;
	bool checker5 = true;
	bool checker6 = true;
	bool checker7 = true;
	bool alternate0 = false;
	bool alternate1= false;
	bool alternate2= false;
	bool alternate3= false;
	bool alternate4 = false;
	bool alternate5 = false;
	bool alternate6 = false;
	bool alternate7= false;
	bool endgame = false;
	bool n1 = false;
	bool n2= false;
	bool n3= false;
	bool n4= false;
	bool n5= false;
	bool n6= false;
	bool n7= false;
	
	bool playerVisible = true;
	int lives=3;
	int a[7];
	bool nextlevel = true;
	
	/********************************/
};