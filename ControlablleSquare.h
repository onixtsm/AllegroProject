//
// Created by onix on 07.06.21.
//

#ifndef ALLEGRO_CONTROLABLLESQUARE_H
#define ALLEGRO_CONTROLABLLESQUARE_H


#include "Square.h"

class ControlablleSquare : public Square {
public:
    ControlablleSquare(double w);

    virtual ~ControlablleSquare();

    void move(double vx, double vy);


};


#endif //ALLEGRO_CONTROLABLLESQUARE_H
