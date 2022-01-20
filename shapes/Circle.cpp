//
// Created by zhc7 on 2022/1/20.
//

#include "Circle.h"

Circle::Circle(double radius, double k) : radius(radius), k(k) {}

Vector Circle::collapse(Vector place, Entity entity, double r) {
    if (typeid(entity) == typeid(Circle)) {
        auto *c = (Circle *) entity.shape;
        if (r > radius + c->radius) {
            return {double(0)};
        }
        Vector d = entity.place - place;
        Vector f = (radius + c->radius - r) * (k + c->k);
        return d * (f / r);
    }
    return {double(0)};
}
