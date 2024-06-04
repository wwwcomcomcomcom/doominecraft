#pragma once
#define Size 0.5f

typedef struct
{
    int x, y, z;
}Block;

int blockLength;
Block blocks[1000];

Block makeBlock(int x, int y, int z);
void addBlock(int x, int y, int z);
void removeBlock(int x, int y, int z);