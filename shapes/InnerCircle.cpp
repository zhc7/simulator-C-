//
// Created by zhc7 on 2022/1/20.
//

#include "InnerCircle.h"
#include "Circle.h"

InnerCircle::InnerCircle(double radius, double k) : radius(radius), k(k) {}

Vector InnerCircle::collapse(Vector place, Entity entity, double r) {
    if (typeid(entity) == typeid(Circle)) {
        auto* c = (Circle*) entity.shape;
        if (r < radius - c->radius) {
            return {double(0)};
        }
        Vector d = entity.place - place;
        Vector f = (radius - c->radius - r) * (k + c->k);
        return d * (f / r);
    }
    return {double(0)};
}