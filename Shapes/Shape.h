//
// Created by onix on 05.06.21.
//

#ifndef ALLEGRO_SHAPE_H
#define ALLEGRO_SHAPE_H

#include "../Allegro/AllegroBase.hpp"
#include "../Helpers/Velosity.h"
#include <ostream>

const ALLEGRO_COLOR BG_COLOR = al_map_rgb(0, 0, 0);

class Shape {
protected:
    double x;
    double y;
    double w;
    double h;
    double m;
    ALLEGRO_COLOR color;

public:

    Velosity vector;

    Shape(double w_, double h_);

    Shape();

    virtual ~Shape() = 0;

    double getX();

    double getY();

    double getW();

    double getH();

    void move();

    void spawn();

    virtual void draw() = 0;

    void setVx(double vx);

    void setVy(double vy);

    double getVx() const;

    double getVy() const;

    double getM() const;

    virtual void toStream(std::ostream &os);

    void setX(double x);

    void setY(double y);

    void setW(double w);

    void setH(double h);

    void setColor(const ALLEGRO_COLOR &color);

private:
    virtual double area() = 0;

};

#endif