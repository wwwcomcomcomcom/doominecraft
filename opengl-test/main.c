#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "player.h"
#include "controller.h"
#include "drawing.h"
#define PI 3.1415926535
//#define gravity 0.2f

int width, height;
bool toggleMouseLock = true;

Player P;
Keys K;

typedef struct
{
    int x, y, z;
}Block;
int blockLength = 0;
Block blocks[1000];

typedef struct
{
    int time1, time2;
}time; time Time;

typedef struct
{
    float maxX, minX, maxY, minY, maxZ, minZ;
}AABB;
void KeysDown(unsigned char key, int x, int y)
{
    if (key == 'w') { K.w = 1; }
    if (key == 's') { K.s = 1; }
    if (key == 'a') { K.a = 1; }
    if (key == 'd') { K.d = 1; }
    if (key == ' ') { K.space = 1; }
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

    if (Time.time1 - Time.time2 >= 50) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        P = movePlayer(P,K);
        for (int i = 0; i < blockLength; i++) {
            cubeWithBorder(
                blocks[i].x,
                blocks[i].y,
                blocks[i].z
            );
        }
        Time.time2 = Time.time1;
        glutSwapBuffers();
    }
    Time.time1 = glutGet(GLUT_ELAPSED_TIME);
    glutPostRedisplay();
}

AABB getAABB(Block block) {
    AABB aabb;
    aabb.maxX = block.x + Size;
    aabb.minX = block.x - Size;
    aabb.maxY = block.y + Size;
    aabb.minY = block.y - Size;
    aabb.maxZ = block.z + Size;
    aabb.minZ = block.z - Size;
    return aabb;
}
bool isCollide(AABB obj1,AABB obj2) {
    if (
        obj1.maxX > obj2.minX
        && obj2.maxX > obj1.minX
        && obj1.maxY > obj2.minY
        && obj2.maxY > obj1.minY
        && obj1.maxZ > obj2.minZ
        && obj2.maxZ > obj1.minZ
        ) return true;
    else return false;
}

Block makeBlock(int x,int y,int z) {
    Block result;
    result.x = x;
    result.y = y;
    result.z = z;
    return result;
}
void addBlock(int x,int y,int z) {
    blocks[blockLength] = makeBlock(x,y,z);
    blockLength++;
}

void init()
{
    //init player
    P.x = 0; P.y = 0; P.z = 0;
    P.rotationX = 0.0f; P.rotationY = 0;
    //P.isJumping = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            addBlock(i - 2, 0, j - 2);
        }
    }
    addBlock(2, 1, 2);
}

void reshape(int w, int h) {
    width = w;
    height = h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Cube");
    glEnable(GL_DEPTH_TEST);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(mouse); // Use glutPassiveMotionFunc for mouse movement without clicking
    glutKeyboardFunc(KeysDown);
    glutKeyboardUpFunc(KeysUp);
    glutMainLoop();
    return 0;
}
