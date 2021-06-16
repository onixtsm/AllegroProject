//
// Created by onix on 05.06.21.
//

#ifndef ALLEGRO_ALEGROAPPP_H
#define ALLEGRO_ALEGROAPPP_H


#include "AllegroBase.hpp"
#include "ScreenSaver.h"
#include "../Shapes/ControlablleSquare.h"

class AllegroApp : public AllegroBase {
private:
    ControlablleSquare playerSquare;
public:
    AllegroApp();

    void Fps();

    void Draw();
};


#endif //ALLEGRO_ALEGROAPPP_H
