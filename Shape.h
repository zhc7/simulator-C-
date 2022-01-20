//
// Created by zhc7 on 2022/1/19.
//

#ifndef SIMULATOR_SHAPE_H
#define SIMULATOR_SHAPE_H


#include "Vector.h"
#include "Entity.h"

class Entity;

class Shape {

public:
    virtual Vector collapse(Vector place, Entity entity, double r) = 0;
};


#endif //SIMULATOR_SHAPE_H
