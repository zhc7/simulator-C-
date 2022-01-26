//
// Created by zhc7 on 2022/1/18.
//

#ifndef SIMULATOR_ENTITY_H
#define SIMULATOR_ENTITY_H

#include "Shape.h"
#include "Vector.h"
#include "NumCpp.hpp"
#include "constants.h"
#include "include/core/SkCanvas.h"
#include <vector>
#include <map>

using namespace std;

class Shape;

class Entity {
public:
    Shape *shape;
    double m;
    double q;
    nc::NdArray<double> place;
    nc::NdArray<double> v;
    nc::NdArray<double> a;
    bool fixed;
    vector<nc::NdArray<double>> forces;

    Entity(Shape *shape, double mass, double charge, nc::NdArray<double>  place, nc::NdArray<double> velocity,
           nc::NdArray<double> acceleration, bool fixed = false);

    void enforce(const nc::NdArray<double> &force);

    nc::NdArray<double> collapse(const Entity& entity);

    void calc_a();

    void draw(SkCanvas *canvas);
};


#endif //SIMULATOR_ENTITY_H
