//
// Created by onix on 07.06.21.
//

#ifndef ALLEGRO_SHAPEFACTORY_H
#define ALLEGRO_SHAPEFACTORY_H


#include "../Shapes/Shape.h"
#include "../config.h"

class ShapeFactory {
private:

    static double RandD();

public:
    static Shape *Create(shape_skeleton skeleton);
};

#endif //ALLEGRO_SHAPEFACTORY_H
