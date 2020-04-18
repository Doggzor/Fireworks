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
        sparks[i].init(x, y, vx, vy, size, c);
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
    durTimer += dt;
    if (SpawnTimer >= SpawnTime)
    {
        x = rng::rdm_float(50.0f, 750.0f);
        y = rng::rdm_float(50.0f, 550.0f);
        for (int i = 0; i < nSparks; ++i)
        {
            speed = rng::rdm_float(-maxSpeed, maxSpeed);
            vx = speed;
            speed = rng::rdm_float(-maxSpeed, maxSpeed);
            vy = speed;
            cSpectrum = rng::rdm_int(0, 7);
            if (cSpectrum == 0) { c = Colors::Blue; }
            if (cSpectrum == 1) { c = Colors::Cyan; }
            if (cSpectrum == 2) { c = Colors::Green; }
            if (cSpectrum == 3) { c = Colors::Magenta; }
            if (cSpectrum == 4) { c = Colors::Orange; }
            if (cSpectrum == 5) { c = Colors::Red; }
            if (cSpectrum == 6) { c = Colors::White; }
            if (cSpectrum == 7) { c = Colors::Yellow; }
            sparks[i].init(x, y, vx, vy, size, c);
        }
        SpawnTimer = 0.0f;
        durTimer = 0.0f;
    }
    isDrawFinished = (durTimer >= duration);

    for (int i = 0; i < nSparks; ++i)
    {
        sparks[i].Update(dt);
    }
}

void Game::ComposeFrame()
{
    if (!isDrawFinished)
    {
        for (int i = 0; i < nSparks; ++i)
        {
            sparks[i].Draw(gfx);
        }
    }
}
