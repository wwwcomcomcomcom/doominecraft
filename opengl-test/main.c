#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#define PI 3.1415926535

int width, height;

typedef struct
{
    float rotationX, rotationY;
    float x, y, z;
}player; player P;

typedef struct
{
    int w, s, a, d;           //wasd
}keys; keys K;

typedef struct
{
    int time1, time2;
}time; time Time;

typedef struct
{
    float cos[360];        //Save sin cos in values 0-360 degrees 
    float sin[360];
}math; math M;

void movePlayer()
{
    float dx = -sin(P.rotationY * PI / 180);
    float dy = cos(P.rotationY * PI / 180);
    //wasd
    if (K.w == 1) { P.x += dx; P.z += dy; }
    if (K.s == 1) { P.x -= dx; P.z -= dy; }

    if (K.a == 1) { P.x += dy; P.z -= dx; }
    if (K.d == 1) { P.x -= dy; P.z += dx; }

    glLoadIdentity();
    glRotatef(P.rotationX, 1.0f, 0.0f, 0.0f);
    glRotatef(P.rotationY, 0.0f, 1.0f, 0.0f);
    glTranslatef(P.x, P.y, P.z);
}
void KeysDown(unsigned char key, int x, int y)
{
    if (key == 'w' == 1) { K.w = 1; }
    if (key == 's' == 1) { K.s = 1; }
    if (key == 'a' == 1) { K.a = 1; }
    if (key == 'd' == 1) { K.d = 1; }
}
void KeysUp(unsigned char key, int x, int y)
{
    if (key == 'w' == 1) { K.w = 0; }
    if (key == 's' == 1) { K.s = 0; }
    if (key == 'a' == 1) { K.a = 0; }
    if (key == 'd' == 1) { K.d = 0; }
}

void mouse(int x, int y) {
    int aW = width / 2, aH = height / 2;
    int deltaX = (x -aW) * 0.1;
    int deltaY = (y -aH) * 0.1;

    glutSetCursor(GLUT_CURSOR_NONE);
    glutWarpPointer(aW, aH);

    P.rotationX += deltaY * 0.5f;
    P.rotationY += deltaX * 0.5f;
}

void cube() {
    // Draw a colored cube
    glBegin(GL_QUADS);
    // Front face
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    // Back face
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Top face
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // Bottom face
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // Right face
    glColor3f(1.0f, 0.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Left face
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    glEnd();
}

void display() {

    if (Time.time1 - Time.time2 >= 50) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        movePlayer();

        cube();
        Time.time2 = Time.time1;
        glutSwapBuffers();
    }
    Time.time1 = glutGet(GLUT_ELAPSED_TIME);
    glutPostRedisplay();
}

void init()
{
    //store sin/cos in degrees
    for (int x = 0; x < 360; x++)                         //precalulate sin cos in degrees
    {
        M.cos[x] = cos(x / 180.0 * PI);
        M.sin[x] = sin(x / 180.0 * PI);
    }
    //init player
    P.x = 0; P.y = 0; P.z = -5;
    P.rotationX = 0.0f; P.rotationY = 0;
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
