#include <GL/glut.h>
#include "drawing.h"

void cube(int x, int y, int z) {

    // Draw a colored cube
    glBegin(GL_QUADS);
    // Front face
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(x - Size, y + -Size, z + Size);
    glVertex3f(x + Size, y + -Size, z + Size);
    glVertex3f(x + Size, y + Size, z + Size);
    glVertex3f(x + -Size, y + Size, z + Size);

    // Back face
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f(x - Size, y + -Size, z + -Size);
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