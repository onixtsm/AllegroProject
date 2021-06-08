//
// Created by onix on 08.06.21.
//

#ifndef ALLEGRO_VECTOR_H
#define ALLEGRO_VECTOR_H

#include <math.h>


class Vector {
public:

    Vector(double vx, double vy);

    Vector();

    ~Vector();

    double getVx() const;

    void setVx(double vx);

    double getVy() const;

    void setVy(double vy);

    double getSpeed() const;

    double div(Vector v);

private:
    double vx{};
    double vy{};
    double speed{};

    void evalSpeed();


};


#endif //ALLEGRO_VECTOR_H
