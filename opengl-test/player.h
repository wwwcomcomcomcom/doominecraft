#pragma once
#include "controller.h"
#include "block.h"
#include "stdbool.h"
#define playerWidth 1.0f
#define playerHeight 1.9f
#define playerHalfWidth playerWidth/2
#define playerHalfHeight playerHeight/2
#include "vec3.h"
/* ���� foo. */
#ifndef FILE_FOO_SEEN
#define FILE_FOO_SEEN

typedef struct
{
    float rotationX, rotationY;
    float x, y, z;
    float vy;
    bool onGround;
}Player;

Player P;

// �Լ� ����
Player movePlayer(Player, Keys, Block*);
Vec3 getPlayerPos(Player P);


#endif /* !FILE_FOO_SEEN */
// ����ü ����
