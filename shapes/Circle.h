//
// Created by zhc7 on 2022/1/20.
//

#ifndef SIMULATOR_CIRCLE_H
#define SIMULATOR_CIRCLE_H

#include "../Shape.h"

class Circle : public Shape {
public:
    double radius;
    string shape = "Circle";
    double k;

    explicit Circle(double radius, double k = 100);

    nc::NdArray<double> collapse(nc::NdArray<double> place, Entity entity, double r) override;
};


#endif //SIMULATOR_CIRCLE_H
