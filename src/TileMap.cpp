//
// Created by Viegas, Jorge on 17/11/19.
//
#ifndef tilemap
#define tilemap

#include <glm/vec2.hpp>
#include <jmorecfg.h>

class TileMap {

public:
    // What is the size of the map?
    int rows, columns;

    bool walkableTiles [ 12 ][ 12 ] = {
            {true,  true,  true,  true,  true,  true,  false,  true,  true,  true,  true,  true} ,     /*  row 0 */
            {true,  true,  true,  true,  true,  true,  false,  true,  true,  true,  true,  true} ,     /*  row 1 */
            {false, false, false, true, true, false, false, false, false, false, false, false} ,     /*  row 2 */
            {true,  true,  true,  true,  true,  true,  true,  true,  true,  false,  true,  true} ,     /*  row 3 */
            {true,  true,  true,  true,  true,  true,  true,  true,  true,  false,  true,  true} ,     /*  row 4 */
            {false, false, false, false, false, false, false, false, false, false, false, false} ,     /*  row 5 */
            {false, false, false, false, false, false, false, false, false, false, false, false} ,     /*  row 6 */
            {true,  true,  true,  true,  false,  true,  false,  true,  true,  false,  true,  true} ,     /*  row 7 */
            {true,  true,  true,  true,  false,  false,  false,  true,  true,  false,  true,  true} ,     /*  row 8 */
            {false,  true,  true,  true,  true,  true,  true,  true,  true,  false,  true,  true} ,     /*  row 9 */
            {false,  false,  true,  true,  true,  true,  true,  false,  false,  false,  true,  true} ,     /*  row 10 */
            {false,  true,  true,  true,  true,  true,  true,  false,  true,  false,  true,  true}      /*  row 11 */
    };
    int tileMap [ 12 ][ 12 ] = {
            {17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17} ,     /*  row 1 */
            {17,  17,  36,  17,  17,  17,  17,  17,  17,  17,  17,  17} ,     /*  row 2 */
            {40,  40,  40,  34,  34,  40,  40,  40,  40,  40,  40,  40} ,     /*  row 3 */
            {17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17} ,     /*  row 4 */
            {17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17,  17},     /*  row 5 */
            {4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4} ,     /*  row 6 */
            {4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4} ,     /*  row 7 */
            {3,  3,  3,  3,  3,  3,  3,  3,  3,  43,  3,  3} ,     /*  row 8 */
            {3,  3,  3,  3,  3,  3,  3,  3,  3,  43,  3,  3} ,     /*  row 9 */
            {3,  3,  3,  3,  3,  3,  3,  3,  3,  43,  3,  3} ,     /*  row 10 */
            {3,  3,  3,  3,  3,  3,  3,  3,  3,  43,  3,  3} ,     /*  row 11 */
            {3,  3,  3,  3,  3,  3,  3,  3,  3,  43,  3,  3}       /*  row 12 */
    };

    // 1 PEDRA
    // 2 CASCALHO
    // 3 DESERTO
    // 4 LAVA
    // 6 GRAMA
    // 40 agua
    // 43 movediça

    // What is the tile ID to be printed on column / row?
    int getTileId(int column, int row) {
        return tileMap[row][column];
    }

    void changeTileId(int column, int row, int newId){
        tileMap[row][column] = newId;
    }

    void setWalkable(int row, int column, bool walkable){
        walkableTiles[row][column] = walkable;
    }

   bool isWalkable(int row, int column){

        if (row < 0 || row == rows || column < 0 || column == columns)
            return false;

        return walkableTiles[row][column];
    }
};
#endif