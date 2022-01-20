//
// Created by zhc7 on 2022/1/18.
//

#ifndef SIMULATOR_ENTITY_H
#define SIMULATOR_ENTITY_H

#include "Shape.h"
#include "Vector.h"
#include <vector>
#include <map>

using namespace std;

class Shape;

class Entity {
public:
    Shape *shape;
    double m;
    double q;
    Vector place;
    Vector v;
    Vector a;
    bool fixed;
    vector<Vector> forces;

    Entity(Shape *shape, double mass, double charge, const Vector& place, const Vector& velocity,
           const Vector& acceleration, bool fixed = false);

    void enforce(const Vector &force);

    Vector collapse(Entity entity, std::map<string, Vector> constants);

    void calc_a();
};


#endif //SIMULATOR_ENTITY_H
