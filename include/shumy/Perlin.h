/*
 * Perlin.h
 *
 *  Created on: Jul 6, 2026
 *      Author: nedveri
 */

#ifndef INCLUDE_PERLIN_H_
#define INCLUDE_PERLIN_H_

#include <algorithm>
#include <random>

namespace shumy
{

float dotProduct(int ix, int iy, float x, float y);
void perlinSeed(int seed);
static float lerp(float a0, float a1, float w);
float perlin(float x, float y);
int perm(int ix, int iy);

}

#endif /* INCLUDE_PERLIN_H_ */
