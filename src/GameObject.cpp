#include <iostream>
#include "GameObject.h"
#include "GameConfig.cpp"

GameObject::GameObject()
        : Position(0, 0), Size(1, 1), Velocity(0.0f), Color(1.0f), Rotation(0.0f), Sprite(), IsSolid(false), Destroyed(false) { }

GameObject::GameObject(glm::vec2 pos, glm::vec2 size, Texture2D sprite, GLint Frames, glm::vec3 color, glm::vec2 velocity)
        : Position(pos), Size(size), Velocity(velocity), Color(color), Rotation(0.0f), Sprite(sprite), IsSolid(false), Destroyed(false), Frames(Frames){

    framewidht = ((float)1 / (float)Frames);
    CurrentFrame = 1;
    offsetx = 0.0f;
    ProcessFrame();
}

void GameObject::Draw(SpriteRenderer &renderer)
{
    //std::cout << "Fw: " << framewidht << "\n";
   // std::cout << "Offsetx: " << offsetx << "\n";
  //  std::cout << "Current Frame: " << CurrentFrame << "\n";

    renderer.DrawSprite(this->Sprite, this->Position, this->Size, this->Rotation, this->Color, this->offsetx, this->offsety, this->framewidht);
}

void GameObject::ProcessFrame() {
    if (this->CurrentFrame == Frames)
        this->CurrentFrame = 1;
    else
        this->CurrentFrame = this->CurrentFrame + 1;
    this->offsetx = (float) this->framewidht * (float) CurrentFrame;
}

void GameObject::MoveRight(GLfloat dt) {
    if (GameConfig::MOVE_BG >= this->Position.x && GameConfig::SCREEN_WIDTH - this->Size.x >= this->Position.x)
        this->Position.x += this->velocity * dt;
    this->CurrentAction = SpriteAction::RUN;
    this->ProcessFrame();
}

void GameObject::MoveLeft(GLfloat dt) {
    if (this->Position.x >= 0)
        this->Position.x -= this->velocity * dt;
    this->CurrentAction = SpriteAction::RUN;
    this->ProcessFrame();
}
void GameObject::MoveUp(GLfloat dt)  {
    if (this->Position.y >= 0) {
        this->Position.y -= this->velocity * dt;
        this->ScaleDown(dt);
    }
    this->CurrentAction = SpriteAction::RUN;
    this->ProcessFrame();
}
void GameObject::MoveDown(GLfloat dt)  {
    if (GameConfig::SCREEN_HEIGHT - this->Size.y >= this->Position.y){
        this->Position.y += this->velocity * dt;
        this->ScaleUp(dt);
    }
    this->CurrentAction = SpriteAction::RUN;
    this->ProcessFrame();
}

void GameObject::ScaleDown(GLfloat dt){
    this->Size.x = this->Size.x * 0.999f;
    this->Size.y = this->Size.y * 0.999f;
}

void GameObject::ScaleUp(GLfloat dt){
    this->Size.x = this->Size.x * 1.001f;
    this->Size.y = this->Size.y * 1.001f;
}