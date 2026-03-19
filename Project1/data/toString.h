#pragma once
#include "../systems/systems.h"
#include <string>

//Days of week and Month
std::string toString(DaysOfWeek v);
std::string toString(MonthsOfYear v);
//Physical 
std::string toString(Physic v);
std::string toString(Eyes v);
std::string toString(Nose v);
std::string toString(Hair v);
std::string toString(Jaw v);
std::string toString(Skin v);
std::string toString(Brow v);
std::string toString(Teeth v);
//Job 
std::string toString(Job v);
//Personality 
std::string toString(Temperament v);
std::string toString(Social v);
std::string toString(Drive v);
std::string toString(Bearing v);
//Disposition 
std::string toString(Hobby v);
std::string toString(Fear v);
std::string toString(Desire v);
//Status 
std::string toString(Health v);
std::string toString(Wound v);
std::string toString(Morale v);
std::string toString(Hunger v);
std::string toString(Thirst v);
std::string toString(Fatigue v);