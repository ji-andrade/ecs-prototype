#pragma once
#include <curses.h>
#include <sstream>
#include <windows.h>
#include "../systems/systems.h"

enum class Menu { mainMenu, personMenu, gameMenu, quit };

void setConsoleFont(int size);

void mainCurses(World& world);
void cursesMainMenu(Menu& currentMenu);
void cursesGameMenu(World& world, Menu& currentMenu);
void cursesPersonMenu(World& world, Menu& currentMenu);