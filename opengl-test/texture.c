#include <GL/glut.h>
#include <soil.h>
#include "texture.h"

void initTextures() {
    loadTexture("img/grass.png",&grassTexture);
    loadTexture("img/stone.png", &stoneTexture);
    loadTexture("img/cobblestone.png", &cobbleStoneTexture);
    loadTexture("img/plank.png", &plankTexture);
}

void loadTexture(const char* filename,GLuint* target ) {
    *target = SOIL_load_OGL_texture(
        filename,
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT
    );
    if (*target == 0) {
        printf("SOIL loading error: '%s'\n", SOIL_last_result());
    }

    glBindTexture(GL_TEXTURE_2D, *target);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

GLuint getTexture(char textureSet) {
    switch (textureSet)
    {
    case 0:
        return grassTexture;
    case 1:
        return stoneTexture;
    case 2:
        return cobbleStoneTexture;
    case 3:
        return plankTexture;
    default:
        return grassTexture;
    }
}