#pragma once
#include "block.h"
#include "player.h"
#include "stdbool.h"

typedef struct
{
    float maxX, minX, maxY, minY, maxZ, minZ;
}AABB;

AABB getBlockAABB(Block);
AABB getPlayerAABB(Player);
bool isCollide(AABB, AABB);