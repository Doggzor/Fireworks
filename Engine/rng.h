#pragma once
#include <random>
#include "Graphics.h"

class rng
{
public:
	static int rdm_int(int min, int max)
	{
		return std::uniform_int_distribution<int>(min, max)(std::mt19937(std::random_device()()));
	}
	static float rdm_float(float min, float max)
	{
		return std::uniform_real_distribution<float>(min, max)(std::mt19937(std::random_device()()));
	}
	static bool rdm_outcome(int success_chance)
	{
		return rdm_int(0, 100) <= success_chance;
	}
	static Color rdm_color()
	{
		return Colors::MakeRGB(rdm_int(0, 255), rdm_int(0, 255), rdm_int(0, 255));
	}
	static Color rdm_color8()
	{
        int cSpectrum = rdm_int(0, 7);
        switch (cSpectrum)
        {
        case 0: return Colors::Blue;
        case 1: return  Colors::Cyan;
        case 2: return  Colors::Green;
        case 3: return  Colors::Magenta;
        case 4: return  Colors::Orange;
        case 5: return  Colors::Red;
        case 6: return  Colors::White;
        case 7: return  Colors::Yellow;
        }
	}
};