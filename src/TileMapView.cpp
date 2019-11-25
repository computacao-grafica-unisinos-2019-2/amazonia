//
// Created by Viegas, Jorge on 17/11/19.
//
#include <GameConfig.cpp>
#include <TileMap.cpp>

class TileMapView {

public:
    const static int tileWidth = 128;
    const static int tileHeight = 64;
    int x ,y;

    static void calculateTilePosition(int &px, int &py, int c, int l) {
        px = c * (tileWidth / 2) + l * (tileWidth / 2);
        py = c * (tileHeight / 2) - l * (tileHeight / 2);

        py = py + (GameConfig::SCREEN_HEIGHT / 2);
    }

    static void tileWalk(int &l, int &c, int key, TileMap *tileMap){
            if (l < 0 || l == tileMap->rows || c < 0 || c == tileMap->columns) {
                l = 0;
                c = 0;
            }
    }

    void mousemap(int &l, int &c, int x, int y, int tileWidth, int tileHeight);
};
