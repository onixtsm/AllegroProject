//
// Created by onix on 05.06.21.
//

#ifndef ALLEGRO_SCREENSAVER_H
#define ALLEGRO_SCREENSAVER_H


#include "Shape.h"
#include <vector>
#include <ostream>
#include <memory>

const int MAX = 100;

typedef std::shared_ptr<Shape> SPShape;


class ScreenSaver {
private:
    std::vector<SPShape> shapes;
    int size_;
    ScreenSaver();

    static bool overlap(std::shared_ptr<Shape> a, std::shared_ptr<Shape> b);
public:

    virtual ~ScreenSaver();
    static ScreenSaver &Instance();


    void add(Shape *shape);

    void next();

    void draw();

    std::shared_ptr<Shape> get(int n);

    std::shared_ptr<Shape> getLast();

    void toFile();

};


#endif //ALLEGRO_SCREENSAVER_H
