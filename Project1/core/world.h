#pragma once
#include "components.h"
#include <unordered_map>

struct World {

	//id counter
	ID nextID = 0;
	//new time system
	Time time = { 1, 1600, DaysOfWeek::Wednesday, MonthsOfYear::January };
	//Basic
	std::unordered_map<ID, Name>         nameMap;
	std::unordered_map<ID, Age>          ageMap;
	//Physical 	     
	std::unordered_map<ID, SPhysic>      physicalMap;
	std::unordered_map<ID, SEyes>        eyesMap;
	std::unordered_map<ID, SNose>        noseMap;
	std::unordered_map<ID, SHair>        hairMap;
	std::unordered_map<ID, SJaw>         jawMap;
	std::unordered_map<ID, SSkin>        skinMap;
	std::unordered_map<ID, SBrow>        browMap;
	std::unordered_map<ID, SJob>         jobMap;
	std::unordered_map<ID, STeeth>       teethMap;
	//Personality 
	std::unordered_map<ID, STemperament> temperamentMap;
	std::unordered_map<ID, SSocial>      socialMap;
	std::unordered_map<ID, SDrive>       driveMap;
	std::unordered_map<ID, SBearing>     bearingMap;
	//Disposition
	std::unordered_map<ID, SHobby>       hobbyMap;
	std::unordered_map<ID, SFear>        fearMap;
	std::unordered_map<ID, SDesire>      desireMap;
	//Status 
	std::unordered_map<ID, SHealth>      healthMap;
	std::unordered_map<ID, SSickness>    sicknessMap;
	std::unordered_map<ID, SWound>       woundMap;
	std::unordered_map<ID, SMorale>      moraleMap;
	std::unordered_map<ID, SHunger>      hungerMap;
	std::unordered_map<ID, SThirst>      thirstMap;
	std::unordered_map<ID, SFatigue>     fatigueMap;
};
