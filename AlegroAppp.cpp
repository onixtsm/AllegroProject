//
// Created by onix on 05.06.21.
//

#include "AlegroAppp.h"
#include "ShapeFactory.h"

AllegroApp::AllegroApp() :
        AllegroBase(),
        playerSquare(30) {
    for (int i = 0; i < MAX; i++) {
        if ((i % 2) == 0) {
            ScreenSaver::Instance().add(ShapeFactory::Create(ShapeFactory::RandomCircle));
        } else {
            ScreenSaver::Instance().add(ShapeFactory::Create(ShapeFactory::RandomSquare));
        }

    }
}

void AllegroApp::Fps() {
    double vx = 0, vy = 0;
    ScreenSaver::Instance().next();
    if (IsPressed(ALLEGRO_KEY_J)) {
        vy = 1;
    }
    if (IsPressed(ALLEGRO_KEY_K)) {
        vy = -1;
    }
    if (IsPressed(ALLEGRO_KEY_H)) {
        vx = -1;
    }
    if (IsPressed(ALLEGRO_KEY_L)) {
        vx = 1;
    }
    playerSquare.move(vx, vy);
}

void AllegroApp::Draw() {
    ScreenSaver::Instance().draw();
}
