/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Texture2D.h"
#include "SpriteRenderer.h"
#include "TileMap.cpp"


enum SpriteAction
{
    RUN,
    ATTACK
};

// Container object for holding all state relevant for a single
// game object entity. Each object in the game likely needs the
// minimal of state as described within GameObject.
class GameObject
{
public:
    // Object state
    glm::vec2   Size, Velocity;
    glm::vec3   Color, Position;
    GLfloat     Rotation;
    GLboolean   IsSolid;
    GLboolean   Destroyed;
    GLfloat     velocity = 400.0f;
    // Render state
    Texture2D   Sprite;

    GLint Frames;
    GLint CurrentFrame;
    int Vida;
    int row;
    int column;
    GLfloat offsetx;
    GLfloat offsety;

    int matrixOffsetX;
    int matrixOffsetY;

    GLfloat framewidht;
    SpriteAction CurrentAction;

    void Attack();
    void NextFrame();
    void MoveLeft(GLfloat dt, TileMap *tileMap);
    void MoveRight(GLfloat dt, TileMap *tileMap);
    void MoveUp(GLfloat dt, TileMap *tileMap);
    void MoveDown(GLfloat dt, TileMap *tileMap);
    void ScaleUp    (GLfloat dt);
    void ScaleDown  (GLfloat dt);

    void ProcessFrame();


    // Constructor(s)
    GameObject();
    GameObject(glm::vec3 pos, glm::vec2 size, Texture2D sprite, GLint Frames = 1, glm::vec3 color = glm::vec3(1.0f), glm::vec2 velocity = glm::vec2(0.0f, 0.0f));

    // Draw sprite
    virtual void Draw(SpriteRenderer &renderer);

    void updatePositionBasedOnMatrix();

    bool CheckIfValid(int column, int row, TileMap *tileMap);
};

#endif