#include <iostream>
#include "GameObject.h"
#include "GameConfig.cpp"
#include "TileMapView.cpp"


GameObject::GameObject()
        : Position(0, 0, 0), Size(1, 1), Velocity(0.0f), Color(1.0f), Rotation(0.0f), Sprite(), IsSolid(false), Destroyed(false) { }

GameObject::GameObject(glm::vec3 pos, glm::vec2 size, Texture2D sprite, GLint Frames, glm::vec3 color, glm::vec2 velocity)
        : Position(pos), Size(size), Velocity(velocity), Color(color), Rotation(0.0f), Sprite(sprite), IsSolid(false), Destroyed(false), Frames(Frames){

    framewidht = ((float)1 / (float)Frames);
    CurrentFrame = 1;
    offsetx = 0.0f;
    matrixOffsetX = 32;
    matrixOffsetY = 32;
    ProcessFrame();
}

void GameObject::Draw(SpriteRenderer &renderer)
{
    if (this->Destroyed) return;
    updatePositionBasedOnMatrix();
    renderer.DrawSprite(this->Sprite, this->Position, this->Size, this->Rotation, this->Color, this->offsetx, this->offsety, this->framewidht);
}

void GameObject::updatePositionBasedOnMatrix() {
    int positionX, positionY = 0;
    TileMapView::calculateTilePosition(positionX, positionY, column, row);

    this->Size.x;

    this->Position.x = positionX + this->matrixOffsetX;
    this->Position.y = positionY - this->matrixOffsetY;
}

void GameObject::ProcessFrame() {
    if (this->CurrentFrame == Frames)
        this->CurrentFrame = 1;
    else
        this->CurrentFrame = this->CurrentFrame + 1;
    this->offsetx = (float) this->framewidht * (float) CurrentFrame;
}

void GameObject::MoveRight(GLfloat dt, TileMap *tileMap) {
    int nextColumnValue = this->column + 1;

    if(!this->CheckIfValid(nextColumnValue, this->row, tileMap)){
        return;
    }

    this->column = nextColumnValue;
    this->CurrentAction = SpriteAction::RUN;
    this->ProcessFrame();
}

void GameObject::MoveLeft(GLfloat dt, TileMap *tileMap) {
    int nextColumnValue = this->column - 1;

    if(!this->CheckIfValid(nextColumnValue, this->row, tileMap)){
        return;
    }

    this->column = nextColumnValue;
    this->CurrentAction = SpriteAction::RUN;
    this->ProcessFrame();
}

// w - north
void GameObject::MoveUp(GLfloat dt, TileMap *tileMap)  {
    int nextRowValue = this->row + 1;

    if(!this->CheckIfValid(this->column, nextRowValue, tileMap)){
        return;
    }

    this->row = nextRowValue;
    this->CurrentAction = SpriteAction::RUN;
    this->ProcessFrame();
}
void GameObject::MoveDown(GLfloat dt, TileMap *tileMap)  {
    int nextRowValue = this->row - 1;

    if(!this->CheckIfValid(this->column, nextRowValue, tileMap)){
        return;
    }

    this->row = nextRowValue;
    this->CurrentAction = SpriteAction::RUN;
    this->ProcessFrame();
}

bool GameObject::CheckIfValid(int column, int row, TileMap *tileMap)  {
    return tileMap->isWalkable(row, column);
}


