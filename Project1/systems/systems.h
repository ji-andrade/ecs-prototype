#pragma once
#include "../core/factory.h"
#include "../data/describe.h"
#include <iostream>

void printPerson(const World& world, int input);

//temporary
void printGeneral(const World& world);
int playerInput();

//systems new
void systemTime(World& world);
void systemHunger(World& world);
void systemThirst(World& world);
void systemFatigue(World& world);
void systemHealth(World& world);