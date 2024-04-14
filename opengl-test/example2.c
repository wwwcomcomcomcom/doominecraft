#include <GL/glut.h>

typedef struct
{
    int w, s, a, d;           //move up, down, left, right
    int sl, sr;             //strafe left, right 
    int m;                 //move up, down, look up, down
}keys; keys K;

void movePlayer()
{
    //move up, down, left, right
    if (K.a == 1 && K.m == 0) { printf("left\n"); }
    if (K.d == 1 && K.m == 0) { printf("right\n"); }
    if (K.w == 1 && K.m == 0) { printf("up\n"); }
    if (K.s == 1 && K.m == 0) { printf("down\n"); }
    //strafe left, right
    if (K.sr == 1) { printf("strafe left\n"); }
    if (K.sl == 1) { printf("strafe right\n"); }
    //move up, down, look up, look down
    if (K.a == 1 && K.m == 1) { printf("look up\n"); }
    if (K.d == 1 && K.m == 1) { printf("look down\n"); }
    if (K.w == 1 && K.m == 1) { printf("move up\n"); }
    if (K.s == 1 && K.m == 1) { printf("move down\n"); }
}
void KeysDown(unsigned char key, int x, int y)
{
    if (key == 'w' == 1) { K.w = 1; }
    if (key == 's' == 1) { K.s = 1; }
    if (key == 'a' == 1) { K.a = 1; }
    if (key == 'd' == 1) { K.d = 1; }
    if (key == 'm' == 1) { K.m = 1; }
    if (key == ',' == 1) { K.sr = 1; }
    if (key == '.' == 1) { K.sl = 1; }
}
void KeysUp(unsigned char key, int x, int y)
{
    if (key == 'w' == 1) { K.w = 0; }
    if (key == 's' == 1) { K.s = 0; }
    if (key == 'a' == 1) { K.a = 0; }
    if (key == 'd' == 1) { K.d = 0; }
    if (key == 'm' == 1) { K.m = 0; }
    if (key == ',' == 1) { K.sr = 0; }
    if (key == '.' == 1) { K.sl = 0; }
}

void display() {
    movePlayer();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(3.0f, 3.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

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
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w / (float)h, 1.0, 10.0);
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
    glutKeyboardFunc(KeysDown);
    glutKeyboardUpFunc(KeysUp);
    glutMainLoop();
    return 0;
}
