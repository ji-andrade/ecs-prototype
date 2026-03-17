#include "describe.h"

std::string describePhysical(const World& world, ID id)
{
    std::string desc;

    desc += world.nameMap.at(id).val + " is a " + std::to_string(world.ageMap.at(id).curr) + " years old ";
    desc += toString(world.jobMap.at(id).curr) + ".\n";
    desc += toString(world.physicalMap.at(id).build) + ", ";
    desc += toString(world.jawMap.at(id).shape) + ".\n";
    desc += "He has " + toString(world.eyesMap.at(id).shape) + ", ";
    desc += toString(world.noseMap.at(id).shape) + ".\n";
    desc += toString(world.hairMap.at(id).style) + ".\n";

    return desc;
}

std::string describePersonality(const World& world, ID id)
{
    std::string desc;

    desc += "By nature he is " + toString(world.temperamentMap.at(id).curr) + ", ";
    desc += "and " + toString(world.socialMap.at(id).curr) + ".\n";
    desc += toString(world.driveMap.at(id).curr) + ", ";
    desc += "and " + toString(world.bearingMap.at(id).curr) + ".\n";

    return desc;
}

std::string describeDisposition(const World& world, ID id)
{
    std::string desc;

    desc += "He " + toString(world.hobbyMap.at(id).curr) + ". ";
    desc += "He " + toString(world.fearMap.at(id).curr) + ". ";
    desc += "Above all he " + toString(world.desireMap.at(id).curr) + ".";

    return desc;
}

std::string describeStatus(const World& world, ID id)
{
    std::string desc;

    desc += "He is " + toString(world.healthMap.at(id).curr) + ". ";
    desc += toString(world.sicknessMap.at(id).curr) + ". ";
    desc += toString(world.woundMap.at(id).curr) + ". ";
    desc += "He is " + toString(world.moraleMap.at(id).curr) + ". ";
    desc += "He is " + toString(world.hungerMap.at(id).curr) + ", ";
    desc += toString(world.thirstMap.at(id).curr) + ", ";
    desc += "and " + toString(world.fatigueMap.at(id).curr) + ".";

    return desc;
}

std::string describePerson(const World& world, ID id)
{
    std::string desc;
    desc += describePhysical(world, id) + "\n";
    desc += describePersonality(world, id) + "\n";
    desc += describeDisposition(world, id) + "\n\n";
    desc += describeStatus(world, id) + "\n";
    return desc;
}