#include <GL/glut.h>
#include <GL/GL.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "block.h"
#include "player.h"
#include "controller.h"
#include "drawing.h"
#include "collide.h"
#include "targetting.h"
#include "texture.h"
#define PI 3.1415926535
//#define gravity 0.2f

int width, height;
bool toggleMouseLock = true;

//Player P;
Keys K;


//int blockLength = 0;
//Block blocks[1000];

typedef struct
{
    int time1, time2;
}time; time Time;

void KeysDown(unsigned char key, int x, int y)
{
    if (key == 'w') { K.w = 1; }
    if (key == 's') { K.s = 1; }
    if (key == 'a') { K.a = 1; }
    if (key == 'd') { K.d = 1; }
    if (key == ' ') { K.space = 1; }
    if (key == 'q') interactBlock(false);
    if (key == 'e') interactBlock(true);
    if (key == '1') P.selectedBlock = 0;
    if (key == '2') P.selectedBlock = 1;
    if (key == '3') P.selectedBlock = 2;
    if (key == '4') P.selectedBlock = 3;
    //esc
    if (key == 27) { toggleMouseLock = !toggleMouseLock; }
}
void KeysUp(unsigned char key, int x, int y)
{
    if (key == 'w') { K.w = 0; }
    if (key == 's') { K.s = 0; }
    if (key == 'a') { K.a = 0; }
    if (key == 'd') { K.d = 0; }
    if (key == ' ') { K.space = 0; }
}

void mouse(int x, int y) {
    if (toggleMouseLock) {
        int aW = width / 2, aH = height / 2;
        float deltaX = (x - aW) * 0.1;
        float deltaY = (y - aH) * 0.1;
        glutSetCursor(GLUT_CURSOR_NONE);
        glutWarpPointer(aW, aH);
        P.rotationX += deltaY * 0.5f;
        P.rotationY += deltaX * 0.5f;
    }else {
        glutSetCursor(GLUT_CURSOR_INHERIT);
    }
}

void display() {
    glLoadIdentity();
    if (Time.time1 - Time.time2 >= 50) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        P = movePlayer(P,K,blocks);
        for (int i = 0; i < blockLength; i++) {
            cubeWithBorder(
                blocks[i].x,
                blocks[i].y,
                blocks[i].z,
                getTexture(blocks[i].textureSet)
            );
        }
        Time.time2 = Time.time1;
        glutSwapBuffers();
    }
    Time.time1 = glutGet(GLUT_ELAPSED_TIME);
    glutPostRedisplay();
}


void init()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    initTextures();
    blockLength = 0;
    //init player
    P.x = 0; P.y = 0; P.z = 0;
    P.rotationX = 0.0f; P.rotationY = 0;
    P.onGround = true;
    P.selectedBlock = 1;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            addBlock(i - 2, 0, j - 2,0);
        }
    }
    addBlock(2, 1, 2,1);
    addBlock(1, 1, 1,1);
    addBlock(2, 1, 1,1);
}

void reshape(int w, int h) {
    width = w;
    height = h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1200, 650);
    glutCreateWindow("OpenGL Cube");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(mouse); // Use glutPassiveMotionFunc for mouse movement without clicking
    glutKeyboardFunc(KeysDown);
    glutKeyboardUpFunc(KeysUp);
    glutMainLoop();
    return 0;
}
