//
// Created by onix on 07.06.21.
//

#ifndef ALLEGRO_SHAPEFACTORY_H
#define ALLEGRO_SHAPEFACTORY_H


#include "Shape.h"

class ShapeFactory {
public:
    enum Type {
        RandomCircle,
        RandomRect,
        RandomSquare
    };

    static Shape *Create(Type type);

};

#endif //ALLEGRO_SHAPEFACTORY_H
