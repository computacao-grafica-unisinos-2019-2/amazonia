/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#include <iostream>
#include "Game.h"
#include "ResourceManager.h"
#include "SpriteRenderer.h"
#include "GameObject.h"
#include "GameConfig.cpp"

// Game-related State data
SpriteRenderer  *Renderer;
GameObject      *Player;
GameObject      *NPC;
GLfloat         offset = 0.0f;


Game::Game(GLuint width, GLuint height)
        : State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{

}

Game::~Game()
{
    delete Renderer;
    delete Player;
    delete NPC;
}

void Game::Init()
{
    // Load shaders
    ResourceManager::LoadShader("resources/shaders/sprite/sprite.vert", "resources/shaders/sprite/sprite.frag", nullptr, "sprite");

    // Configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->Width), static_cast<GLfloat>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("sprite", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);
    // Load textures
    ResourceManager::LoadTexture("resources/textures/sprites/run.png", GL_TRUE,"elf");
    ResourceManager::LoadTexture("resources/textures/sprites/orc.png",GL_TRUE, "orc");
    ResourceManager::LoadTexture("resources/textures/background.png", GL_FALSE,"forest");

    // Set render-specific controls
    Shader shader = ResourceManager::GetShader("sprite");
    Renderer = new SpriteRenderer(shader);

    Texture2D elfSprite = ResourceManager::GetTexture("elf");
    Texture2D orcSprite = ResourceManager::GetTexture("orc");
    Texture2D forest = ResourceManager::GetTexture("forest");

    forest.offset = 0.0f;

    Player = new GameObject(glm::vec2(50, 340), glm::vec2(150, 200), elfSprite, 5);
    NPC = new GameObject(glm::vec2(800, 340), glm::vec2(150, 200), orcSprite);

}

void Game::Update(GLfloat dt)
{

}


void Game::ProcessInput(GLfloat dt)
{

    if (this->State == GAME_ACTIVE)
    {
        // Move playerboard
        if (this->Keys[GLFW_KEY_A])
        {
            Player->MoveLeft(dt);
        }
        if (this->Keys[GLFW_KEY_D])
        {
            Player->MoveRight(dt);
        }
        if (this->Keys[GLFW_KEY_W])
        {
            Player->MoveUp(dt);
        }

        if (this->Keys[GLFW_KEY_S])
        {
            Player->MoveDown(dt);
        }

        if(GameConfig::MOVE_BG <= Player->Position.x){
            offset = offset +  0.0001f;
        }

        ProcessNPC(dt);
    }
}

void Game::Render()
{

    if (this->State == GAME_ACTIVE)
    {
        Texture2D forestTexture = ResourceManager::GetTexture("forest");
        // Draw background
        Renderer->DrawSprite(forestTexture, glm::vec2(0, 0), glm::vec2(this->Width, this->Height), 0.0f,glm::vec3(1.0f), offset);
        // Draw level
        //this->Levels[this->Level].Draw(*Renderer);
        // Draw player
        Player->Draw(*Renderer);
        NPC->Draw(*Renderer);
    }
}

void Game::ProcessNPC(GLfloat dt) {


    NPC->MoveLeft(dt);

}
