#pragma once
#include "controller.h"


// 구조체 선언
typedef struct
{
    float rotationX, rotationY;
    float x, y, z;
    float vy;
}Player;

// 함수 선언
Player movePlayer(Player, Keys);
