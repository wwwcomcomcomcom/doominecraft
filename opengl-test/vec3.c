#include "vec3.h"

bool equalsVec3(Vec3 vec1, Vec3 vec2) {
	if (
		vec1.x == vec2.x
		&& vec1.y == vec2.y
		&& vec1.z == vec2.z
		) return 1;
	else return 0;
}