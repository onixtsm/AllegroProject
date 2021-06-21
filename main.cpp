#include <iostream>
#include "Allegro/AllegroBase.hpp"
#include "Allegro/AlegroAppp.h"


using namespace std;



int main(int argc, char **argv) {

    cout << "Made by" << endl;
    cout << "             _\n"
            "  ___  _ __ (_)_  __\n"
            " / _ \\| '_ \\| \\ \\/ /\n"
            "| (_) | | | | |>  <\n"
            " \\___/|_| |_|_/_/\\_\\" << endl;

    srand( time(0));

    AllegroApp app;

    if ( !app.Init(SCREEN_W, SCREEN_H, FPS)) {
        app.Destroy();
        return 1;
    }

    app.Run();
    sleep(60);
    app.Exit();
    return 0;
}


