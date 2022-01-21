//
// Created by zhc7 on 2022/1/19.
//

#include "Vector.h"
#include <iostream>

Vector::Vector(const vector<double> &vals) {
    values = vals;
    dim = (int) vals.size();
}

Vector::Vector(const Vector &v) {
    dim = v.dim;
    values = v.values;
    value = v.value;
}

Vector::Vector(double val) {
    value = val;
    dim = 0;
}

Vector::Vector(int dim) {
    this->dim = dim;
    values = vector<double>(dim, 0);
}

Vector Vector::operator+(double n) {
    vector<double> new_v;
    for (int i = 0; i < dim; i++) {
        new_v.push_back(values.at(i) + n);
    }
    return {new_v};
}

Vector Vector::operator+(Vector &v) {
    if (v.dim == 0) {
        return *this + double(v);
    } else if (dim == 0) {
        return v + value;
    }
    vector<double> new_v;
    new_v.reserve(dim);
    for (int i = 0; i < dim; i++) {
        new_v.push_back(values.at(i) + v.values.at(i));
    }
    return {new_v};
}

Vector Vector::operator-(Vector &v) {
    vector<double> new_v;
    new_v.reserve(dim);
    for (int i = 0; i < dim; i++) {
        new_v.push_back(values.at(i) - v.values.at(i));
    }
    return {new_v};
}

Vector Vector::operator*(double n) {
    vector<double> new_v;
    new_v.reserve(dim);
    for (int i = 0; i < dim; i++) {
        new_v.push_back(values.at(i) * n);
    }
    return {new_v};
}

Vector Vector::operator/(double n) {
    vector<double> new_v;
    new_v.reserve(dim);
    for (int i = 0; i < dim; i++) {
        new_v.push_back(values.at(i) / n);
    }
    return {new_v};
}

Vector::operator bool() const {
    if (!dim && !bool(value)) {
        return false;
    }
    for (int i = 0; i < dim; i++) {
        if (bool(values.at(i))) {
            return true;
        }
    }
    return false;
}

Vector::operator double() const {
    return value;
}

double Vector::mod() {
    double m = 0;
    for (int i = 0; i < dim; i++) {
        m += values.at(i) * values.at(i);
    }
    return m;
}