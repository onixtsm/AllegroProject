//
// Created by onix on 05.06.21.
//
#include <allegro5/allegro.h>
#include "Shape.h"

using namespace std;



Shape::Shape(double w_, double h_) {
    w = w_;
    h = h_;
    spawn();
}


Shape::~Shape() {
}


double Shape::getX() {
    return x;
}

double Shape::getY() {
    return y;
}

double Shape::getW() {
    return w;
}

double Shape::getH() {
    return h;
}

void Shape::move() {
    x += vx;
    y += vy;

    if (x + w / 2 > SCREEN_W || x - w / 2 < 0) {
        vx = -vx;
    }
    if (y + h / 2 > SCREEN_H || y - h / 2 < 0) {
        vy = -vy;
    }
}

void Shape::spawn() {
    x = rand() % SCREEN_W;
    y = rand() % SCREEN_H;
    vx = 10 - rand() % 16;
    vy = 10 - rand() % 16;
    int r = rand() % 256;
    int g = rand() % 256;
    int b = rand() % 256;
    color = al_map_rgb(r, g, b);


}


void Shape::setVx(double vx) {
    Shape::vx = vx;
}

void Shape::setVy(double vy) {
    Shape::vy = vy;
}

double Shape::getVx() const {
    return vx;
}

double Shape::getVy() const {
    return vy;
}