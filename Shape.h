//
// Created by zhc7 on 2022/1/19.
//

#ifndef SIMULATOR_SHAPE_H
#define SIMULATOR_SHAPE_H


#include "Vector.h"
#include "Entity.h"
#include "NumCpp.hpp"
#include "constants.h"
#include "include/core/SkCanvas.h"

class Entity;

class Shape {

public:
    virtual nc::NdArray<double> collapse(nc::NdArray<double> place, Entity entity, double r) = 0;

    virtual void draw(SkCanvas* canvas, nc::NdArray<double> place) = 0;
};


#endif //SIMULATOR_SHAPE_H
