#include "init.h"


static inline BOOL InitDependecies(){
    BOOL InitStatus;
    InitStatus = al_init();
    InitStatus &= al_init_image_addon();

    //TODO: move this function to a apropriate place
    InitStatus &= al_install_keyboard();

    return InitStatus;
}

static inline PRESOLUTION GetDefaultResolution(){
    PRESOLUTION res = malloc(sizeof * res);
    GameCore.config = al_load_config_file(GAME_CONFIG_FILE);
    res->px = atoi(al_get_config_value(GameCore.config, "resolution", "px"));
    res->py = atoi(al_get_config_value(GameCore.config, "resolution", "py"));

    return res;
}

static inline ALLEGRO_DISPLAY* sf_create_display(){
    
    PRESOLUTION GameRes = GetDefaultResolution();

    return al_create_display(GameRes->px,GameRes->py);
}

static inline double GetDefaultFrameRate(){
    double fps = atof(al_get_config_value(GameCore.config, "", "fps"));

    return FrameDuration(fps);

}

static inline ALLEGRO_TIMER* sf_create_timer(){
    double FrameDuration = GetDefaultFrameRate();
    
    return al_create_timer(FrameDuration);
}


static inline void GameCoreInit(PCORE GameCore){
    GameCore->config = al_load_config_file(GAME_CONFIG_FILE);
    GameCore->timer = sf_create_timer();
    GameCore->display = sf_create_display();
    GameCore->queue = al_create_event_queue();
    GameCore->font = sf_create_font();

    GameCore->GameState = MAIN_MENU;
}

 static inline void RegisterEventSources(PCORE GameCore){
    
    al_register_event_source(GameCore->queue, al_get_keyboard_event_source());
    al_register_event_source(GameCore->queue, al_get_display_event_source(GameCore->display));
    al_register_event_source(GameCore->queue, al_get_timer_event_source(GameCore->timer));
}

void GameSetup(PCORE GameCore){
    
    (void)InitDependecies();
    
    GameCoreInit(GameCore);

    RegisterEventSources(GameCore);

    return;
}

void GameShutdown(PCORE GameCore){

    al_destroy_font(GameCore->font);
    al_destroy_display(GameCore->display);
    al_destroy_timer(GameCore->timer);
    al_destroy_event_queue(GameCore->queue);
    al_destroy_config(GameCore->config);
    return ;
}



