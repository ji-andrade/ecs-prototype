#pragma once
#include "world.h"
#include "utils.h"

inline void makePerson(World& world)
{
	for(int i = 0; i < 10; i++)
	{
		ID id = world.nextID++;
		//Basic 
		world.nameMap[id] = { readFile("names.txt") };
		world.ageMap[id] = { randomInt(18, 50) };
		//Assign random physical traits
		world.physicalMap[id] = { static_cast<Physic>(randomInt(0, static_cast<int>(Physic::Count) - 1)) };
		world.eyesMap[id] = { static_cast<Eyes>(randomInt(0, static_cast<int>(Eyes::Count) - 1)) };
		world.noseMap[id] = { static_cast<Nose>(randomInt(0, static_cast<int>(Nose::Count) - 1)) };
		world.hairMap[id] = { static_cast<Hair>(randomInt(0, static_cast<int>(Hair::Count) - 1)) };
		world.jawMap[id]  = { static_cast<Jaw>(randomInt(0, static_cast<int>(Jaw::Count) - 1)) };
		world.skinMap[id] = { static_cast<Skin>(randomInt(0, static_cast<int>(Skin::Count) - 1)) };
		world.browMap[id] = { static_cast<Brow>(randomInt(0, static_cast<int>(Brow::Count) - 1)) };
		world.jobMap[id] =  { static_cast<Job>(randomInt(0, static_cast<int>(Job::Count) - 1)) };
		//Assign random personality traits
		world.temperamentMap[id] = { static_cast<Temperament>(randomInt(0, static_cast<int>(Temperament::Count) - 1)) };
		world.socialMap[id] =      { static_cast<Social>     (randomInt(0, static_cast<int>(Social::Count) - 1)) };
		world.driveMap[id] =       { static_cast<Drive>      (randomInt(0, static_cast<int>(Drive::Count) - 1)) };
		world.bearingMap[id] =     { static_cast<Bearing>    (randomInt(0, static_cast<int>(Bearing::Count) - 1)) };
	}
}