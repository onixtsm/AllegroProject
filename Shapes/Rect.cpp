//
// Created by onix on 05.06.21.
//

#include "Rect.h"

using namespace std;

Rect::Rect(double w, double h) :
        Shape(w, h)
{
}
void Rect::draw() {
    double half_w = w/2;
    double half_h = h/2;
    al_draw_filled_rectangle(x - half_w, y - half_h, x + half_w, y + half_h, color);
}

void Rect::toStream(ostream &os) {

    os << "x:" << getX() << endl;
    os << "y:" << getY() << endl;
    os << "Vx:" << getVx() << endl;
    os << "Vy:" << getVy() << endl;
    os << "m:" << getM() << endl;
    os << "W:" << getW() << endl;
    os << "H:" << getH() << endl;
}


double Rect::area() {
    return w * h;
}

Rect::Rect() {

}
