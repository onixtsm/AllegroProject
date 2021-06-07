//
// Created by onix on 05.06.21.
//

#include "Rect.h"
Rect::Rect(double w, double h) :
        Shape(w, h)
{
}
void Rect::draw() {
    double half_w = w/2;
    double half_h = h/2;
    al_draw_filled_rectangle(x - half_w, y - half_h, x + half_w, y + half_h, color);
}
