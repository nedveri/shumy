/*
 * Perlin.cpp
 *
 *  Created on: Jul 6, 2026
 *      Author: nedveri
 */

#include <Perlin.h>

namespace shumy
{

int permTable[512];

float gradient[16][2] = {
		{ 1,  0},
		{-1,  0},
		{ 0,  1},
		{ 0, -1},

		{ 0.7071,  0.7071},
		{-0.7071,  0.7071},
		{ 0.7071, -0.7071},
		{-0.7071, -0.7071},

		{ 0.9239,  0.3827},
		{-0.9239,  0.3827},
		{ 0.9239, -0.3827},
		{-0.9239, -0.3827},

		{ 0.3827,  0.9239},
		{-0.3827,  0.9239},
		{ 0.3827, -0.9239},
		{-0.3827, -0.9239}
};

void perlinSeed(int seed){
	std::mt19937 rng(seed);
	for (int i = 0; i < 256; i++)
		permTable[i] = i;

	std::shuffle(permTable, permTable+256, rng);
	for (int i = 256; i < 512; i++)
		permTable[i] = permTable[i-256];
}

static float lerp(float a0, float a1, float w)
{
	return (a1 - a0) * (3 - 2 * w) * w * w + a0;
}

int perm(int ix, int iy)
{
	ix = ((ix % 256) + 256) % 256;
	iy = ((iy % 256) + 256) % 256;
	int value = permTable[ix];
		value = permTable[value + iy];
	return value % 16;
}

float dotProduct(int ix, int iy, float x, float y)
{
	float dx = x - (float)ix;
	float dy = y - (float)iy;

	int dir = perm(ix, iy);

	return (dx * gradient[dir][0]) + (dy * gradient[dir][1]);
}

float perlin(float x, float y)
{
	float value, sx, sy, n0, n1, ix0, ix1;
	int x0, y0, x1, y1;
	x0 = (int)floor(x);
	y0 = (int)floor(y);
	x1 = x0 + 1;
	y1 = y0 + 1;
	sx = x - (float)x0;
	sy = y - (float)y0;

	n0 = dotProduct(x0, y0, x, y);
	n1 = dotProduct(x1, y0, x, y);
	ix0 = lerp(n0, n1, sx);
	n0 = dotProduct(x0, y1, x, y);
	n1 = dotProduct(x1, y1, x, y);
	ix1 = lerp(n0, n1, sx);
	value = lerp(ix0, ix1, sy);

	return value;
}

}
