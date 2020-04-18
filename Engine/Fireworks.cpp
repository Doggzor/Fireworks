#include "Fireworks.h"

void Fireworks::Draw(float x, float y, Graphics& gfx) const
{
	gfx.PutPixel(x, y, c);
}

void Fireworks::Update()
{
	x += vx;
	y += vy;
}

void Fireworks::init(float in_x, float in_y, float in_vx, float in_vy, Color in_c)
{
	x = in_x;
	y = in_y;
	vx = in_vx;
	vy = in_vy;
	c = in_c;

}

