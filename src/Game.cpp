/*******************************************************************
** This code is part of Breakout.
**
** Breakout is free software: you can redistribute it and/or modify
** it under the terms of the CC BY 4.0 license as published by
** Creative Commons, either version 4 of the License, or (at your
** option) any later version.
******************************************************************/
#include <iostream>
#include <sstream>
#include "Game.h"
#include "ResourceManager.h"
#include "SpriteRenderer.h"
#include "GameObject.h"
#include "GameConfig.cpp"
#include "TextRenderer.h"
#include "TileMap.cpp"
#include "TileMapView.cpp"
#include "TileSet.cpp"


// Game-related State data
SpriteRenderer  *Renderer;
GameObject      *Player;
GameObject      *NPC;
GameObject      *Portal;
GameObject      *Portal2;
GameObject      *Chest1;
GameObject      *Chest2;
GameObject      *Chest3;
GameObject      *Wizard;
GameObject      *Tree1;
GameObject      *Tree2;
GameObject      *Guard1;
GameObject      *Dog1;
GameObject      *Dog2;
GameObject      *Pharao;
GameObject      *Pyramid;
GameObject      *Boulder1;
GameObject      *Boulder2;
GameObject      *Boulder3;
GameObject      *Boulder4;
GameObject      *Boulder5;
GameObject      *Urn1;
GameObject      *Urn2;

GameObject      *Cactus1;
GameObject      *Cactus2;
GameObject      *Cactus3;

GameObject      *BearTrap1;
GameObject      *BearTrap2;

TileSet         *tileSet;
TileMap         *tileMap;
TileMapView     *tileMapView;

int tools;

TextRenderer *Text;

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
    delete Renderer;
    delete Player;
    delete NPC;
    delete Portal;
    delete Portal2;
    delete Chest1;
    delete Wizard;
    delete Tree1;
    delete Tree2;
    delete tileSet;
    delete tileMap;
    delete tileMapView;
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
    ResourceManager::LoadTexture("resources/textures/sprites/indiana.png", GL_TRUE,"indiana");
    ResourceManager::LoadTexture("resources/textures/sprites/tree.png", GL_TRUE,"tree");
    ResourceManager::LoadTexture("resources/textures/sprites/banner.png", GL_TRUE,"banner");
    ResourceManager::LoadTexture("resources/textures/sprites/chest.png", GL_TRUE,"chest");
    ResourceManager::LoadTexture("resources/textures/sprites/portal.png", GL_TRUE,"portal");
    ResourceManager::LoadTexture("resources/textures/sprites/wizard.png", GL_TRUE,"wizard");
    ResourceManager::LoadTexture("resources/textures/sprites/beartrap.png",GL_TRUE, "beartrap");
    ResourceManager::LoadTexture("resources/textures/sprites/alicate.png",GL_TRUE, "alicate");
    ResourceManager::LoadTexture("resources/textures/sprites/glasses.png",GL_TRUE, "glasses");
    ResourceManager::LoadTexture("resources/textures/sprites/axe.png",GL_TRUE, "axe");
    ResourceManager::LoadTexture("resources/textures/sprites/pick.png",GL_TRUE, "pick");
    ResourceManager::LoadTexture("resources/textures/sprites/bp.png",GL_TRUE, "bp");
    ResourceManager::LoadTexture("resources/textures/sprites/shovel.png",GL_TRUE, "shovel");
    ResourceManager::LoadTexture("resources/textures/sprites/guard.png",GL_TRUE, "guard");
    ResourceManager::LoadTexture("resources/textures/sprites/pharao.png",GL_TRUE, "pharao");
    ResourceManager::LoadTexture("resources/textures/sprites/urn.png",GL_TRUE, "urn");
    ResourceManager::LoadTexture("resources/textures/sprites/pyramid.png",GL_TRUE, "pyramid");
    ResourceManager::LoadTexture("resources/textures/sprites/dog.png",GL_TRUE, "dog");
    ResourceManager::LoadTexture("resources/textures/sprites/boulder.png",GL_TRUE, "boulder");
    ResourceManager::LoadTexture("resources/textures/sprites/cactus.png",GL_TRUE, "cactus");
    ResourceManager::LoadTexture("resources/textures/sprites/coins.png",GL_TRUE, "coins");
    ResourceManager::LoadTexture("resources/textures/sprites/bridge.png",GL_TRUE, "bridge");

    // Set render-specific controls
    Shader shader = ResourceManager::GetShader("sprite");
    Renderer = new SpriteRenderer(shader);

   // TileRenderer = new SpriteRenderer(shader);
    tileSet = new TileSet();
    tileSet->texture2D = ResourceManager::LoadTexture("resources/textures/tilemap/terrain.png",GL_TRUE, "terrain");
    tileSet->rows = 12;
    tileSet->columns = 8;
    // 1024 x 768

    tileMap = new TileMap();
    tileMap->rows = 12;
    tileMap->columns = 12;
    tileMapView = new TileMapView();

    Texture2D portalSprite = ResourceManager::GetTexture("portal");
    Texture2D guardSprite = ResourceManager::GetTexture("guard");
    Texture2D indianaSprite = ResourceManager::GetTexture("indiana");
    Texture2D chestSprite = ResourceManager::GetTexture("chest");
    Texture2D wizardSprite = ResourceManager::GetTexture("wizard");
    Texture2D treeSprite = ResourceManager::GetTexture("tree");
    Texture2D bearTrapSprite = ResourceManager::GetTexture("beartrap");
    Texture2D pyramidSprite = ResourceManager::GetTexture("pyramid");
    Texture2D pharaoSprite = ResourceManager::GetTexture("pharao");
    Texture2D urnSprite = ResourceManager::GetTexture("urn");
    Texture2D dogSprite = ResourceManager::GetTexture("dog");
    Texture2D boulderSprite = ResourceManager::GetTexture("boulder");
    Texture2D cactusSprite = ResourceManager::GetTexture("cactus");

    // Player = new GameObject(glm::vec3(50, 340, 0.0), glm::vec2(75, 100), elfSprite, 5);
    Player = new GameObject(glm::vec3(50, 340, 0.0), glm::vec2(50, 80), indianaSprite, 1);
    Player->Vida = 100;
    Player->column=0;
    Player->row=0;

    Portal = new GameObject(glm::vec3(250, 500, 0.0), glm::vec2(128, 64), portalSprite, 1);
    Portal->row = 4;
    Portal->column = 0;
    Portal->matrixOffsetY = 0;
    Portal->matrixOffsetX = 0;
    Portal->Destroyed = true;

    Portal2 = new GameObject(glm::vec3(250, 500, 0.0), glm::vec2(128, 64), portalSprite, 1);
    Portal2->row = 7;
    Portal2->column = 0;
    Portal2->matrixOffsetY = 0;
    Portal2->matrixOffsetX = 0;
    Portal2->Destroyed = true;

    Chest1 = new GameObject(glm::vec3(250, 500, 0.0), glm::vec2(85, 85), chestSprite, 2);
    Chest1->column = 4;
    Chest1->row = 4;

    Chest2 = new GameObject(glm::vec3(250, 500, 0.0), glm::vec2(85, 85), chestSprite, 2);
    Chest2->column = 10;
    Chest2->row = 1;

    Chest3 = new GameObject(glm::vec3(250, 500, 0.0), glm::vec2(85, 85), chestSprite, 2);
    Chest3->column = 11;
    Chest3->row = 4;

    Wizard = new GameObject(glm::vec3(500, 500, 0.0), glm::vec2(80, 160), wizardSprite, 1);
    Wizard->column = 2;
    Wizard->row = 4;
    Wizard->matrixOffsetY = 100;
    Wizard->matrixOffsetX = 10;

    Tree1 = new GameObject(glm::vec3(500, 500, 0.0), glm::vec2(60, 120), treeSprite, 1);
    Tree1->column = 9;
    Tree1->row = 4;
    Tree1->matrixOffsetY = 60;

    Tree2 = new GameObject(glm::vec3(500, 500, 0.0), glm::vec2(60, 120), treeSprite, 1);
    Tree2->column = 9;
    Tree2->row = 3;
    Tree2->matrixOffsetY = 60;

    BearTrap1 = new GameObject(glm::vec3(500, 500, 0.0), glm::vec2(128, 64), bearTrapSprite, 1);
    BearTrap1->column = 6;
    BearTrap1->row = 0;
    BearTrap1->matrixOffsetY = -2;
    BearTrap1->matrixOffsetX = -5;

    BearTrap2 = new GameObject(glm::vec3(500, 500, 0.0), glm::vec2(128, 64), bearTrapSprite, 1);
    BearTrap2->column = 6;
    BearTrap2->row = 1;
    BearTrap2->matrixOffsetY = -2;
    BearTrap2->matrixOffsetX = -5;

    Pyramid = new GameObject(glm::vec3(500, 500, 0.0), glm::vec2(200, 100), pyramidSprite, 1);
    Pyramid->row = 9;
    Pyramid->column = 10;
    Pyramid->matrixOffsetY = 10;
    Pyramid->matrixOffsetX = 0;

    Dog1 = new GameObject(glm::vec3(500, 500, 0.0), glm::vec2(100, 64), dogSprite, 1);
    Dog1->row = 9;
    Dog1->column = 0;
    Dog1->matrixOffsetY = 10;
    Dog1->matrixOffsetX = 15;

    Dog2 = new GameObject(glm::vec3(500, 500, 0.0), glm::vec2(100, 64), dogSprite, 1);
    Dog2->row = 11;
    Dog2->column = 0;
    Dog2->matrixOffsetY = 10;
    Dog2->matrixOffsetX = 15;

    Pharao = new GameObject(glm::vec3(500, 500, 0.0), glm::vec2(120, 175), pharaoSprite, 1);
    Pharao->row = 10;
    Pharao->column = 0;
    Pharao->matrixOffsetY = 110;
    Pharao->matrixOffsetX = 0;

    Guard1 = new GameObject(glm::vec3(500, 500, 0.0), glm::vec2(80, 100), guardSprite, 1);
    Guard1->column = 1;
    Guard1->row = 10;
    Guard1->matrixOffsetY = 45;
    Guard1->matrixOffsetX = 20;

    Boulder1 = new GameObject(glm::vec3(500, 500, 0.0), glm::vec2(80, 80), boulderSprite, 1);
    Boulder1->column = 4;
    Boulder1->row = 7;
    Boulder1->matrixOffsetY = 25;

    Boulder2 = new GameObject(glm::vec3(500, 500, 0.0), glm::vec2(80, 80), boulderSprite, 1);
    Boulder2->column = 4;
    Boulder2->row = 8;
    Boulder2->matrixOffsetY = 25;

    Boulder3 = new GameObject(glm::vec3(500, 500, 0.0), glm::vec2(80, 80), boulderSprite, 1);
    Boulder3->column = 5;
    Boulder3->row = 8;
    Boulder3->matrixOffsetY = 25;

    Boulder4 = new GameObject(glm::vec3(500, 500, 0.0), glm::vec2(80, 80), boulderSprite, 1);
    Boulder4->column = 6;
    Boulder4->row = 8;
    Boulder4->matrixOffsetY = 25;

    Boulder5 = new GameObject(glm::vec3(500, 500, 0.0), glm::vec2(80, 80), boulderSprite, 1);
    Boulder5->column = 6;
    Boulder5->row = 7;
    Boulder5->matrixOffsetY = 25;

    Urn2 = new GameObject(glm::vec3(500, 500, 0.0), glm::vec2(40, 60), urnSprite, 1);
    Urn2->matrixOffsetY = 8;
    Urn2->column = 5;
    Urn2->row = 7;

    Urn1 = new GameObject(glm::vec3(500, 500, 0.0), glm::vec2(40, 60), urnSprite, 1);
    Urn1->matrixOffsetY = 8;
    Urn1->column = 8;
    Urn1->row = 11;

    Cactus1 = new GameObject(glm::vec3(500, 500, 0.0), glm::vec2(60, 100), cactusSprite, 1);
    Cactus1->matrixOffsetY = 40;
    Cactus1->column = 7;
    Cactus1->row = 10;

    Cactus2 = new GameObject(glm::vec3(500, 500, 0.0), glm::vec2(60, 100), cactusSprite, 1);
    Cactus2->matrixOffsetY = 40;
    Cactus2->column = 8;
    Cactus2->row = 10;

    Cactus3 = new GameObject(glm::vec3(500, 500, 0.0), glm::vec2(60, 100), cactusSprite, 1);
    Cactus3->matrixOffsetY = 40;
    Cactus3->column = 7;
    Cactus3->row = 11;

    // Text = new TextRenderer(this->Width, this->Height);
  //  Text->Load("resources/fonts/OCRAEXT.TTF", 24);
}

void Game::Update(GLfloat dt)
{
    if (Player->column == 0 && Player->row == 4 && !Portal->Destroyed){
        Player->row = 7;
    }

}

void Game::ProcessInput(GLfloat dt)
{
    if (this->State == GAME_ACTIVE)
    {
        // Move playerboard
        if (this->Keys[GLFW_KEY_A])
        {
            Player->MoveLeft(dt, tileMap);
        }
        if (this->Keys[GLFW_KEY_D])
        {
            Player->MoveRight(dt, tileMap);
        }
        if (this->Keys[GLFW_KEY_W])
        {
            Player->MoveUp(dt, tileMap);
        }

        if (this->Keys[GLFW_KEY_S])
        {
            Player->MoveDown(dt, tileMap);
        }

        interact();
    }
}

void Game::Render()
{
    if (this->State == GAME_ACTIVE)
    {
       drawTiles();


        Wizard->Draw(*Renderer);

      //  NPC->Draw(*Renderer);
        Portal->Draw(*Renderer);
        Portal2->Draw(*Renderer);
        Chest1->Draw(*Renderer);
        Chest2->Draw(*Renderer);
        Chest3->Draw(*Renderer);

        Pyramid->Draw(*Renderer);
        Dog1->Draw(*Renderer);
        Dog2->Draw(*Renderer);
        Pharao->Draw(*Renderer);
        Guard1->Draw(*Renderer);

        Boulder1->Draw(*Renderer);
        Boulder2->Draw(*Renderer);
        Boulder3->Draw(*Renderer);
        Boulder4->Draw(*Renderer);
        Boulder5->Draw(*Renderer);
        Urn1->Draw(*Renderer);
        Urn2->Draw(*Renderer);

        Cactus1->Draw(*Renderer);
        Cactus2->Draw(*Renderer);
        Cactus3->Draw(*Renderer);


        Tree1->Draw(*Renderer);
        Tree2->Draw(*Renderer);
        BearTrap1->Draw(*Renderer);
        BearTrap2->Draw(*Renderer);

        Texture2D banner = ResourceManager::GetTexture("banner");
        Renderer->DrawSprite(banner, glm::vec3(1100, 100, 0.0), glm::vec2(400, 120), 0.0f, glm::vec3(1.0f));

        renderTools();

        Player->Draw(*Renderer);


        // std::stringstream ss; ss << Player->Vida;
       // Text->RenderText("Vida:"+ ss.str(), 50.0f, 20.0f, 1.0f);
    }
}

void Game::drawTiles() {
    int px, py, tileID = 0;
    GLfloat offsetx, offsety;
    for (int c = 0; c < tileMap->columns; c++) {
        for (int r = 0; r < tileMap->rows; r++) {


            // Gets the tile ID for a given column / row
            tileID = tileMap->getTileId(c,r);

            // Calculates the position of the tile
            tileMapView->calculateTilePosition(px, py, c, r);

            offsetx = (float) tileSet->getColumnForId(tileID) / tileSet->columns;
            offsety = (float) tileSet->getRowForId(tileID) / tileSet->rows;

            Renderer->DrawSprite(tileSet->texture2D,
                    glm::vec3(px, py, -0.9),
                    glm::vec2(tileMapView->tileWidth,tileMapView->tileHeight),
                    0.0f,
                    glm::vec3(1.0f),
                    offsetx,
                    offsety,
                    0.125f,
                    0.0833333f);

            //tile->calculaPosicaoTile(px, py, c, l, tile->getWidth(), tile->getHeight());
            //desenhaTile(tile->getWidth(), tile->getHeight(), px + tile->getX(), py + tile->getY(), c, l);
        }
    }
}

void Game::renderTools() {


    Texture2D bp = ResourceManager::GetTexture("bp");
    Renderer->DrawSprite(bp, glm::vec3(0, 550, 0.0), glm::vec2(200, 275), 0.0f, glm::vec3(1.0f));

    Texture2D alicate = ResourceManager::GetTexture("alicate");
    Texture2D axe = ResourceManager::GetTexture("axe");
    Texture2D shovel = ResourceManager::GetTexture("shovel");
    Texture2D pick = ResourceManager::GetTexture("pick");
    Texture2D glasses = ResourceManager::GetTexture("glasses");
    Texture2D coins = ResourceManager::GetTexture("coins");
    Texture2D bridge = ResourceManager::GetTexture("bridge");

    if (tools > 0){
        Renderer->DrawSprite(alicate, glm::vec3(25, 605, 0.0), glm::vec2(35, 35), 0.0f, glm::vec3(1.0f));
    }

    if (tools > 1) {
        Renderer->DrawSprite(axe, glm::vec3(62, 605, 0.0), glm::vec2(35, 35), 0.0f, glm::vec3(1.0f));
    }

    if (tools > 2) {
        Renderer->DrawSprite(shovel, glm::vec3(100, 605, 0.0), glm::vec2(35, 35), 0.0f, glm::vec3(1.0f));
    }

    if (tools > 3) {
        Renderer->DrawSprite(glasses, glm::vec3(142, 605, 0.0), glm::vec2(35, 35), 0.0f, glm::vec3(1.0f));
    }

    if (tools > 4) {
        Renderer->DrawSprite(pick, glm::vec3(25, 650, 0.0), glm::vec2(35, 35), 0.0f, glm::vec3(1.0f));
    }

    if (tools > 5) {
        Renderer->DrawSprite(coins, glm::vec3(65, 650, 0.0), glm::vec2(35, 35), 0.0f, glm::vec3(1.0f));
    }

    if (tools > 6) {
        Renderer->DrawSprite(bridge, glm::vec3(105, 650, 0.0), glm::vec2(35, 35), 0.0f, glm::vec3(1.0f));
    }

}



void Game::interact() {
   int row1 = Player->row + 1;
   int column1 = Player->column;

   int row2 = Player->row;
   int column2 = Player->column + 1;

    int row3 = Player->row;
    int column3 = Player->column - 1;

    // E key Interactions
    if (this->Keys[GLFW_KEY_E]){
        // chest to find alicate
        if(((row1 == 4 && column1 == 4) || (row2 == 4 && column2 == 4)) && tools == 0){
            Chest1->ProcessFrame();
            tools++;
        }

        // chest to find axe
        if(((row1 == 1 && column1 == 10) || (row2 == 1 && column2 == 10)) && tools == 1){
            Chest2->ProcessFrame();
            tools++;
        }

        // chest to find shovel
        if(((row1 == 4 && column1 == 11) || (row2 == 4 && column2 == 11)) && tools == 2){
            Chest3->ProcessFrame();
            tools++;
        }

        // urn to find pickaxe
        if(((row1 == 11 && column1 == 8) || (row2 == 11 && column2 == 8)) && tools == 4){
            Urn1->Destroyed = true;
            tools++;
        }

        // urn to find coins
        if(((row1 == 7 && column1 == 5) || (row2 == 7 && column2 == 5)) && tools == 5){
            Urn2->Destroyed = true;
            tools++;
        }
    }

   // ALICATE
   if (this->Keys[GLFW_KEY_1] && tools > 0){
       // disarm bear trap1
       if((row1 == 0 && column1 == 6) || (row2 == 0 && column2 == 6)){
           BearTrap1->Destroyed = true;
           tileMap->setWalkable(0,6,true);
       }

       // disarm bear trap2
       if((row1 == 1 && column1 == 6) || (row2 == 1 && column2 == 6)){
           BearTrap2->Destroyed = true;
           tileMap->setWalkable(1,6,true);
       }
   }

    // axe
    if (this->Keys[GLFW_KEY_2] && tools > 1){
        // destroy tree 1
        if((row1 == 4 && column1 == 9) || (row2 == 4 && column2 == 9)){
            Tree1->Destroyed = true;
            tileMap->setWalkable(4,9,true);
        }

        // destroy tree 2
        if((row1 == 3 && column1 == 9) || (row2 == 3 && column2 == 9)){
            Tree2->Destroyed = true;
            tileMap->setWalkable(3,9,true);
        }

        // cactus 1
        if((row1 == 10 && column1 == 7) || (row2 == 10 && column2 == 7)){
            Cactus1->Destroyed = true;
            tileMap->setWalkable(10,7,true);
        }

        // cactus 2
        if((row1 == 10 && column1 == 8) || (row2 == 10 && column2 == 8)){
            Cactus2->Destroyed = true;
            tileMap->setWalkable(10,8,true);
        }

        // cactus 3
        if((row1 == 11 && column1 == 7) || (row2 == 11 && column2 == 7)){
            Cactus3->Destroyed = true;
            tileMap->setWalkable(11,7,true);
        }
    }

    // SHOVEL
    if (this->Keys[GLFW_KEY_3] && tools == 3){
        // dig
        if((row1 == 1 && column1 == 2) || (row2 == 1 && column2 == 2)){
            tileMap->changeTileId(2,1,30);
            tools++;
        }
    }

    // PICKAXE
    if (this->Keys[GLFW_KEY_5] && tools > 4){
        // destroy boulder 1
        if((row1 == 7 && column1 == 4) || (row2 == 7 && column2 == 4)){
            Boulder1->Destroyed = true;
            tileMap->setWalkable(7,4,true);
        }

        // destroy boulder 2
        if((row1 == 8 && column1 == 4) || (row2 == 8 && column2 == 4)){
            Boulder2->Destroyed = true;
            tileMap->setWalkable(8,4,true);
        }

        // destroy boulder 3
        if((row1 == 8 && column1 == 5) || (row2 == 8 && column2 == 5)){
            Boulder3->Destroyed = true;
            tileMap->setWalkable(8,5,true);
        }

        // destroy boulder 4
        if((row1 == 8 && column1 == 6) || (row2 == 8 && column2 == 6)){
            Boulder4->Destroyed = true;
            tileMap->setWalkable(8,6,true);
        }

        // destroy boulder 5
        if((row1 == 7 && column1 == 6) || (row2 == 7 && column2 == 6)){
            Boulder5->Destroyed = true;
            tileMap->setWalkable(7,6,true);
        }
    }


    // Gandalf
    if (this->Keys[GLFW_KEY_4] && tools == 4){
        if(((row1 == 4 && column1 == 2) || (row2 == 4 && column2 == 2))){
            Portal->Destroyed = false;
            Portal2->Destroyed = false;
        }
    }

    // Guard
    if (this->Keys[GLFW_KEY_6] && tools == 6){
        if(row3 == 10 && column3 == 1){
            Guard1->row++;
            tileMap->setWalkable(10, 1, true);
        }
    }

    // Pharao
    if (this->Keys[GLFW_KEY_E] && tools == 6){
        if((row3 == 10 && column3 == 0)){
            tools++;
        }
    }


    // Bridge
    if (this->Keys[GLFW_KEY_7] && tools == 7){
        if(column2 == 9){
            tileMap->setWalkable(row2,column2, true);
            tileMap->changeTileId(column2, row2, 35);
        }
    }
}

