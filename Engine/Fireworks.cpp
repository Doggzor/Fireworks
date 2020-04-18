#include "Fireworks.h"

void Fireworks::Draw(Graphics& gfx) const
{
	int int_x = (int)x;
	int int_y = (int)y;
	if(int_x >= 0 && int_x < gfx.ScreenWidth && int_y >=0 && int_y < gfx.ScreenHeight)
	//gfx.PutPixel(int_x, int_y, c);
	gfx.DrawCircle(int_x, int_y, r, c);
}

void Fireworks::Update(float dt)
{
	x += vx * dt;
	y += vy * dt;
}

void Fireworks::init(float in_x, float in_y, float in_vx, float in_vy, int in_size, Color in_c)
{
	x = in_x;
	y = in_y;
	vx = in_vx;
	vy = in_vy;
	r = in_size;
	c = in_c;
}

