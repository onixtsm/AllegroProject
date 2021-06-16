//
// Created by onix on 05.06.21.
//

#include "Circle.h"
#include <ostream>
#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES

using namespace std;

Circle::Circle(double d) :
        Shape(d, d) {
    m = area();
}

void Circle::draw() {
    al_draw_filled_circle(x, y, w / 2, color);
}

double Circle::area() {
    return M_PI * w * w / 2;
}


void Circle::toStream(ostream &os) {
    os << "x:" << getX() << endl;
    os << "y:" << getY() << endl;
    os << "Vx:" << getVx() << endl;
    os << "Vy:" << getVy() << endl;
    os << "m:" << getM() << endl;
    os << "W:" << getW() << endl;
    os << "H:" << getH() << endl;


}

Circle::Circle() {

}
