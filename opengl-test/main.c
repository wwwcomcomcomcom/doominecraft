#include <GL/glut.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define PI 3.1415926535
#define Size 0.5f
//#define gravity 0.2f

int width, height;
bool toggleMouseLock = true;

typedef struct
{
    float rotationX, rotationY;
    float x, y, z;
    bool isJumping;
    float vy;
}player; player P;

typedef struct
{
    int x, y, z;
}block;
int blockLength = 0;
block blocks[1000];

typedef struct
{
    int w, s, a, d,space;           //wasd
}keys; keys K;

typedef struct
{
    int time1, time2;
}time; time Time;

void movePlayer()
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

    
    P.y += P.vy*0.2;
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
    glTranslatef(P.x,-P.y, P.z);
}
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

void cube(int x, int y, int z) {

    // Draw a colored cube
    glBegin(GL_QUADS);
    // Front face
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(x-Size,y + -Size, z + Size);
    glVertex3f(x+Size, y + -Size, z + Size);
    glVertex3f(x + Size, y + Size, z + Size);
    glVertex3f(x + -Size, y + Size, z + Size);

    // Back face
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(x -Size,y + -Size, z + -Size);
    glVertex3f(x + -Size, y + Size, z + -Size);
    glVertex3f(x + Size, y + Size, z + -Size);
    glVertex3f(x + Size, y + -Size, z + -Size);

    // Top face
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(x + -Size, y + Size, z + -Size);
    glVertex3f(x + -Size, y + Size, z + Size);
    glVertex3f(x + Size, y + Size, z + Size);
    glVertex3f(x + Size, y + Size, z + -Size);

    // Bottom face
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(x + -Size, y + -Size, z + -Size);
    glVertex3f(x + Size, y + -Size, z + -Size);
    glVertex3f(x + Size, y + -Size, z + Size);
    glVertex3f(x + -Size, y + -Size, z + Size);

    // Right face
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(x + Size, y + -Size, z + -Size);
    glVertex3f(x + Size, y + Size, z + -Size);
    glVertex3f(x + Size, y + Size, z + Size);
    glVertex3f(x + Size, y + -Size, z + Size);

    // Left face
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(x + -Size, y + -Size, z + -Size);
    glVertex3f(x + -Size, y + -Size, z + Size);
    glVertex3f(x + -Size, y + Size, z + Size);
    glVertex3f(x + -Size, y + Size, z + -Size);

    glEnd();
}
void cubeWithBorder(int x, int y, int z) {
    y -= Size + 1.5;

    cube(x, y, z);
    // Draw cube edges as lines to create a border effect
    glLineWidth(3.0f);
    glBegin(GL_LINES);
    glColor3f(0.0f, 0.0f, 0.0f); // Border color (black in this case)

    // Front face border
    glVertex3f(x - Size, y - Size, z + Size);
    glVertex3f(x + Size, y - Size, z + Size);

    glVertex3f(x + Size, y - Size, z + Size);
    glVertex3f(x + Size, y + Size, z + Size);

    glVertex3f(x + Size, y + Size, z + Size);
    glVertex3f(x - Size, y + Size, z + Size);

    glVertex3f(x - Size, y + Size, z + Size);
    glVertex3f(x - Size, y - Size, z + Size);

    // Back face border
    glVertex3f(x - Size, y - Size, z - Size);
    glVertex3f(x + Size, y - Size, z - Size);

    glVertex3f(x + Size, y - Size, z - Size);
    glVertex3f(x + Size, y + Size, z - Size);

    glVertex3f(x + Size, y + Size, z - Size);
    glVertex3f(x - Size, y + Size, z - Size);

    glVertex3f(x - Size, y + Size, z - Size);
    glVertex3f(x - Size, y - Size, z - Size);

    // Connecting lines between front and back faces
    glVertex3f(x - Size, y - Size, z + Size);
    glVertex3f(x - Size, y - Size, z - Size);

    glVertex3f(x + Size, y - Size, z + Size);
    glVertex3f(x + Size, y - Size, z - Size);

    glVertex3f(x + Size, y + Size, z + Size);
    glVertex3f(x + Size, y + Size, z - Size);

    glVertex3f(x - Size, y + Size, z + Size);
    glVertex3f(x - Size, y + Size, z - Size);

    glEnd();
}


void display() {

    if (Time.time1 - Time.time2 >= 50) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        movePlayer();
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

block makeBlock(int x,int y,int z) {
    block result;
    result.x = x;
    result.y = y;
    result.z = z;
    return result;
}

void init()
{
    //init player
    P.x = 0; P.y = 0; P.z = -5;
    P.rotationX = 0.0f; P.rotationY = 0;
    P.isJumping = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            blockLength++;
            blocks[j+i*5] = makeBlock(i - 2, 0, j - 2);
        }
    }
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
