#pragma once
#include "../core/factory.h"
#include "../core/constants.h"
#include "../data/describe.h"
//#include <iostream>

//systems new
void systemTime(World& world);

void systemNeeds(World& world);
static void systemHunger(World& world);
static void systemThirst(World& world);
static void systemFatigue(World& world);

void systemHealth(World& world);
void systemMorale(World& world);

void systemDisease(World& world);
static void updateScurvy(World& world);