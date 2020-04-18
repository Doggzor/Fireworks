#pragma once
#include "Graphics.h"
class Fireworks
{
public:
	void Draw(Graphics& gfx) const;
	void Update(float dt);
	void init(float in_x, float in_y, float in_vx, float in_vy, int in_size, Color in_c);
	float x;
	float y;
	Color c;
	float vx;
	float vy;
	int r;
};

