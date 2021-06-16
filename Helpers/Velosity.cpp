//
// Created by onix on 08.06.21.
//

#include "Velosity.h"

Velosity::Velosity(double vx_, double vy_){
    vx = vx_;
    vy = vy_;
    evalSpeed();
}

Velosity::Velosity() {

}

Velosity::~Velosity() {}

double Velosity::getVx() const {
    return vx;
}

void Velosity::setVx(double vx) {
    Velosity::vx = vx;
    evalSpeed();
}

double Velosity::getVy() const {
    return vy;
}

void Velosity::setVy(double vy) {
    Velosity::vy = vy;
    evalSpeed();
}

double Velosity::getSpeed() const {
    return speed;
}


void Velosity::evalSpeed() {
    speed = sqrt(pow(vx, 2) + pow(vy, 2));
}

double Velosity::div(Velosity v) {
    return speed / v.speed;
}
