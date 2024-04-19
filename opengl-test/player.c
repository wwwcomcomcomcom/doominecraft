#pragma once
#include <GL/glut.h>
#include <stdio.h>
#include "block.h"
#include "math.h"
#include "player.h"
#include "controller.h"
#include "collide.h"

#define PI 3.1415926535
#define Speed 0.3

Player movePlayer(Player P,Keys K,Block* blocks)
{
    float tempX = P.x, tempY = P.y, tempZ = P.z;
    if (P.onGround && K.space) {
        P.vy = 3;
    }

    float dx = -sin(P.rotationY * PI / 180) * Speed;
    float dy = cos(P.rotationY * PI / 180) * Speed;
    //wasd
    if (K.s == 1) { P.x += dx; P.z += dy; }
    if (K.w == 1) { P.x -= dx; P.z -= dy; }

    if (K.d == 1) { P.x += dy; P.z -= dx; }
    if (K.a == 1) { P.x -= dy; P.z += dx; }


    P.y += P.vy * 0.2;
    if (P.y < 0) {
        P.y = 0;
        P.vy =0;
        P.onGround = true;
    }
    //if (P.onGround) P.vy = 0;
    /*else if(!P.onGround){
        P.vy -= 0.2;
    }*/
    /*else if(P.vy < -0.01) {
        P.vy = -0.01;
    }*/
    P.vy -= 0.2;
    printf("qwer2\n");
    P.onGround = false;
    for (int i = 0; i < blockLength; i++) {
        Vec3 collideOffeset = isCollide(getPlayerAABB(P), getBlockAABB(blocks[i]));
        if (!equalsVec3(collideOffeset, ORIGIN)) {
            P.x += collideOffeset.x;
            P.y += collideOffeset.y;
            P.z += collideOffeset.z;
        }
        if (collideOffeset.y > 0.0f) {
            P.onGround = true;
            P.vy = 0;
            printf("asdf");
        }
        /*else {
            P.onGround = false;
            printf("asdf2");
        }*/
    }
    if (P.y == 0) P.onGround = true;
    if (P.vy > 0) P.onGround = false;

    printf("%f %d\n",P.vy,P.onGround );

    glLoadIdentity();
    glRotatef(P.rotationX, 1.0f, 0.0f, 0.0f);
    glRotatef(P.rotationY, 0.0f, 1.0f, 0.0f);
    glTranslatef(-P.x, -(P.y + 1), -P.z);
    return P;
}