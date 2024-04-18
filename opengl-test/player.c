#pragma once
#include <GL/glut.h>
#include <stdio.h>
#include "math.h"
#include "player.h"
#include "controller.h"
#include "block.h"
#include "collide.h"

#define PI 3.1415926535

Player movePlayer(Player P,Keys K,Block* blocks)
{
    float tempX = P.x, tempY = P.y, tempZ = P.z;
    if (P.y == 0 && K.space) {
        P.vy = 2;
    }

    float dx = -sin(P.rotationY * PI / 180) * 0.5;
    float dy = cos(P.rotationY * PI / 180) * 0.5;
    //wasd
    if (K.s == 1) { P.x += dx; P.z += dy; }
    if (K.w == 1) { P.x -= dx; P.z -= dy; }

    if (K.d == 1) { P.x += dy; P.z -= dx; }
    if (K.a == 1) { P.x -= dy; P.z += dx; }


    P.y += P.vy * 0.2;
    if (P.y < 0) {
        P.y = 0;
        P.vy = 0;
    }
    else {
        P.vy -= 0.2;
    }
    if (isCollide(getBlockAABB(blocks[25]), getPlayerAABB(P))) {
        P.x = tempX;
        P.y = tempY;
        P.z = tempZ;
    }

    glLoadIdentity();
    glRotatef(P.rotationX, 1.0f, 0.0f, 0.0f);
    glRotatef(P.rotationY, 0.0f, 1.0f, 0.0f);
    glTranslatef(-P.x, -(P.y + 2), -P.z);
    return P;
}