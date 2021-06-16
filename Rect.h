//
// Created by onix on 05.06.21.
//

#ifndef ALLEGRO_RECT_H
#define ALLEGRO_RECT_H

#include <iostream>
#include "Shape.h"

class Rect : public Shape {

public:
    Rect(double w, double h);

    virtual void draw();

    virtual void toStream(std::ostream &os);

private:
    virtual double area();
};

#endif //ALLEGRO_RECT_H
