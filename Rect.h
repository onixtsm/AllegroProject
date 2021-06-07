//
// Created by onix on 05.06.21.
//

#ifndef ALLEGRO_RECT_H
#define ALLEGRO_RECT_H

#include <iostream>
#include "Shape.h"
using namespace std;

class Rect : public Shape {

public:
    Rect(double w, double h);

    virtual void draw();
};

#endif //ALLEGRO_RECT_H
