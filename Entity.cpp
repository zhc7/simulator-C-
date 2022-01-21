//
// Created by zhc7 on 2022/1/19.
//

#include "Entity.h"
#include <iostream>


Entity::Entity(Shape *shape, double mass, double charge, const Vector &place, const Vector &velocity,
               const Vector &acceleration, bool fixed) : shape(shape), m(mass), q(charge),
                                                         place(place), v(velocity), a(acceleration), fixed(fixed) {}

void Entity::enforce(const Vector &force) {
    if (fixed || !bool(force)) {
        return;
    }
    forces.push_back(force);
}

void Entity::calc_a() {
    if (fixed) {
        return;
    }
    Vector F = Vector(double(0));
    for (auto &f: forces) {
        F = F + f;
    }
    a = F / m;
    forces = {};
}

Vector Entity::collapse(Entity e, map<string, Vector> constants) {
    Vector r_v = e.place - place;
    double r = r_v.mod();
    Vector mechanical = shape->collapse(place, e, r);
    Vector electrical = Vector(double(0));
    if (bool(q)) {
        double electrical_n =
                q * e.q / ( constants.at("epsilon0").value *
                           4 * constants.at("pi").value * r);
        electrical = r_v * (electrical_n / r);
    }
    return mechanical + electrical;
}
