#include "collide.h"
#define Size 0.5f

AABB getBlockAABB(Block block) {
    AABB aabb;
    aabb.maxX = block.x + Size;
    aabb.minX = block.x - Size;
    aabb.maxY = block.y + Size;
    aabb.minY = block.y - Size;
    aabb.maxZ = block.z + Size;
    aabb.minZ = block.z - Size;
    return aabb;
}
AABB getPlayerAABB(Player player) {
    AABB aabb;
    aabb.maxX = player.x + playerHalfWidth;
    aabb.minX = player.x - playerHalfWidth;
    aabb.maxY = player.y + playerHalfHeight;
    aabb.minY = player.y - playerHalfHeight;
    aabb.maxZ = player.z + playerHalfWidth;
    aabb.minZ = player.z - playerHalfWidth;
    return aabb;
}
bool isCollide(AABB obj1, AABB obj2) {
    if (
        obj1.maxX > obj2.minX
        && obj2.maxX > obj1.minX
        && obj1.maxY > obj2.minY
        && obj2.maxY > obj1.minY
        && obj1.maxZ > obj2.minZ
        && obj2.maxZ > obj1.minZ
        ) return true;
    else return false;
}