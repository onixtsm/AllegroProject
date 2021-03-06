//
// Created by onix on 05.06.21.
//
#include <allegro5/allegro.h>
#include <fstream>
#include "Shape.h"



Shape::Shape(double w_, double h_) {
    w = w_;
    h = h_;
    m = area();
    Velosity(0, 0);
    spawn();
}

Shape::Shape() {
    Velosity();
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
    x += vector.getVx();
    y += vector.getVy();

    if (x + w / 2 > SCREEN_W || x - w / 2 < 0) {
        vector.setVx(-vector.getVx());
    }
    if (y + h / 2 > SCREEN_H || y - h / 2 < 0) {
        vector.setVy(-vector.getVy());
    }
}

double Shape::area() {
    return 0;
}

void Shape::spawn() {
    x = rand() % SCREEN_W;
    y = rand() % SCREEN_H;
    vector.setVx(10 - rand() % 16);
    vector.setVy(10 - rand() % 16);
    int r = rand() % 256;
    int g = rand() % 256;
    int b = rand() % 256;
    color = al_map_rgb(r, g, b);


}


void Shape::setVx(double vx) {
    Shape::vector.setVx(vx);
}

void Shape::setVy(double vy) {
    Shape::vector.setVy(vy);
}

double Shape::getVx() const {
    return vector.getVx();
}

double Shape::getVy() const {
    return vector.getVy();
}

double Shape::getM() const {
    return m;
}

void Shape::toStream(std::ostream &os) {

}



void Shape::setX(double x) {
    Shape::x = x;
}

void Shape::setY(double y) {
    Shape::y = y;
}

void Shape::setW(double w) {
    Shape::w = w;
}

void Shape::setH(double h) {
    Shape::h = h;
}

void Shape::setColor(const ALLEGRO_COLOR &color) {
    Shape::color = color;
}
