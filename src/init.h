#ifndef INIT_H
#define INIT_H

#include "mainHeader.h"
#include "core.h"

#define GAME_CONFIG_FILE "config/gameConfigs.cfg"

extern void GameSetup(PCORE GameCore);

extern void GameShutdown(PCORE GameCore);

#endif
