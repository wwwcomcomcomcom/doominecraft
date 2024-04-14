#include <GL/glut.h>
#include <stdio.h>

#define PI 3.1415926535

int lastX, lastY;
float rotationX = 0, rotationY = PI/2;
float cameraX = 0.0f, cameraY = 0.0f, cameraZ = 5.0f;

typedef struct
{
    int w, s, a, d;           //wasd
}keys; keys K;

typedef struct
{
    int time1, time2;
}time; time Time;

void movePlayer()
{
    //move up, down, left, right
    if (K.a == 1) { cameraX -= 0.5f; }
    if (K.d == 1) { cameraX += 0.5f; }
    if (K.w == 1) { cameraZ -= 0.5f; }
    if (K.s == 1) { cameraZ += 0.5f; }
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
    int deltaX = x - lastX;
    int deltaY = y - lastY;
    lastX = x;
    lastY = y;

    rotationX += deltaY * 0.2f;
    rotationY += deltaX * 0.2f;
}

int tick = 0;

void cube() {
    tick++;
    glLoadIdentity();
    glRotatef(-rotationX, 1.0f, 0.0f, 0.0f);
    glRotatef(-rotationY, 0.0f, 1.0f, 0.0f);
    glTranslatef(-cameraX, -cameraY, -cameraZ);

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

void reshape(int w, int h) {
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
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(mouse); // Use glutPassiveMotionFunc for mouse movement without clicking
    glutKeyboardFunc(KeysDown);
    glutKeyboardUpFunc(KeysUp);
    lastX = 250;
    lastY = 250;
    glutMainLoop();
    return 0;
}
