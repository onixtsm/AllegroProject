//
// Created by onix on 05.06.21.
//

#ifndef ALLEGRO_CIRCLE_H
#define ALLEGRO_CIRCLE_H


#include "Shape.h"

class Circle : public Shape {
protected:
    double r;
public:
    Circle(double r);

    virtual void draw();

private:
    virtual double area();
};


#endif //ALLEGRO_CIRCLE_H
