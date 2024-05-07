#include "panel.h"
#include "block.h"
#include "vec3.h"

Panel* convertToPanel(Block block) {
	block.x;
	Panel panel1 = {
		.axis = 'x',
		.axisPos = block.x + Size,
		.xMax = block.x + Size,
		.xMin = block.x - Size,
		.yMax = block.y + Size,
		.yMin = block.y - Size,
	};
	Panel panel2 = {
		.axis = 'x',
		.axisPos = block.x - Size,
		.xMax = block.x + Size,
		.xMin = block.x - Size,
		.yMax = block.y + Size,
		.yMin = block.y - Size,
	};
	Panel panel3 = {
		.axis = 'y',
		.axisPos = block.y + Size,
		.xMax = block.x + Size,
		.xMin = block.x - Size,
		.yMax = block.z + Size,
		.yMin = block.z - Size,
	};
	Panel panel4 = {
		.axis = 'y',
		.axisPos = block.y - Size,
		.xMax = block.x + Size,
		.xMin = block.x - Size,
		.yMax = block.z + Size,
		.yMin = block.z - Size,
	};
	Panel panel5 = {
		.axis = 'z',
		.axisPos = block.z + Size,
		.xMax = block.x + Size,
		.xMin = block.x - Size,
		.yMax = block.y + Size,
		.yMin = block.y - Size,
	};
	Panel panel6 = {
		.axis = 'z',
		.axisPos = block.z - Size,
		.xMax = block.x + Size,
		.xMin = block.x - Size,
		.yMax = block.y + Size,
		.yMin = block.y - Size,
	};
	Panel result[6] = { panel1,panel2 ,panel3,panel4,panel5,panel6 };
	return result;
}

Vec3 getPanelPos(Panel panel) {
	Vec3 result;
	if (panel.axis == 'x') {
		result.x = panel.axisPos;
		result.y = panel.yMax - Size;
		result.z = panel.xMax - Size;
	}
	else if (panel.axis == 'y') {
		result.x = panel.xMax - Size;
		result.y = panel.axisPos;
		result.z = panel.yMax - Size;
	}
	else {
		result.x = panel.xMax - Size;
		result.y = panel.yMax - Size;
		result.z = panel.axisPos;
	}
	return result;
}