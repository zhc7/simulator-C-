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

using namespace std;

class World {
public:
    vector<Entity> entities;
    map<string, Vector> constants;
    string mode;
    double tic;
    double total_time;
    Vector g;

    World(vector<Entity> entities, map<string, Vector> constants,
          string mode = "display", double tic = 0.01, double total_time = 10);

    void step();

    vector<byte> loop(double record_rate);
};


#endif //SIMULATOR_WORLD_H
