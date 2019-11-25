//
// Created by Viegas, Jorge on 18/11/19.
//

#include "Texture2D.h"

class TileSet {
public:

    Texture2D texture2D;
    int rows, columns;
    int width, height;

    int getRowForId(int id){
        return id / rows;
    }

    int getColumnForId(int id){
        return id % columns;
    }
};

