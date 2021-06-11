//
// Created by onix on 07.06.21.
//

#include "ShapeFactory.h"
#include "Circle.h"
#include "Rect.h"
#include "Square.h"


Shape * ShapeFactory::Create(Type type) {
    switch (type) {
        case RandomCircle:
            return new Circle(10 + rand() % 30);
        case RandomRect:
            return new Rect(10 + rand() % 30, 10 + rand() % 30);
        case RandomSquare:
            return new Square(10 + rand() % 30);

    }
}