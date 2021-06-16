//
// Created by onix on 05.06.21.
//

#ifndef ALLEGRO_CIRCLE_H
#define ALLEGRO_CIRCLE_H


#include "Shape.h"
#include <ostream>

class Circle : public Shape {
protected:
    double r;
public:
    Circle(double r);

    Circle();

    virtual void draw();

private:
    virtual double area();

    virtual void toStream(std::ostream &os);
};


#endif //ALLEGRO_CIRCLE_H
