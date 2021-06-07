//
// Created by onix on 05.06.21.
//

#include <iostream>
#include "ScreenSaver.h"

ScreenSaver::ScreenSaver() :
        size_(0)
{
    memset(shapes, 0, sizeof(shapes));
}

ScreenSaver::~ScreenSaver() {
    for (int i = 0; i < size_; i++) {
        delete shapes[i];
        shapes[i] = 0;
    }
}

void ScreenSaver::add(Shape *shape) {
    if (size_ >= MAX) {
        return;
    }
    shapes[size_] = shape;
    size_++;
}

ScreenSaver & ScreenSaver::Instance() {
    static ScreenSaver instance;
    return instance;
}

void ScreenSaver::next() {
    for (int i = 0; i < size_; i++) {
        shapes[i]->move();
        for (int j = i+1; j < size_; j++) {
            Shape *a = shapes[i];
            Shape *b = shapes[j];
            if (overlap(a, b)) {
                a->setVx((-a->getVx()));
                b->setVx((-b->getVx()));
                a->setVy((-a->getVy()));
                b->setVy((-b->getVy()));
            }
        }
    }
}

void ScreenSaver::draw() {
    al_clear_to_color(BG_COLOR);
    for ( int i = 0; i < size_; i++) {
        shapes[i]->draw();
    }
}

bool ScreenSaver::overlap(Shape *a, Shape *b) {
    if ((a->getX() - a->getW() / 2 < b->getX() + b->getW() / 2) &&
         (a->getX() + a->getW() / 2 > b->getX() - b->getW() / 2) &&
         (a->getY() - a->getH() / 2 <= b->getY() + b->getH() / 2) &&
         (a->getY() + a->getH() / 2 >= b->getY() - b->getH() / 2)) {
        return true;
    }


    return false;
}
