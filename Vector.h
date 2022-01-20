//
// Created by zhc7 on 2022/1/19.
//

#ifndef SIMULATOR_VECTOR_H
#define SIMULATOR_VECTOR_H


#include "Vector.h"
#include <vector>

using namespace std;

class Vector {
public:
    int dim = 0;
    vector<double> values;
    double value = 0;

    Vector(int dim);

    Vector(double val);

    Vector(const vector<double> &vals);

    Vector(Vector const &v);

    Vector operator+(Vector &v);

    Vector operator-(Vector &v);

    Vector operator*(double n);

    Vector operator/(double n);

    operator bool() const;

    operator double() const;

    double mod();
};


#endif //SIMULATOR_VECTOR_H
