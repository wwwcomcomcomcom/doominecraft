#pragma once
#include <GL/glut.h>
#include <stdio.h>
#include "math.h"
#include "player.h"
#include "controller.h"

#define PI 3.1415926535

Player movePlayer(Player P,Keys K)
{
    if (P.y == 0 && K.space) {
        P.vy = 2;
    }

    float dx = -sin(P.rotationY * PI / 180) * 0.5;
    float dy = cos(P.rotationY * PI / 180) * 0.5;
    //wasd
    if (K.w == 1) { P.x += dx; P.z += dy; }
    if (K.s == 1) { P.x -= dx; P.z -= dy; }

    if (K.a == 1) { P.x += dy; P.z -= dx; }
    if (K.d == 1) { P.x -= dy; P.z += dx; }


    P.y += P.vy * 0.2;
    if (P.y < 0) {
        P.y = 0;
        P.vy = 0;
    }
    else {
        P.vy -= 0.2;
    }

    glLoadIdentity();
    glRotatef(P.rotationX, 1.0f, 0.0f, 0.0f);
    glRotatef(P.rotationY, 0.0f, 1.0f, 0.0f);
    glTranslatef(P.x, -P.y, P.z);
    return P;
}