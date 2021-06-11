//
// Created by onix on 07.06.21.
//

#include "ControlablleSquare.h"

ControlablleSquare::ControlablleSquare(double w) :
        Square(w)
{
}

ControlablleSquare::~ControlablleSquare()= default;

void ControlablleSquare::move(double vx, double vy) {
    x += vx;
    y += vy;
}