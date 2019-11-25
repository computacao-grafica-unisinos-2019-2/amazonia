//
// Created by Viegas, Jorge on 22/09/19.
//
#ifndef gameconfig
#define gameconfig

#include <OpenGL/OpenGL.h>
class GameConfig {
public:
    constexpr static const GLfloat SCREEN_HEIGHT = 840;
    constexpr static const GLfloat SCREEN_WIDTH = 1550;
    constexpr static const GLfloat MOVE_BG = 450;
    constexpr static const GLfloat MOVE_Y_LIMIT = 450;

    constexpr static const GLfloat TILE_WIDTH = 128;
    constexpr static const GLfloat TILE_HEIGHT = 64;

};

#endif