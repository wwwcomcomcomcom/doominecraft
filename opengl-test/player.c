#pragma once
#include <GL/glut.h>
#include <stdio.h>
#include "block.h"
#include "math.h"
#include "player.h"
#include "controller.h"
#include "collide.h"
#include "vec3.h"

#define PI 3.1415926535
#define Speed 0.3

Player movePlayer(Player P,Keys K,Block* blocks)
{
    float tempX = P.x, tempY = P.y, tempZ = P.z;
    if (P.onGround && K.space) {
        P.vy = 3;
    }

    Vec3 facingVector = getVectorWithRotation(P.rotationX, P.rotationY);
    facingVector = multiplyVec3(facingVector, Speed);
    
    //wasd
    if (K.s == 1) { P.x += facingVector.x; P.z += facingVector.z; }
    if (K.w == 1) { P.x -= facingVector.x; P.z -= facingVector.z; }

    if (K.d == 1) { P.x += facingVector.z; P.z -= facingVector.x; }
    if (K.a == 1) { P.x -= facingVector.z; P.z += facingVector.x; }


    P.y += P.vy * 0.2;
    if (P.y < 0) {
        P.y = 0;
        P.vy =0;
        P.onGround = true;
    }
    
    P.vy -= 0.2;
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
        }

    }
    if (P.y == 0) P.onGround = true;
    if (P.vy > 0) P.onGround = false;

    glLoadIdentity();
    glRotatef(P.rotationX, 1.0f, 0.0f, 0.0f);
    glRotatef(P.rotationY, 0.0f, 1.0f, 0.0f);
    glTranslatef(-P.x, -(P.y + 1), -P.z);
    return P;
}
Vec3 getPlayerPos(Player P) {
    static Vec3 result;
    result.x = P.x;
    result.y = P.y;
    result.z = P.z;
    return result;
}