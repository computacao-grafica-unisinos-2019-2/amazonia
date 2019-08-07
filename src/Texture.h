#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL.h>

#include "AssetManager.h"

class Texture
{
private:
	GLuint textureID;
	GLint textureLocation;
	GLshort textureNum;

public:
	Texture();
	~Texture();

	void Load( char const *path, char const *textureUniformName, GLuint shaderProgram, GLint textureNum );

	GLuint GetTextureId() { return textureID; }
	GLshort GetTextureNum() { return textureNum; }

};

#endif