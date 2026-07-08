/*
 * Value.cpp
 *
 *  Created on: Jul 7, 2026
 *      Author: nedveri
 */

#include "shumy/Value.h"
#include "shumy/White.h"

namespace shumy
{

static float lerp(float a0, float a1, float w)
{
	return (a1 - a0) * (3 - 2 * w) * w * w + a0;
}

float value(float x, float y, int seed)
{
	float value, sx, sy, n0, n1, ix0, ix1;
	int x0, y0, x1, y1;
	x0 = (x > 0.0 ? (int)x : (int)x - 1);
	y0 = (y > 0.0 ? (int)y : (int)y - 1);
	x1 = x0 + 1;
	y1 = y0 + 1;
	sx = x - (float)x0;
	sy = y - (float)y0;


	n0 = shumy::white(x0, y0, seed);
	n1 = shumy::white(x1, y0, seed);
	ix0 = lerp(n0, n1, sx);
	n0 = shumy::white(x0, y1, seed);
	n1 = shumy::white(x1, y1, seed);
	ix1 = lerp(n0, n1, sx);
	value = lerp(ix0, ix1, sy);

	return value;
}

}
