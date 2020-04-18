#pragma once
#include "Graphics.h"
class Fireworks
{
public:
	void Draw(float x, float y, Graphics& gfx) const;
	void Update();
	void init(float in_x, float in_y, float in_vx, float in_vy, Color in_c);
	float x;
	float y;
	Color c;
	float vx;
	float vy;
};

