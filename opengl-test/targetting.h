#pragma once
#include "block.h"
#include "panel.h"
#include <stdbool.h>

static Block _targettedBlock;
static bool hasTargettedBlock = false;

Block getTargettingBlock();
int comparePanelDistance(Panel*,Panel*);
void updateTarget();