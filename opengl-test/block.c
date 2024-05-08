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