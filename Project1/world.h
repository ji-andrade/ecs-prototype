#pragma once
#include "components.h"
#include <unordered_map>

struct World {

	//id counter
	ID nextID = 0;

	//Basic
	std::unordered_map<ID, Name>         nameMap;
	std::unordered_map<ID, Age>          ageMap;
	//Physical unordered maps		     
	std::unordered_map<ID, SPhysic>      physicalMap;
	std::unordered_map<ID, SEyes>        eyesMap;
	std::unordered_map<ID, SNose>        noseMap;
	std::unordered_map<ID, SHair>        hairMap;
	std::unordered_map<ID, SJaw>         jawMap;
	std::unordered_map<ID, SSkin>        skinMap;
	std::unordered_map<ID, SBrow>        browMap;
	std::unordered_map<ID, SJob>         jobMap;
	//Personality unordered maps
	std::unordered_map<ID, STemperament> temperamentMap;
	std::unordered_map<ID, SSocial>      socialMap;
	std::unordered_map<ID, SDrive>       driveMap;
	std::unordered_map<ID, SBearing>     bearingMap;
	//Disposition unordered maps
	std::unordered_map<ID, SHobby>       hobbyMap;
	std::unordered_map<ID, SFear>        fearMap;
	std::unordered_map<ID, SDesire>      desireMap;
};
