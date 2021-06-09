//
// Created by onix on 08.06.21.
//

#ifndef ALLEGRO_VELOSITY_H
#define ALLEGRO_VELOSITY_H

#include <math.h>


class Velosity {
public:

    Velosity(double vx, double vy);

    Velosity();

    ~Velosity();

    double getVx() const;

    void setVx(double vx);

    double getVy() const;

    void setVy(double vy);

    double getSpeed() const;

    double div(Velosity v);

private:
    double vx{};
    double vy{};
    double speed{};

    void evalSpeed();


};


#endif //ALLEGRO_VELOSITY_H
