#pragma once
#define Size 0.5f

typedef struct
{
    int x, y, z;
    char textureSet;
}Block;

int blockLength;
Block blocks[1000];

Block makeBlock(int x, int y, int z,char textureSet);
void addBlock(int x, int y, int z, char textureSet);
void removeBlock(int x, int y, int z);