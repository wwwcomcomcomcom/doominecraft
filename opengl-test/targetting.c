#include <stdlib.h>
#include "targetting.h"
#include "block.h"
#include "player.h"
#include "vec3.h"
#include "panel.h"

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
	Vec3 facingVector = getVectorWithRotation(P.rotationX, P.rotationY);

	int panelLength = blockLength * 6;
	Panel panels[600];
	for (int i = 0; i < blockLength; i++) {
		Panel *blockPanels = convertToPanel(blocks[i]);
		for (int j = 0; j < 6; j++) {
			panels[i*6+i] = blockPanels[i];
		}
	}
	qsort(panels, panelLength, sizeof(Panel), comparePanelDistance);
	
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