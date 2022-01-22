//
// Created by zhc7 on 2022/1/20.
//

#ifndef SIMULATOR_INNERCIRCLE_H
#define SIMULATOR_INNERCIRCLE_H

#include <string>
#include "../Vector.h"
#include "../Shape.h"

class InnerCircle : public Shape {
public:
    double radius;
    string shape = "InnerCircle";
    double k;

    explicit InnerCircle(double radius, double k=10000);

    nc::NdArray<double> collapse(nc::NdArray<double> place, Entity entity, double r) override;
};


#endif //SIMULATOR_INNERCIRCLE_H
