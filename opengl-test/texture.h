#pragma once
#include <GL/glut.h>
GLuint grassTexture;
GLuint stoneTexture;
GLuint cobbleStoneTexture;
GLuint plankTexture;

void initTextures();
void loadTexture(const char*, GLuint*);
GLuint getTexture(char);