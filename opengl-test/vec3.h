#pragma once
#include "stdbool.h"

typedef struct
{
	float x, y, z;
}Vec3;

static const Vec3 ORIGIN = {
	0.0f,
	0.0f,
	0.0f
};

bool equalsVec3(Vec3, Vec3);