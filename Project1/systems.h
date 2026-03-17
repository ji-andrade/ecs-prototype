#pragma once
#include "factory.h"
#include <iostream>

inline std::string describePhysical(const World& world, ID id)
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

inline std::string describePersonality(const World& world, ID id)
{
    std::string desc;

    desc += "By nature he is " + toString(world.temperamentMap.at(id).curr) + ", ";
    desc += "and " + toString(world.socialMap.at(id).curr) + ".\n";
    desc += toString(world.driveMap.at(id).curr) + ", ";
    desc += "and " + toString(world.bearingMap.at(id).curr) + ".\n";

    return desc;
}

inline std::string describeDisposition(const World& world, ID id)
{
    std::string desc;

    desc += "He " + toString(world.hobbyMap.at(id).curr) + ". ";
    desc += "He " + toString(world.fearMap.at(id).curr) + ". ";
    desc += "Above all he " + toString(world.desireMap.at(id).curr) + ".";

    return desc;
}

inline std::string describePerson(const World& world, ID id)
{
    std::string desc;
    desc += describePhysical(world, id) + "\n";
    desc += describePersonality(world, id) + "\n";
    desc += describeDisposition(world, id) + "\n";
    return desc;
}

inline void printPerson(const World& world, int input)
{
    if (!world.nameMap.count(input))
    {
        std::cout << "No person with that ID.\n";
        return;
    }
    std::cout << describePerson(world, input) << "\n";
}

//temporary
inline void printGeneral(const World& world)
{
    system("cls");
    std::cout << "Number of persons: " << world.nameMap.size() << "\n";
    for (auto& [id, name] : world.nameMap)
        std::cout << id << " " << world.nameMap.at(id).val << " \n";
}

inline int playerInput()
{
    int input{};
    std::cout << "\nWhich person do you wish to see?\n";
    std::cin >> input;
    system("cls");
    return input;
}