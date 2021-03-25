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
#include "Numbers.h"
#include "FrameTimer.h"
#include "Fireworks.h"
#include "rng.h"

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
    void SpawnWave(float& durTimer, int Wave, Fireworks* sparks)
    {
        if (SpawnTimer >= SpawnTime * !wave + (bool)wave * 0.3f && wave == Wave) {
            for (int i = 0; i < nSparks; ++i)
            {
                speed = rng::rdm_float(-maxSpeed, maxSpeed);
                vx = speed;
                speed = rng::rdm_float(-maxSpeed, maxSpeed);
                vy = speed;
                while (vx * vx + vy * vy > maxSpeed * maxSpeed / 2)
                {
                    vx = vx * 0.5f;
                    vy = vy * 0.5f;
                }
                c = rng::rdm_color8();
                sparks[i].init(x, y, vx, vy, size, c);
            }
            ++wave;
            SpawnTimer = 0.0f;
            durTimer = 0.0f;
        }
    }
	/********************************/
private:
	MainWindow& wnd;
	Graphics gfx;
	/********************************/
	/*  User Variables              */
    FrameTimer ft;
    int cSpectrum = 0;
    Color c = Colors::Black;
    float x = 0.0f;
    float y = 0.0f;
    float vx = 0.0f;
    float vy = 0.0f;
    float SpawnTimer = 0.0f;
    float speed = 0.0f;
    float durTimer0 = 0.0f;
    float durTimer1 = 0.0f;
    float durTimer2 = 0.0f;
    bool isStarted = true;
    bool isDrawFinished0 = true;
    bool isDrawFinished1 = true;
    bool isDrawFinished2 = true;
    int wave = 0;

    /***Modifiable values of fireworks******        ****************************/
    static constexpr int nSparks = 500;             //Number of sparks
    static constexpr int size = 1;                  //Size of sparks
    static constexpr float SpawnTime = 5.5f;        //Time between 2 fireworks
    static constexpr float maxSpeed = 60.0f;        //Speed of sparks
    static constexpr float duration = 3.5f;         //How long the sparks last
    /***************************************        ****************************/

    Fireworks sparks0[nSparks];
    Fireworks sparks1[nSparks];
    Fireworks sparks2[nSparks];
	/********************************/
};