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
Vec3 getDirectionWithRotation(float, float);
Vec3 getVectorWithRotation(float, float);
Vec3 multiplyVec3(Vec3, float);
float getDistance(Vec3 fromVec, Vec3 toVec);
Vec3 sumVector(Vec3 vec1, Vec3 vec2);