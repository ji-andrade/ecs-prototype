#pragma once
#include <curses.h>
#include <sstream>
#include "../systems/systems.h"

enum class Menu { mainMenu, personMenu, quit };

void cursesPerson(World& world, Menu& currentMenu);
void mainCurses(World& world);
void cursesMainMenu(Menu& currentMenu);