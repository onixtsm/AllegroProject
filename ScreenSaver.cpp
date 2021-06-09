//
// Created by onix on 05.06.21.
//

#include <iostream>
#include <valarray>
#include "ScreenSaver.h"
#include <cmath>

using namespace std;

ScreenSaver::ScreenSaver() :
        size_(0)
{
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
    shapes.push_back(shape);
    size_++;
}

Shape* ScreenSaver::get(int n) {
    return shapes[n];
}

Shape* ScreenSaver::getLast() {
    return shapes[size_];
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

                double va = a->vector.getSpeed();
                double vb = b->vector.getSpeed();

                double phy = asin((a->getVx() * b->getVy() - a->getVy() * b->getVx()) /
                        (a->vector.getSpeed() * b->vector.getSpeed()));
                double tetaA = acos(a->getVx() / va);
                double tetaB = acos(b->getVx() / vb);

                double vaxn = (va * cos(tetaA - phy) * (a->getM() - b->getM()) + 2 * b->getM() * vb * cos(tetaB - phy) * cos(phy) + va *
                                                                                                                                           sin(tetaA - phy) *
                                                                                                                                           cos(phy + M_PI / 2)) / (a->getM() + b->getM());

                double vayn = (va * cos(tetaA - phy) * (a->getM() - b->getM()) + 2 * b->getM() * vb * cos(tetaB - phy) * sin(phy) + va *
                                                                                                                                    sin(tetaA - phy) *
                                                                                                                                    sin(phy + M_PI / 2)) / (a->getM() + b->getM());
                double vbyn = (vb * cos(tetaB - phy) * (b->getM() - a->getM()) + 2 * a->getM() * va * cos(tetaA - phy) * sin(phy) + vb *
                                                                                                                                    sin(tetaB - phy) *
                                                                                                                                    sin(phy + M_PI / 2)) / (a->getM() + b->getM());
                double vbxn = (vb * cos(tetaB - phy) * (b->getM() - a->getM()) + 2 * a->getM() * va * cos(tetaA - phy) * cos(phy) + vb *
                                                                                                                                    sin(tetaB - phy) *
                                                                                                                                    cos(phy + M_PI / 2)) / (a->getM() + b->getM());

                a->setVx(vaxn);
                a->setVy(vayn);

                b->setVx(vbxn);
                b->setVy(vbyn);
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
