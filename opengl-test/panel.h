#pragma once
#include "vec3.h"
typedef struct
{
	char axis;
	float axisPos;
	float xMin, xMax,yMin,yMax;
}Panel;

Panel* convertToPanel(Block);
Vec3 getPanelPos(Panel panel);