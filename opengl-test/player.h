#pragma once
#include "controller.h"


// ����ü ����
typedef struct
{
    float rotationX, rotationY;
    float x, y, z;
    float vy;
}Player;

// �Լ� ����
Player movePlayer(Player, Keys);
