//
// Created by onix on 05.06.21.
//

#include "AlegroAppp.h"
#include "../Factories/ShapeFactory.h"
#include "../config.h"
#include <algorithm>

using namespace std;


int speed = 10;

AllegroApp::AllegroApp() :
        AllegroBase(),
        playerSquare(30) {

    for (_List_const_iterator<shape_skeleton> it = ShapeArray.begin(); it != ShapeArray.end(); it++) {
        ScreenSaver::Instance().add(ShapeFactory::Create(*it));
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
    if (IsPressed(ALLEGRO_KEY_F5)) {
       ScreenSaver::Instance().toFile();
    }
    ScreenSaver::Instance().next();
//    playerSquare.move(vx, vy);
}

void AllegroApp::Draw() {
    ScreenSaver::Instance().draw();
}
