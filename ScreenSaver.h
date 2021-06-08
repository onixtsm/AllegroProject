//
// Created by onix on 05.06.21.
//

#ifndef ALLEGRO_SCREENSAVER_H
#define ALLEGRO_SCREENSAVER_H


#include "Shape.h"

const int MAX = 100;

class ScreenSaver {
private:
    Shape* shapes[MAX]{};
    int size_;
    ScreenSaver();

    static bool overlap(Shape *a, Shape *b);
public:

    virtual ~ScreenSaver();
    static ScreenSaver &Instance();


    void add(Shape *shape);

    void next();

    void draw();

    Shape *get(int n);

    Shape *getLast();
};


#endif //ALLEGRO_SCREENSAVER_H
