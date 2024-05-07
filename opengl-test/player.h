#pragma once
#include "controller.h"
#include "block.h"
#include "stdbool.h"
#define playerWidth 1.0f
#define playerHeight 1.9f
#define playerHalfWidth playerWidth/2
#define playerHalfHeight playerHeight/2
#include "vec3.h"

// 구조체 선언
typedef struct
{
    float rotationX, rotationY;
    float x, y, z;
    float vy;
    bool onGround;
}Player;

static Player P;

// 함수 선언
Player movePlayer(Player, Keys,Block*);
Vec3 getPlayerPos(Player P);
