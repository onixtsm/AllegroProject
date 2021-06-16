//
// Created by onix on 07.06.21.
//

#include "ShapeFactory.h"
#include "../Shapes/Circle.h"
#include "../Shapes/Rect.h"
#include "../Shapes/ControlablleSquare.h"
#include <algorithm>
#include "../config.h"

using namespace std;

void ShapeFactory::StartFactory() {

//    for_each(ShapeArray.begin(), ShapeArray.end(), ShapeFactory::Create());

    for (_List_const_iterator<shape_skeleton> it = ShapeArray.begin(); it != ShapeArray.end(); it++) {
        ShapeFactory::Create(*it);
    }

//    switch (type) {
//
//    }
}

Shape *ShapeFactory::Create(shape_skeleton skeleton) {

    Shape *shape;

    switch (skeleton.type) {
        case RandomCircle:
            shape = new class Circle(10 + rand() % 30);
        case RandomRect:
            shape = new class Rect(10 + rand() % 30, 10 + rand() % 30);
        case RandomSquare:
            shape = new class Square(10 + rand() % 30);
//        case ContollableSquare:
//            return new ControlablleSquare(30);
        case Circle:
            shape = new class Circle();
        case Rect:
            shape = new class Rect();
        case Square:
            shape = new class Square();
    }

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

    shape->setX(skeleton.x);
    shape->setY(skeleton.y);
    shape->setVx(skeleton.vx);
    shape->setVy(skeleton.vy);
    shape->setW(skeleton.w);
    shape->setH(skeleton.h);
    shape->setColor(color);
}

double ShapeFactory::RandD() {
    return 10 + rand() % 30;
}
