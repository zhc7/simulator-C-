//
// Created by zhc7 on 2022/1/20.
//

#include "Circle.h"
#include <iostream>

Circle::Circle(double radius, double k) : radius(radius), k(k) {}

Vector Circle::collapse(Vector place, Entity entity, double r) {
    auto* c = dynamic_cast<Circle*>(entity.shape);
    if (c) {
        // std::cout << "Circle::collapse" << std::endl;
        if (r > radius + c->radius) {
            return {double(0)};
        }
        Vector d = entity.place - place;
        Vector f = (radius + c->radius - r) * (k + c->k);
        return d * (f / r);
    }
    return {double(0)};
}
