#include "mainHeader.h"
#include "core.h"
#include "eventHandler.h"
#include "init.h"

int main(){

    GameSetup(&GameCore);

    int i = 0;

    while (GameCore.GameState != EXIT){
        al_start_timer(GameCore.timer);
        
        DequeueEvent();

        i++;
        if (i > 5000000000)
            GameCore.GameState = EXIT;
    }

    GameShutdown(&GameCore);

    return 0;
}
