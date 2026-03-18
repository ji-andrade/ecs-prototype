#pragma once
#include "../systems/systems.h"
#include "toString.h"

std::string describePhysical(const World& world, ID id);
std::string describePersonality(const World& world, ID id);
std::string describeDisposition(const World& world, ID id);
std::string describeStatus(const World& world, ID id);
std::string describePerson(const World& world, ID id);
std::string describeHealth(const World& world, ID id);