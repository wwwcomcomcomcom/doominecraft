#pragma once
#include "controller.h"
#include "block.h"
#define playerWidth 1.0f
#define playerHeight 1.9f
#define playerHalfWidth playerWidth/2
#define playerHalfHeight playerHeight/2

// ����ü ����
typedef struct
{
    float rotationX, rotationY;
    float x, y, z;
    float vy;
}Player;

// �Լ� ����
Player movePlayer(Player, Keys,Block*);
