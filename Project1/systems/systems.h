#pragma once
#include "../core/factory.h"
#include "../core/constants.h"
#include "../data/describe.h"
//#include <iostream>

//systems new
void systemTime(World& world);


void systemNeeds(World& world);


void systemHealth(World& world);


void systemMorale(World& world);


static void updateScurvy(World& world);
void systemDisease(World& world);