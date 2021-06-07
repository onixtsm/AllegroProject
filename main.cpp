#include <iostream>
#include "AllegroBase.hpp"
#include "AlegroAppp.h"


using namespace std;



int main(int argc, char **argv) {

    srand( time(0));

    AllegroApp app;

    if ( !app.Init(SCREEN_W, SCREEN_H, FPS)) {
        app.Destroy();
        return 1;
    }

    app.Run();
    sleep(60);
    return 0;
}


