#include "describe.h"

std::string describePhysical(const World& world, ID id)
{
    std::string desc;

    
    desc += world.nameMap.at(id).val + " is a " + std::to_string(world.ageMap.at(id).curr) + " years old ";
    desc += toString(world.jobMap.at(id).curr) + ".\n";
    desc += "\nPhysical\n" ;
    desc += toString(world.physicalMap.at(id).build) + ", ";
    desc += toString(world.jawMap.at(id).shape) + ".\n";
    desc += "His mouth reveals " + toString(world.teethMap.at(id).cond) + ".";
    desc += " Currently has " + std::to_string(world.teethMap.at(id).num) + " teeth.\n";
    desc += "He has " + toString(world.eyesMap.at(id).shape) + ", ";
    desc += toString(world.noseMap.at(id).shape) + ".\n";
    desc += toString(world.hairMap.at(id).style) + ".\n";

    return desc;
}

std::string describePersonality(const World& world, ID id)
{
    std::string desc;
    desc += "\nPersonality\n";
    desc += "By nature he is " + toString(world.temperamentMap.at(id).curr) + ", ";
    desc += "and " + toString(world.socialMap.at(id).curr) + ".\n";
    desc += toString(world.driveMap.at(id).curr) + ", ";
    desc += "and " + toString(world.bearingMap.at(id).curr) + ".\n";

    return desc;
}

std::string describeDisposition(const World& world, ID id)
{
    std::string desc;
    desc += "\nDisposition\n";
    desc += "He " + toString(world.hobbyMap.at(id).curr) + ". ";
    desc += "He " + toString(world.fearMap.at(id).curr) + ". ";
    desc += "Above all he " + toString(world.desireMap.at(id).curr) + ".";

    return desc;
}

std::string describeStatus(const World& world, ID id)
{
    std::string desc;

    desc += "\Current status\n";
    desc += "He is " + toString(world.moraleMap.at(id).curr) + ". ";
    desc += "He is " + toString(world.hungerMap.at(id).curr) + ", ";
    desc += toString(world.thirstMap.at(id).curr) + ", ";
    desc += "and " + toString(world.fatigueMap.at(id).curr) + ".";

    return desc;
}
//new
std::string describeHealth(const World& world, ID id)
{
    std::string desc;
    
    desc += "He is " + toString(world.healthMap.at(id).curr) + ". ";

    auto& s = world.sicknessMap.at(id);

    if (s.scurvy)      
    {
        int duration = world.currDay - s.scurvyStart;
        if (duration < 14)
            desc += "his gums are tender and bleeding, the first signs of scurvy taking hold.\n";
        else
            desc += "riddled with scurvy, his gums black and his joints screaming.\n";
    }
    if (s.dysentery)   desc += "Hollowed out by dysentery, too weak to stand for long. \n";
    if (s.feverish)    desc += "Burning with fever, his eyes glassy and distant.\n";
    if (s.malnourished) desc += "Malnourished, his body beginning to turn on itself.\n";
    if (s.dehydrated)  desc += "Dehydrated, his skin tight and his mind starting to slip.\n";
    if (s.wasting)     desc += "Wasting away, starved of both food and water, not long for this world.\n";
    if (s.delirious)   desc += "Delirious from exhaustion, seeing things that are not there.\n";

    return desc;
}

std::string describePerson(const World& world, ID id)
{
    std::string desc;
    desc += describePhysical(world, id) + "\n";
    desc += describePersonality(world, id) + "\n";
    desc += describeDisposition(world, id) + "\n\n";
    desc += describeStatus(world, id) + "\n";
    desc += describeHealth(world, id) + "\n";
    return desc;
}