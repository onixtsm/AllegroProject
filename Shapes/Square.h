//
// Created by onix on 05.06.21.
//

#ifndef ALLEGRO_SQUARE_H
#define ALLEGRO_SQUARE_H


#include "Rect.h"

class Square : public Rect {
public:
    Square(double w);

    Square();

    virtual void draw();
};


#endif //ALLEGRO_SQUARE_H
