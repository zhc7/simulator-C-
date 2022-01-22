//
// Created by zhc7 on 2022/1/19.
//

#include "Entity.h"
#include <iostream>
#include <utility>


Entity::Entity(Shape *shape, double mass, double charge, nc::NdArray<double> place,
               nc::NdArray<double> velocity, nc::NdArray<double> acceleration, bool fixed) : shape(shape),
                                                                                             m(mass),
                                                                                             q(charge),
                                                                                             place(std::move(place)),
                                                                                             v(std::move(velocity)),
                                                                                             a(std::move(acceleration)),
                                                                                             fixed(fixed) {}

void Entity::enforce(const nc::NdArray<double> &force) {
    if (fixed) {
        return;
    }
    forces.push_back(force);
}

void Entity::calc_a() {
    if (fixed) {
        return;
    }
    nc::NdArray<double> F = nc::zeros<double>(1, dimension);
    for (auto &f: forces) {
        F = F + f;
    }
    a = F / m;
    forces = {};
}

nc::NdArray<double> Entity::collapse(const Entity &e) {
    nc::NdArray<double> r_v = e.place - place;
    double r = nc::norm(r_v).at(0);
    nc::NdArray<double> mechanical = shape->collapse(place, e, r);
    nc::NdArray<double> electrical = nc::zeros<double>(1, dimension);
    if (bool(q)) {
        double electrical_n =
                q * e.q / (epsilon0 *
                           4 * pi * r * r);
        electrical = r_v * (electrical_n / r);
    }
    return mechanical + electrical;
}
