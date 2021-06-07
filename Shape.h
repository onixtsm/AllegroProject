//
// Created by onix on 05.06.21.
//

#ifndef ALLEGRO_SHAPE_H
#define ALLEGRO_SHAPE_H

#include "AllegroBase.hpp"

const ALLEGRO_COLOR BG_COLOR = al_map_rgb(0, 0, 0);

class Shape {
protected:
    double vx;
    double vy;
    double x;
    double y;
    double w;
    double h;
    ALLEGRO_COLOR color;

public:
    Shape(double w_, double h_);
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

};

#endif