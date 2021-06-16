//
// Created by onix on 16.06.21.
//

#ifndef ALLEGRO_CONFIG_H
#define ALLEGRO_CONFIG_H


#include <list>

#define RANDOM NULL
enum Type {
    Circle,
    Square,
    Rect,
    RandomCircle,
    RandomRect,
    RandomSquare,
};

struct Color {
    int r;
    int g;
    int b;

    bool operator! () {
        return (r != NULL && g != NULL && b != NULL);
    }
};

struct shape_skeleton {


    Type type;
    double x;
    double y;
    double vx;
    double vy;
    double w;
    double h;
    Color c;
};


static const std::list<shape_skeleton> ShapeArray = {
/*    type,     x,      y,      vx,     vy,     w,      h,      color      */

    { Circle,   20,     90,     2,      5,      3,      3,      {2, 200, 255} }

};



#endif //ALLEGRO_CONFIG_H
