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

void interactBlock(bool destroy) {

	Vec3 facingVector = getVectorWithRotation(P.rotationX, P.rotationY);
	facingVector.x *= -1;
	facingVector.z *= -1;

	//printf("%.1f %.1f %.1f || %.1f %.1f %.1f\n", P.x, P.y, P.z, facingVector.x, facingVector.y, facingVector.z);

	int panelLength = blockLength * 6;
	Panel panels[6000];
	for (int i = 0; i < blockLength; i++) {
		Panel *blockPanels = convertToPanel(blocks[i]);
		for (int j = 0; j < 6; j++) {
			Panel newPanel = blockPanels[j];
			panels[i*6+j] = newPanel;
		}
	}
	qsort(panels, panelLength, sizeof(Panel), comparePanelDistance);
	for (int i = 0; i < panelLength; i++) {
		if (isFacingPanel(facingVector, panels[i])) {
			Vec3 playerPos = getPlayerPos(P);
			float playerAxisPos=0.0f;
			if (panels[i].axis == 'x') playerAxisPos = playerPos.x;
			if (panels[i].axis == 'y') playerAxisPos = playerPos.y;
			if (panels[i].axis == 'z') playerAxisPos = playerPos.z;
			float offset = panels[i].axisPos - playerAxisPos;
			if (panels[i].axis == 'x') {
				int roundX;
				if (isPositive(offset)) {
					roundX = (int)(panels[i].axisPos - Size);
				}
				else {
					roundX = (int)(panels[i].axisPos + Size);
				}
				int roundY = (int)(panels[i].yMax - Size);
				int roundZ = (int)(panels[i].xMax - Size);
				if (destroy) {
					if (isPositive(offset)) {
						roundX++;
					}
					else roundX--;
					removeBlock(roundX, roundY, roundZ);
					return;
				}
				addBlock(roundX, roundY, roundZ,P.selectedBlock);
			}
			else if (panels[i].axis == 'y') {
				int roundY;
				if (isPositive(offset)) {
					roundY = (int)(panels[i].axisPos - Size);
				}
				else {
					roundY = (int)(panels[i].axisPos + Size);
				}
				int roundX = (int)(panels[i].xMax - Size);
				int roundZ = (int)(panels[i].yMax - Size);
				if (destroy) {
					if (isPositive(offset)) {
						roundY++;
					}
					else roundY--;
					removeBlock(roundX, roundY, roundZ);
					return;
				}
				addBlock(roundX, roundY, roundZ,P.selectedBlock);
			}
			else {
				int roundZ;
				if (isPositive(offset)) {
					roundZ = (int)(panels[i].axisPos - Size);
				}
				else {
					roundZ = (int)(panels[i].axisPos + Size);
				}
				int roundY = (int)(panels[i].yMax - Size);
				int roundX = (int)(panels[i].xMax - Size);
				if (destroy) {
					if (isPositive(offset)) {
						roundZ++;
					}
					else roundZ--;
					removeBlock(roundX, roundY, roundZ);
					return;
				}
				addBlock(roundX, roundY, roundZ,P.selectedBlock);
			}
			
			break;
		}
		//panels[i]
	}
}

int comparePanelDistance(Panel *a,const Panel *b) {
	Vec3 aPos = getPanelPos(*a), bPos = getPanelPos(*b);
	Vec3 playerVec = getPlayerPos(P);
	float distanceA = getDistance(playerVec, aPos);
	float distanceB = getDistance(playerVec, bPos);
	if (distanceA < distanceB)
		return -1;
	return distanceA > distanceB;
}

bool isFacingPanel(Vec3 facingVec, Panel panel) {
	Vec3 playerPos;
	playerPos.x = P.x;
	playerPos.y = P.y+1.5;
	playerPos.z = P.z;
	if (panel.axis == 'x') {
		float offset = panel.axisPos - playerPos.x;
		float vecMultiplier = offset / facingVec.x;
		//if (vecMultiplier > 0) return false;
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
	else if (panel.axis == 'z') {
		float offset = panel.axisPos - playerPos.z;
		float vecMultiplier = offset / facingVec.z;
		//if (vecMultiplier > 0) return false;
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
	else /*if (panel.axis == 'y')*/ {
		float offset = panel.axisPos - playerPos.y;
		float vecMultiplier = offset / facingVec.y;
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

	printf("targetting exception");
	return true;

}
bool isPositive(float num) {
	if (num > 0) return true;
	else return false;
}