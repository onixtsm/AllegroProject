//
// Created by onix on 07.06.21.
//

#include "ShapeFactory.h"
#include "../Shapes/Circle.h"
#include "../Shapes/Rect.h"
#include "../Shapes/ControlablleSquare.h"


using namespace std;

Shape *ShapeFactory::Create(shape_skeleton skeleton) {

    Shape *shape;


    if (!skeleton.x) {
        skeleton.x = RandD();
    }
    if (!skeleton.y) {
        skeleton.y = RandD();
    }
    if (!skeleton.vx) {
        skeleton.vx = RandD();
    }
    if (!skeleton.vy) {
        skeleton.vy = RandD();
    }
    if (!skeleton.w) {
        skeleton.w = RandD();
    }
    if (!skeleton.h) {
        skeleton.h = RandD();
    }

    if (!skeleton.c) {

        skeleton.c.r = rand() % 256;
        skeleton.c.g = rand() % 256;
        skeleton.c.b = rand() % 256;
    }
    ALLEGRO_COLOR color = al_map_rgb(skeleton.c.r, skeleton.c.g, skeleton.c.b);

    switch (skeleton.type) {
        case RandomCircle:
            shape = new class Circle(RandD());
            break;
        case RandomRect:
            shape = new class Rect(RandD(), RandD());
            break;
        case RandomSquare:
            shape = new class Square(RandD());
            break;
//        case ContollableSquare:
//            return new ControlablleSquare(30);
        case Circle:
            shape = new class Circle(skeleton.w / 2);
            break;
        case Rect:
            shape = new class Rect(skeleton.w, skeleton.h);
            break;
        case Square:
            shape = new class Square(skeleton.w);
            break;
    }

    shape->setX(skeleton.x);
    shape->setY(skeleton.y);
    shape->setVx(skeleton.vx);
    shape->setVy(skeleton.vy);
    shape->setColor(color);

    return shape;
}

double ShapeFactory::RandD() {
    return 10 + rand() % 15;
}
