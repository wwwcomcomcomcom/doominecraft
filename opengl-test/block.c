#include "block.h"
#include <stdio.h>

Block makeBlock(int x, int y, int z,char textureSet) {
    Block result;
    result.x = x;
    result.y = y;
    result.z = z;
    result.textureSet = textureSet;
    return result;
}
void addBlock(int x, int y, int z,char textureSet) {
    blocks[blockLength] = makeBlock(x, y, z, textureSet);
    blockLength = blockLength + 1;
}
void removeBlock(int x, int y, int z) {
    int resultIndex = -1;
    printf("%d %d %d\n", x, y, z);
    for (int i = 0; i < blockLength; i++) {
        if (blocks[i].x == x && blocks[i].y == y && blocks[i].z == z) {
            resultIndex = i;
            break;
        }
    }
    if (resultIndex == -1) return;

    printf("The %d %d %d\n", x, y, z);
    for (int i = resultIndex; i < blockLength - 1; i++) blocks[i] = blocks[i + 1];
    blockLength--;
}