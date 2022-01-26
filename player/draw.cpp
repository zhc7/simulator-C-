//
// Created by zhc7 on 2022/1/24.
//

#include "../Entity.h"
#include "../shapes/Circle.h"
#include "../shapes/InnerCircle.h"
#include "include/core/SkCanvas.h"
#include "include/core/SkColor.h"
#include "include/core/SkPaint.h"


void Entity::draw(SkCanvas* canvas) {
    shape->draw(canvas, place);
}

void Circle::draw(SkCanvas* canvas, nc::NdArray<double> place) {
    SkPaint paint;
    paint.setColor(SK_ColorBLUE);
    double x = place.at(0);
    double y = place.at(1);
    canvas->drawCircle(x, y, radius, paint);
}

void InnerCircle::draw(SkCanvas* canvas, nc::NdArray<double> place) {
    SkPaint paint;
    paint.setColor(SK_ColorBLACK);
    double x = place.at(0);
    double y = place.at(1);
    canvas->drawCircle(x, y, radius, paint);
}