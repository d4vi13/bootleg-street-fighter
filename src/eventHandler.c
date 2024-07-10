#include "mainHeader.h"
#include "core.h"

void DequeueEvent(){
    
    al_wait_for_event(GameCore.queue, &GameCore.event);
    
    return;
}
