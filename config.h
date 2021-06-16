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

    bool operator!() {
        return (r == NULL && g == NULL && b == NULL);
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

/* Use this, to generate shapes. You can choose which shape to take form enum higher. Any field (except type) could be RANDOM
 * or NULL
 */

static const std::list<shape_skeleton> ShapeArray = {
/*    type,     x,      y,      vx,     vy,     w/r,      h,      color      */

        {Circle, 20, 90, 2, 5, 30, 30, {255, 0, 0}},
        {Circle, 200, 600, 2, 5, 60, 30, {0, 255, 0}},
        {Circle, 500, 40, RANDOM, RANDOM, RANDOM, 0, RANDOM},
        {RandomCircle }

};


#endif //ALLEGRO_CONFIG_H
