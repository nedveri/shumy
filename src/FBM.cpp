/*
 * FBM.cpp
 *
 *  Created on: Jul 7, 2026
 *      Author: nedveri
 */

#include "FBM.h"

namespace shumy
{

float FBM(float x, float y, int seed, unsigned short n)
{
	float value = 0, ampl = 1, amplSum = 0;
	int freq = 1;
	perlinSeed(seed);
	for (int i = 0; i < n; i++)
	{
		value += ampl * perlin(freq * x, freq * y);
		amplSum += ampl;

		freq*=2;
		ampl /= 2;
	}

	value /= amplSum;

	return value;
}

}
