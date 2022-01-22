//
// Created by zhc7 on 2022/1/20.
//

#ifndef SIMULATOR_WORLD_H
#define SIMULATOR_WORLD_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Entity.h"
#include "NumCpp.hpp"

using namespace std;

class World {
public:
    vector<Entity> entities;
    string mode;
    double tic;
    double total_time;

    World(vector<Entity> entities, string mode = "display", double tic = 0.01, double total_time = 10);

    void step();

    vector<byte> loop(double record_rate);
};


#endif //SIMULATOR_WORLD_H
