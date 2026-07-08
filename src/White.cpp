/*
 * WhiteNoise.cpp
 *
 *  Created on: Jul 7, 2026
 *      Author: nedveri
 */

#include <White.h>

const unsigned X_CONST = 374761393;
const unsigned Y_CONST = 668265263;
const unsigned SEED_CONST = 1442695041;

namespace shumy
{

unsigned hash(unsigned value)
{
	unsigned x = value;
	x ^= x >> 16;
	x *= 0x7feb352d;
	x ^= x >> 15;
	x *= 0x846ca68b;
	x ^= x >> 16;
	return x;
}

float white(float x, float y, int seed)
{
	unsigned input = (unsigned)x * X_CONST
			+ (unsigned)y * Y_CONST
			+ (unsigned)seed * SEED_CONST;
	unsigned hashValue = hash(input);
	float value =  hashValue / (float)std::numeric_limits<unsigned int>::max();
	return value * 2 - 1;
}

}
