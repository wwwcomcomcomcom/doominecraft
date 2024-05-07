#include "vec3.h"
#include "math.h"
#define PI 3.1415926535

bool equalsVec3(Vec3 vec1, Vec3 vec2) {
	if (
		vec1.x == vec2.x
		&& vec1.y == vec2.y
		&& vec1.z == vec2.z
		) return 1;
	else return 0;
}
Vec3 getVectorWithRotation(float rotationX, float rotationY) {
	Vec3 result;
	result.x = - sin(rotationY * PI / 180);
	result.y = -sin(rotationX * PI / 180);
	result.z = cos(rotationY * PI / 180);
	return result;
}

Vec3 multiplyVec3(Vec3 vector, float multiplier) {
	vector.x *= multiplier;
	vector.y *= multiplier;
	vector.z *= multiplier;
	return vector;
}