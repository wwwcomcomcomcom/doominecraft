#pragma once
#include <GL/glut.h>

GLuint texture;

void initTextures();
void loadTexture(const char*);
void cube(int, int, int);
void cubeWithBorder(int, int, int);