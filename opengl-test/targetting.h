#pragma once
#include "block.h"
#include <stdbool.h>

Block _targettedBlock;
bool hasTargettedBlock = false;

Block getTargettingBlock();
int comparePanelDistance(Panel,Panel);