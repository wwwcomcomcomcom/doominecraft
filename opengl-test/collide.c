#include <float.h>
#include "collide.h"
#include "vec3.h"

#define Size 0.5f
#define arrSize 6


#include <stdio.h>
#include <math.h>

float* absOfArr(float* arr) {
    static float result[arrSize];
    for (int i = 0; i < arrSize; i++) {
        result[i] = fabs(arr[i]);
    }
    return result;
}
/* result it's index*/
//int minIndexOfArr(float arr[], int size) {
//    int result = 0;
//    for (int i = 1; i < size; i++)
//    {
//        if (arr[i] < arr[result]) result++;
//    }
//    return result;
//}

int findMinIndex(float arr[], int size) {
    // 배열의 첫 번째 요소를 최솟값으로 가정합니다.
    float min = arr[0];
    int minIndex = 0;

    // 나머지 요소들과 비교하여 최솟값을 찾습니다.
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
    }

    return minIndex;
}


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
    aabb.maxY = player.y + playerHeight;
    aabb.minY = player.y;
    aabb.maxZ = player.z + playerHalfWidth;
    aabb.minZ = player.z - playerHalfWidth;
    return aabb;
}
Vec3 isCollide(AABB obj1, AABB obj2) {



    if (
        obj1.maxX > obj2.minX
        && obj2.maxX > obj1.minX
        && obj1.maxY > obj2.minY
        && obj2.maxY > obj1.minY
        && obj1.maxZ > obj2.minZ
        && obj2.maxZ > obj1.minZ
        ) {
        float allOffset[arrSize] = {
            obj2.minX - obj1.maxX,
            obj2.maxX - obj1.minX,

            obj2.minY - obj1.maxY,
            obj2.maxY - obj1.minY,

            obj2.minZ - obj1.maxZ,
            obj2.maxZ - obj1.minZ
        };

        float* absArrP = absOfArr(allOffset);
        int minIndex = findMinIndex(absArrP, arrSize);

        float min = allOffset[minIndex];

        Vec3 overlapOffset = {
            0.0f,
            0.0f,
            0.0f,
        };

        switch (minIndex/2)
        {
        case 0:
            overlapOffset.x = min;
            break;
        case 1:
            overlapOffset.y = min;
            break;
        case 2:
            overlapOffset.z = min;
            break;
        default:
            break;
        }

        

        //if (overlapOffset.x > 0) overlapOffset.x = obj2.maxX - obj1.minX;

        //printf("%.1f %.1f %.1f\n", overlapOffset.x, overlapOffset.y, overlapOffset.z);
        /*if (overlapOffset.y > 0) overlapOffset.y = ;
        if (overlapOffset.z > 0) overlapOffset.z = ;*/

        return overlapOffset;
    }
    else return ORIGIN;
}