#include "block.h"

Block makeBlock(int x, int y, int z) {
    Block result;
    result.x = x;
    result.y = y;
    result.z = z;
    return result;
}
void addBlock(int x, int y, int z) {
    blocks[blockLength] = makeBlock(x, y, z);
    blockLength = blockLength + 1;
}
void removeBlock(int x, int y, int z) {
    int resultIndex = -1;
    for (int i = 0; i < blockLength; i++) {
        if (blocks[i].x == x && blocks[i].y == y && blocks[i].z == z) {
            resultIndex = i;
            break;
        }
    }
    if (resultIndex == -1) return;
    
    for (int i = resultIndex; i < blockLength - 1; i++) blocks[i] = blocks[i + 1];
}