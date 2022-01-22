//
// Created by zhc7 on 2022/1/20.
//

#include "Circle.h"

Circle::Circle(double radius, double k) : radius(radius), k(k) {}

nc::NdArray<double> Circle::collapse(nc::NdArray<double> place, Entity entity, double r) {
    auto* c = dynamic_cast<Circle*>(entity.shape);
    if (c) {
        // std::cout << "Circle::collapse" << std::endl;
        if (r > radius + c->radius) {
            return nc::zeros<double>(1, dimension);
        }
        nc::NdArray<double> d = entity.place - place;
        double f = (radius + c->radius - r) * (k + c->k);
        return d * (f / r);
    }
    return nc::zeros<double>(1, dimension);
}
