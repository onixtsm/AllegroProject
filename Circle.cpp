//
// Created by onix on 05.06.21.
//

#include "Circle.h"

Circle::Circle(double d) :
        Shape(d, d) {
}

void Circle::draw() {
    al_draw_filled_circle(x, y, w / 2, color);
}


