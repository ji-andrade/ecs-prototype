#include "systems.h"


void printPerson(const World& world, int input)
{
    if (!world.nameMap.count(input))
    {
        std::cout << "No person with that ID.\n";
        return;
    }
    std::cout << describePerson(world, input) << "\n";
}

//temporary
void printGeneral(const World& world)
{
    system("cls");
    std::cout << "Day " << world.currDay << "\n\n";
    //std::cout << "Type a number for the person you wish to see" << "\n";
    for (auto& [id, name] : world.nameMap)
        std::cout << id << " " << world.nameMap.at(id).val << " \n";
}

int playerInput()
{
    int input{};
    std::cin >> input;
    system("cls");
    return input;
}

void systemTime(World& world)
{
    world.currDay++;
}

void systemHunger(World& world)
{
    for (auto& [id, hunger] : world.hungerMap)
    {
        if (world.currDay - hunger.lastAte < 1)
        {
            world.hungerMap[id].curr = Hunger::Fed;
        }
        else if (world.currDay - hunger.lastAte < 4)
        {
            world.hungerMap[id].curr = Hunger::Hungry;
        }
        else 
        {
            world.hungerMap[id].curr = Hunger::Starving;
        }
    }
}

void systemThirst(World& world)
{
    for (auto& [id, thirst] : world.thirstMap)
    {
        if (world.currDay - thirst.lastDrink < 1)
        {
            world.thirstMap[id].curr = Thirst::Quenched;
        }
        else if (world.currDay - thirst.lastDrink < 3)
        {
            world.thirstMap[id].curr = Thirst::Thirsty;
        }
        else
        {
            world.thirstMap[id].curr = Thirst::Parched;
        }
    }
}

void systemFatigue(World& world)
{
    for (auto& [id, fatigue] : world.fatigueMap)
    {
        if (world.currDay - fatigue.lastSlept < 1)
        {
            world.fatigueMap[id].curr = Fatigue::Rested;
        }
        else if (world.currDay - fatigue.lastSlept < 3)
        {
            world.fatigueMap[id].curr = Fatigue::Tired;
        }
        else
        {
            world.fatigueMap[id].curr = Fatigue::Exhausted;
        }
    }
}

void systemHealth(World& world)
{
    //degrade health
    for (auto& [id, health] : world.healthMap)
    {
        bool canDegrade = health.curr != Health::Dying;

        if (world.thirstMap.at(id).curr == Thirst::Parched &&
            world.hungerMap.at(id).curr == Hunger::Starving &&
            canDegrade)
        {
            health.curr = static_cast<Health>(static_cast<int>(health.curr) + 1);
            world.sicknessMap[id].curr = Sickness::Wasting;
        }
        else if (world.hungerMap.at(id).curr == Hunger::Starving && 
            canDegrade && randomInt(0, 3) == 0)
        {
            health.curr = static_cast<Health>(static_cast<int>(health.curr) + 1);
            world.sicknessMap[id].curr = Sickness::Malnourished;
        }
        else if (world.thirstMap.at(id).curr == Thirst::Parched && 
            canDegrade && randomInt(0, 3) == 0)
        {
            health.curr = static_cast<Health>(static_cast<int>(health.curr) + 1);
            world.sicknessMap[id].curr = Sickness::Dehydrated;

        }      
        else if (world.fatigueMap.at(id).curr == Fatigue::Exhausted && 
            canDegrade && randomInt(0, 5) == 0)
        {
            health.curr = static_cast<Health>(static_cast<int>(health.curr) + 1);
            world.sicknessMap[id].curr = Sickness::Delirious;
        }
    }
    //improve health
    for (auto& [id, health] : world.healthMap)
    {
        bool canImprove = health.curr != Health::Healthy;

        if (world.thirstMap.at(id).curr == Thirst::Quenched &&
            world.hungerMap.at(id).curr == Hunger::Fed &&
            canImprove && randomInt(0, 9) == 0)
        {
            health.curr = static_cast<Health>(static_cast<int>(health.curr) - 1);
            world.sicknessMap[id].curr = Sickness::None;
        }
        else if (world.hungerMap.at(id).curr == Hunger::Fed && 
            canImprove && randomInt(0, 9) == 0)
        {
            health.curr = static_cast<Health>(static_cast<int>(health.curr) - 1);
            if (world.sicknessMap[id].curr == Sickness::Malnourished)
            {
                world.sicknessMap[id].curr = Sickness::None;
            }

        }
        else if (world.thirstMap.at(id).curr == Thirst::Quenched && 
            canImprove && randomInt(0, 9) == 0)
        {
            health.curr = static_cast<Health>(static_cast<int>(health.curr) - 1);
            if (world.sicknessMap[id].curr == Sickness::Dehydrated)
            {
                world.sicknessMap[id].curr = Sickness::None;
            }
        }
        else if (world.fatigueMap.at(id).curr == Fatigue::Rested && 
            canImprove && randomInt(0, 18) == 0)
        {
            health.curr = static_cast<Health>(static_cast<int>(health.curr) - 1);
            if (world.sicknessMap[id].curr == Sickness::Delirious)
            {
                world.sicknessMap[id].curr = Sickness::None;
            }
        }
    }
}