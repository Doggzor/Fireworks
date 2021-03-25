/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
    for (int i = 0; i < nSparks; ++i)
    {
        sparks0[i].init(x, y, vx, vy, size, c);
    }
    for (int i = 0; i < nSparks; ++i)
    {
        sparks1[i].init(x, y, vx, vy, size, c);
    }
    for (int i = 0; i < nSparks; ++i)
    {
        sparks2[i].init(x, y, vx, vy, size, c);
    }
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
    const float dt = ft.Mark();

    if (isStarted)
    {
        SpawnTimer = SpawnTime + duration;
        isStarted = false;
    }

    SpawnTimer += dt;
    durTimer0 += dt;
    durTimer1 += dt;
    durTimer2 += dt;
    if (!wave) {
        x = rng::rdm_float(50.0f, 750.0f);
        y = rng::rdm_float(50.0f, 550.0f);
    }

    SpawnWave(durTimer0, 0, sparks0);
    SpawnWave(durTimer1, 1, sparks1);
    SpawnWave(durTimer2, 2, sparks2);
    isDrawFinished0 = (durTimer0 >= duration);
    isDrawFinished1 = (durTimer1 >= duration - 0.37f);
    isDrawFinished2 = (durTimer2 >= duration - 0.74f);

    wave %= 3; //Reset waves

    //Movement of sparks
    for (int i = 0; i < nSparks; ++i)
    {
        sparks0[i].Update(dt);
    }
    for (int i = 0; i < nSparks; ++i)
    {
        sparks1[i].Update(dt);
    }
    for (int i = 0; i < nSparks; ++i)
    {
        sparks2[i].Update(dt);
    }
}

void Game::ComposeFrame()
{
    if (!isDrawFinished0)
    {
        for (int i = 0; i < nSparks; ++i)
        {
            sparks0[i].Draw(gfx);
        }
    }
    if (!isDrawFinished1)
    {
        for (int i = 0; i < nSparks; ++i)
        {
            sparks1[i].Draw(gfx);
        }
    }
    if (!isDrawFinished2)
    {
        for (int i = 0; i < nSparks; ++i)
        {
            sparks2[i].Draw(gfx);
        }
    }
}
