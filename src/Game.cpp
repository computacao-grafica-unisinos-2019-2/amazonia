/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#include "Game.h"
#include "ResourceManager.h"
#include "SpriteRenderer.h"
#include "GameObject.h"


// Game-related State data
SpriteRenderer  *Renderer;
GameObject      *Player;


Game::Game(GLuint width, GLuint height)
        : State(GAME_ACTIVE), Keys(), Width(width), Height(height)
{

}

Game::~Game()
{
    delete Renderer;
    delete Player;
}

void Game::Init()
{
    // Load shaders
    ResourceManager::LoadShader("resources/shaders/sprite/sprites.vert", "resources/shaders/sprite/sprites.frag", nullptr, "sprite");

    // Configure shaders
    glm::mat4 projection = glm::ortho(0.0f, static_cast<GLfloat>(this->Width), static_cast<GLfloat>(this->Height), 0.0f, -1.0f, 1.0f);
    ResourceManager::GetShader("sprite").Use().SetInteger("sprite", 0);
    ResourceManager::GetShader("sprite").SetMatrix4("projection", projection);

    // Load textures
    ResourceManager::LoadTexture("resources/textures/sprites/elf.png", GL_TRUE,"elf");
    ResourceManager::LoadTexture("resources/textures/background.png", GL_FALSE,"forest");

    // Set render-specific controls
    Shader shader = ResourceManager::GetShader("sprite");
    Renderer = new SpriteRenderer(shader);

    Texture2D elfSprite = ResourceManager::GetTexture("elf");
    Player = new GameObject(glm::vec2(50, 340), glm::vec2(150, 200), elfSprite);
}

void Game::Update(GLfloat dt)
{

}


void Game::ProcessInput(GLfloat dt)
{
    if (this->State == GAME_ACTIVE)
    {
        GLfloat velocity = 500.0f * dt;
        // Move playerboard
        if (this->Keys[GLFW_KEY_A])
        {
            if (Player->Position.x >= 0)
                Player->Position.x -= velocity;
        }
        if (this->Keys[GLFW_KEY_D])
        {
            if (Player->Position.x <= this->Width - Player->Size.x)
                Player->Position.x += velocity;
        }
    }
}

void Game::Render()
{

    if (this->State == GAME_ACTIVE)
    {
        // Draw background
        Texture2D forestTexture = ResourceManager::GetTexture("forest");
        Renderer->DrawSprite(forestTexture, glm::vec2(0, 0), glm::vec2(this->Width, this->Height), 0.0f);
        // Draw level
        //this->Levels[this->Level].Draw(*Renderer);
        // Draw player
        Player->Draw(*Renderer);
    }
    //Texture2D faceTexture = ResourceManager::GetTexture("face");
   // Renderer->DrawSprite(faceTexture, glm::vec2(50, 400), glm::vec2(150, 200), 0.0f, glm::vec3(1.0f, 1.0f, 1.0f));
}