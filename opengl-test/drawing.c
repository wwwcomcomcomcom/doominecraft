#include <GL/glut.h>
#include <GL/GL.h>
#include "drawing.h"
#include "block.h"
#include "texture.h"

void cube(int x, int y, int z,GLuint texture) {
    // Draw a colored cube
    glBindTexture(GL_TEXTURE_2D, texture);
    glBegin(GL_QUADS);
    // Front face
    //glColor3f(1.0f, 0.0f, 0.0f);
    glTexCoord2f(0.0, 0.0); glVertex3f(x - Size, y + -Size, z + Size);
    glTexCoord2f(1.0, 0.0); glVertex3f(x + Size, y + -Size, z + Size);
    glTexCoord2f(1.0, 1.0); glVertex3f(x + Size, y + Size, z + Size);
    glTexCoord2f(0.0, 1.0); glVertex3f(x + -Size, y + Size, z + Size);

    // Back face
    //glColor3f(0.0f, 1.0f, 0.0f);
    glTexCoord2f(1.0, 0.0); glVertex3f(x - Size, y + -Size, z + -Size);
    glTexCoord2f(1.0, 1.0); glVertex3f(x + -Size, y + Size, z + -Size);
    glTexCoord2f(0.0, 1.0); glVertex3f(x + Size, y + Size, z + -Size);
    glTexCoord2f(0.0, 0.0); glVertex3f(x + Size, y + -Size, z + -Size);

    // Top face
    //glColor3f(0.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0, 1.0); glVertex3f(x + -Size, y + Size, z + -Size);
    glTexCoord2f(0.0, 0.0); glVertex3f(x + -Size, y + Size, z + Size);
    glTexCoord2f(1.0, 0.0); glVertex3f(x + Size, y + Size, z + Size);
    glTexCoord2f(1.0, 1.0); glVertex3f(x + Size, y + Size, z + -Size);

    // Bottom face
    //glColor3f(1.0f, 1.0f, 0.0f);
    glTexCoord2f(1.0, 1.0); glVertex3f(x + -Size, y + -Size, z + -Size);
    glTexCoord2f(0.0, 1.0); glVertex3f(x + Size, y + -Size, z + -Size);
    glTexCoord2f(0.0, 0.0); glVertex3f(x + Size, y + -Size, z + Size);
    glTexCoord2f(1.0, 0.0); glVertex3f(x + -Size, y + -Size, z + Size);

    // Right face
    //glColor3f(1.0f, 0.0f, 1.0f);
    glTexCoord2f(1.0, 0.0); glVertex3f(x + Size, y + -Size, z + -Size);
    glTexCoord2f(1.0, 1.0); glVertex3f(x + Size, y + Size, z + -Size);
    glTexCoord2f(0.0, 1.0); glVertex3f(x + Size, y + Size, z + Size);
    glTexCoord2f(0.0, 0.0); glVertex3f(x + Size, y + -Size, z + Size);

    // Left face
    //glColor3f(0.0f, 1.0f, 1.0f);
    glTexCoord2f(0.0, 0.0); glVertex3f(x + -Size, y + -Size, z + -Size);
    glTexCoord2f(1.0, 0.0); glVertex3f(x + -Size, y + -Size, z + Size);
    glTexCoord2f(1.0, 1.0); glVertex3f(x + -Size, y + Size, z + Size);
    glTexCoord2f(0.0, 1.0); glVertex3f(x + -Size, y + Size, z + -Size);

    glEnd();
}
void cubeWithBorder(int x, int y, int z,GLuint texture) {

    cube(x, y, z,texture);
    // Draw cube edges as lines to create a border effect
    //glLineWidth(3.0f);
    //glBegin(GL_LINES);
    //glColor3f(0.0f, 0.0f, 0.0f); // Border color (black in this case)

    //// Front face border
    //glVertex3f(x - Size, y - Size, z + Size);
    //glVertex3f(x + Size, y - Size, z + Size);

    //glVertex3f(x + Size, y - Size, z + Size);
    //glVertex3f(x + Size, y + Size, z + Size);

    //glVertex3f(x + Size, y + Size, z + Size);
    //glVertex3f(x - Size, y + Size, z + Size);

    //glVertex3f(x - Size, y + Size, z + Size);
    //glVertex3f(x - Size, y - Size, z + Size);

    //// Back face border
    //glVertex3f(x - Size, y - Size, z - Size);
    //glVertex3f(x + Size, y - Size, z - Size);

    //glVertex3f(x + Size, y - Size, z - Size);
    //glVertex3f(x + Size, y + Size, z - Size);

    //glVertex3f(x + Size, y + Size, z - Size);
    //glVertex3f(x - Size, y + Size, z - Size);

    //glVertex3f(x - Size, y + Size, z - Size);
    //glVertex3f(x - Size, y - Size, z - Size);

    //// Connecting lines between front and back faces
    //glVertex3f(x - Size, y - Size, z + Size);
    //glVertex3f(x - Size, y - Size, z - Size);

    //glVertex3f(x + Size, y - Size, z + Size);
    //glVertex3f(x + Size, y - Size, z - Size);

    //glVertex3f(x + Size, y + Size, z + Size);
    //glVertex3f(x + Size, y + Size, z - Size);

    //glVertex3f(x - Size, y + Size, z + Size);
    //glVertex3f(x - Size, y + Size, z - Size);

    //glEnd();
}