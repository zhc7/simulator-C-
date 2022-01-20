//
// Created by zhc7 on 2022/1/20.
//

#include "InnerCircle.h"
#include "Circle.h"
#include <iostream>

InnerCircle::InnerCircle(double radius, double k) : radius(radius), k(k) {}

Vector InnerCircle::collapse(Vector place, Entity entity, double r) {
    auto* c = dynamic_cast<Circle*>(entity.shape);
    if (c) {
        // std::cout << "InnerCircle::collapse" << std::endl;
        if (r < radius - c->radius) {
            return {double(0)};
        }
        Vector d = entity.place - place;
        Vector f = (radius - c->radius - r) * (k + c->k);
        return d * (f / r);
    }
    std::cout << "InnerCircle::collapse not if " << typeid(&entity.shape).name() << typeid(Circle).name() << std::endl;
    return {double(0)};
}