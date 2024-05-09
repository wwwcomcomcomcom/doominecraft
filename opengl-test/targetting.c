#include <stdlib.h>
#include <stdbool.h>
#include "math.h"
#include "targetting.h"
#include "block.h"
#include "player.h"
#include "vec3.h"
#include "panel.h"

#include <stdio.h>

bool isFacingPanel(Vec3, Panel);
bool isPositive(float);

Block getTargettingBlock() {
	if (!hasTargettedBlock) {
		exit(-1);
		return _targettedBlock;
	}
	else {
		return _targettedBlock;
	}
}

void updateTarget() {
	printf("run\n");

	Vec3 facingVector = getVectorWithRotation(P.rotationX, P.rotationY);

	int panelLength = blockLength * 6;
	Panel panels[600];
	for (int i = 0; i < blockLength; i++) {
		Panel *blockPanels = convertToPanel(blocks[i]);
		for (int j = 0; j < 6; j++) {
			Panel newPanel = blockPanels[j];
			panels[i*6+j] = newPanel;
		}
	}
	printf("panel test %f\n", panels[3].axisPos);
	qsort(panels, panelLength, sizeof(Panel), comparePanelDistance);
	printf("panel test %f\n", panels[3].axisPos);
	for (int i = 0; i < panelLength; i++) {
		if (isFacingPanel(facingVector, panels[i])) {
			Vec3 playerPos = getPlayerPos(P);
			float offset = panels[i].axisPos - playerPos.x;
			int roundX;
			if (isPositive(offset)) {
				roundX = (int)roundf(panels[i].axisPos - Size);
			}
			else {
				roundX = (int)roundf(panels[i].axisPos + Size);
			}
			int roundY = (int)roundf(panels[i].yMax - Size);
			int roundZ = (int)roundf(panels[i].xMax - Size);
			addBlock(roundX, roundY, roundZ);
			break;
		}
		//panels[i]
	}
}

int comparePanelDistance(const Panel *a,const Panel *b) {
	Vec3 aPos = getPanelPos(*a), bPos = getPanelPos(*b);
	Vec3 playerVec = getPlayerPos(P);
	float distanceA = getDistance(playerVec, aPos);
	float distanceB = getDistance(playerVec, bPos);
	if (distanceA < distanceB)
		return -1;
	return distanceA > distanceA;
}

bool isFacingPanel(Vec3 facingVec, Panel panel) {
	Vec3 playerPos;
	playerPos.x = P.x;
	playerPos.y = P.y;
	playerPos.z = P.z;
	//Vec3 playerPos = getPlayerPos(P);
	printf("%f %f %f\n", P.x, playerPos.y, playerPos.z);
	if (panel.axis == 'x') {
		float offset = panel.axisPos - playerPos.x;
		float vecMultiplier = offset / facingVec.x;
		if (vecMultiplier < 0) return false;
		Vec3 facingPoint = sumVector(playerPos, multiplyVec3(facingVec, vecMultiplier));
		
		if(
			facingPoint.y > panel.yMin
			&& facingPoint.y < panel.yMax
			&& facingPoint.z > panel.xMin
			&& facingPoint.z < panel.xMax
		){
			return true;
		}
		else {
			return false;
		}
	}
	if (panel.axis == 'y') {
		float offset = panel.axisPos - playerPos.y;
		float vecMultiplier = offset / facingVec.y;
		if (vecMultiplier < 0) return false;
		Vec3 facingPoint = sumVector(playerPos, multiplyVec3(facingVec, vecMultiplier));

		if (
			facingPoint.z > panel.yMin
			&& facingPoint.z < panel.yMax
			&& facingPoint.x > panel.xMin
			&& facingPoint.x < panel.xMax
			) {
			return true;
		}
		else {
			return false;
		}
	}
	if (panel.axis == 'z') {
		float offset = panel.axisPos - playerPos.z;
		float vecMultiplier = offset / facingVec.z;
		if (vecMultiplier < 0) return false;
		Vec3 facingPoint = sumVector(playerPos, multiplyVec3(facingVec, vecMultiplier));

		if (
			facingPoint.y > panel.yMin
			&& facingPoint.y < panel.yMax
			&& facingPoint.x > panel.xMin
			&& facingPoint.x < panel.xMax
			) {
			return true;
		}
		else {
			return false;
		}
	}
}
bool isPositive(float num) {
	if (num > 0) return true;
	else return false;
}