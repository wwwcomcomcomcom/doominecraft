#include <GL/glut.h>
#include <soil.h>
#include "drawing.h"
#include "block.h"

GLuint texture;

void initTextures() {
    loadTexture("grass.png");
}

void loadTexture(const char* filename) {
    texture = SOIL_load_OGL_texture(
        filename,
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
    if (texture == 0) {
        printf("SOIL loading error: '%s'\n", SOIL_last_result());
    }

    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

void cube(int x, int y, int z) {
    // Draw a colored cube
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
void cubeWithBorder(int x, int y, int z) {

    cube(x, y, z);
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