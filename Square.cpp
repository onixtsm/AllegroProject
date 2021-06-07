//
// Created by onix on 05.06.21.
//

#include "Square.h"

Square::Square(double w) :
        Rect(w, w)
{
}

void Square::draw() {
    double half = w / 2;
    al_draw_filled_rectangle(x - half, y - half, x + half, y + half, color);
}
