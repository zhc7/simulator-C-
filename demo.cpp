//
// Created by zhc7 on 2022/1/20.
//


#include "shapes/Circle.h"
#include "shapes/InnerCircle.h"
#include "World.h"
#include <ctime>

using namespace std;


int main() {
    InnerCircle s0 = InnerCircle(10);
    Shape *ps0 = &s0;
    Entity Box = Entity(ps0, 1.0, 0.0, Vector({0, 0}), Vector(0.0), Vector(0.0), true);
    Circle s1 = Circle(1);
    Shape *ps1 = &s1;
    Circle s2 = Circle(1);
    Shape *ps2 = &s2;
    Circle s3 = Circle(1);
    Shape *ps3 = &s3;
    Entity c1 = Entity(ps1, 2, 1e-4, Vector({0, 0}), Vector({3, 4}), 0);
    Entity c2 = Entity(ps2, 2, -1e-4, Vector({3, 5}), Vector({5, -4}), 0);
    Entity c3 = Entity(ps3, 2, -1e-4, Vector({-3, -4}), Vector({6, 0}), 0);
    
    map<string, Vector> constants = {
            {"g",       Vector({0, 9.8})},
            {"epsion0", Vector((double)8.854e-12)},
            {"pi",      Vector((double)3.14159)},
    };

    World world = World({Box, c1, c2, c3}, constants, "display", 1e-4);

    clock_t t1 = clock();
    world.loop(0.1);
    clock_t t2 = clock();
    cout << (double) (t2 - t1) / 1000 << "s" << endl;
}