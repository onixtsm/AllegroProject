//
// Created by onix on 08.06.21.
//

#include "Vector.h"

Vector::Vector(double vx_, double vy_){
    vx = vx_;
    vy = vy_;
    evalSpeed();
}

Vector::Vector() {

}

Vector::~Vector() {}

double Vector::getVx() const {
    return vx;
}

void Vector::setVx(double vx) {
    Vector::vx = vx;
    evalSpeed();
}

double Vector::getVy() const {
    return vy;
}

void Vector::setVy(double vy) {
    Vector::vy = vy;
    evalSpeed();
}

double Vector::getSpeed() const {
    return speed;
}


void Vector::evalSpeed() {
    speed = sqrt(pow(vx, 2) + pow(vy, 2));
}

double Vector::div(Vector v) {
    return speed / v.speed;
}
