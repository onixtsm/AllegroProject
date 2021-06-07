//
// Created by onix on 05.06.21.
//

#include "AlegroAppp.h"
#include "ShapeFactory.h"


int speed = 10;

AllegroApp::AllegroApp() :
        AllegroBase(),
        playerSquare(30)
{
    for (int i = 0; i < MAX; i++) {
        if ((i % 2) == 0) {
            ScreenSaver::Instance().add(ShapeFactory::Create(ShapeFactory::RandomCircle));
        } else {
            ScreenSaver::Instance().add(ShapeFactory::Create(ShapeFactory::RandomSquare));
        }
        ScreenSaver::Instance().add(&playerSquare);

    }
}

void AllegroApp::Fps() {
    playerSquare.setVx(0);
    playerSquare.setVy(0);
    if (IsPressed(ALLEGRO_KEY_J)) {
        playerSquare.setVy(speed);
    }
    if (IsPressed(ALLEGRO_KEY_K)) {
        playerSquare.setVy(-speed);
    }
    if (IsPressed(ALLEGRO_KEY_H)) {
        playerSquare.setVx(-speed);
    }
    if (IsPressed(ALLEGRO_KEY_L)) {
        playerSquare.setVx(speed);
    }
    ScreenSaver::Instance().next();
//    playerSquare.move(vx, vy);
}

void AllegroApp::Draw() {
    ScreenSaver::Instance().draw();
    playerSquare.draw();
}
