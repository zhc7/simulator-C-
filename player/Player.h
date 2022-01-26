//
// Created by zhc7 on 2022/1/22.
//

#ifndef SIMULATOR_PLAYER_H
#define SIMULATOR_PLAYER_H

#include "../World.h"
#include "include/core/SkCanvas.h"
#include "GLFW/glfw3.h"

class Player {
public:
    SkCanvas canvas;

    Player(const World &world);

    void draw(World &world);

    void play(vector<World> &worlds);
};


#endif //SIMULATOR_PLAYER_H
