#ifndef CORE_H
#define CORE_H

#include "mainHeader.h"

enum _GameState{
    EXIT = 0,
    MAIN_MENU,
    PLAYING,
    PAUSE_MENU,
    SETTINGS
};

typedef enum _GameState GAME_STATE, *PGAME_STATE;

struct core{
    ALLEGRO_TIMER* timer;
    ALLEGRO_EVENT_QUEUE* queue;
    ALLEGRO_DISPLAY* display;
    ALLEGRO_FONT* font;
    ALLEGRO_CONFIG* config;
    ALLEGRO_EVENT event;

    GAME_STATE GameState;
};

typedef struct core CORE, *PCORE;

struct resolution{
    unsigned int px;
    unsigned int py;
};

typedef struct resolution RESOLUTION, *PRESOLUTION;

#define FrameDuration(a) 1.0/a  

extern CORE GameCore; 

#endif 
