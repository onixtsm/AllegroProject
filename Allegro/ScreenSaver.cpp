//
// Created by onix on 05.06.21.
//

#include <valarray>
#include "ScreenSaver.h"
#include <cmath>
#include <fstream>

using namespace std;

ScreenSaver::ScreenSaver() :
        size_(0) {
}

ScreenSaver::~ScreenSaver() {
}

void ScreenSaver::add(Shape *shape) {
    if (size_ >= MAX) {
        return;
    }
    shapes.push_back(SPShape(shape));
    size_++;
}

shared_ptr<Shape> ScreenSaver::get(int n) {
    return shapes[n];
}

shared_ptr<Shape> ScreenSaver::getLast() {
    return shapes[size_];
}

ScreenSaver &ScreenSaver::Instance() {
    static ScreenSaver instance;
    return instance;
}
constexpr double find_speed_x(double va, double vb, double tetaA, double tetaB, double am, double bm, double phy) {
    return (va * cos(tetaA - phy) * (am - bm) + 2 * bm * vb * cos(tetaB - phy) * cos(phy) + va * sin(tetaA - phy) * cos(phy + M_PI / 2)) / (am + bm);
}

constexpr double find_speed_y(double va, double vb, double tetaA, double tetaB, double am, double bm, double phy) {
    return (va * cos(tetaA - phy) * (am - bm) + 2 * bm * vb * cos(tetaB - phy) * sin(phy) + va * sin(tetaA - phy) * sin(phy + M_PI / 2)) / (am + bm);
}

void ScreenSaver::next() {
    for (int i = 0; i < size_; i++) {
        shapes[i]->move();
        for (int j = i + 1; j < size_; j++) {
            shared_ptr<Shape> a = shapes[i];
            shared_ptr<Shape> b = shapes[j];
            if (overlap(a, b)) {

                double va = a->vector.getSpeed();
                double vb = b->vector.getSpeed();

                double phy = asin((a->getVx() * b->getVy() - a->getVy() * b->getVx()) /
                                  (a->vector.getSpeed() * b->vector.getSpeed()));
                double tetaA = acos(a->getVx() / va);
                double tetaB = acos(b->getVx() / vb);

                double vaxn = find_speed_x(va, vb, tetaA, tetaB, a->getM(), b->getM(), phy);
                double vayn = find_speed_y(va, vb, tetaA, tetaB, a->getM(), b->getM(), phy);

                double vbxn = find_speed_x(vb, va, tetaB, tetaA, b->getM(), a->getM(), phy);
                double vbyn = find_speed_y(vb, va, tetaB, tetaA, b->getM(), a->getM(), phy);

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
    for (int i = 0; i < size_; i++) {
        shapes[i]->draw();
    }
}

bool ScreenSaver::overlap(shared_ptr<Shape> a, shared_ptr<Shape> b) {
    if ((a->getX() - a->getW() / 2 < b->getX() + b->getW() / 2) &&
        (a->getX() + a->getW() / 2 > b->getX() - b->getW() / 2) &&
        (a->getY() - a->getH() / 2 <= b->getY() + b->getH() / 2) &&
        (a->getY() + a->getH() / 2 >= b->getY() - b->getH() / 2)) {
        return true;
    }
    return false;
}

ostream & operator << (ostream &os, Shape *shape) {

    shape->toStream(os);
    return os;

}

void ScreenSaver::toFile() {
    fstream logfile("shape_log.txt", fstream::out);
    for (int i = 0; i < size_; i++) {
        logfile << shapes[i] << endl;
    }
    logfile.close();

}
