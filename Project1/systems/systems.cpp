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

//start here
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
        bool canImprove = health.curr != Health::Healthy;
        //thirst and hunger
        if (world.thirstMap.at(id).curr == Thirst::Parched &&
            world.hungerMap.at(id).curr == Hunger::Starving &&
            canDegrade)
        {
            health.curr = static_cast<Health>(static_cast<int>(health.curr) + 1);
            world.sicknessMap[id].curr = Sickness::Wasting;
        }
        //hunger only
        else if (world.hungerMap.at(id).curr == Hunger::Starving && 
            canDegrade && randomInt(0, 3) == 0)
        {
            health.curr = static_cast<Health>(static_cast<int>(health.curr) + 1);
            world.sicknessMap[id].curr = Sickness::Malnourished;
        }
        //thirst only
        else if (world.thirstMap.at(id).curr == Thirst::Parched && 
            canDegrade && randomInt(0, 3) == 0)
        {
            health.curr = static_cast<Health>(static_cast<int>(health.curr) + 1);
            world.sicknessMap[id].curr = Sickness::Dehydrated;

        }      
        //fatigue only
        else if (world.fatigueMap.at(id).curr == Fatigue::Exhausted && 
            canDegrade && randomInt(0, 5) == 0)
        {
            health.curr = static_cast<Health>(static_cast<int>(health.curr) + 1);
            world.sicknessMap[id].curr = Sickness::Delirious;
        }

        //recovery 
        
        //thirst and hunger
        else if (world.thirstMap.at(id).curr == Thirst::Quenched &&
            world.hungerMap.at(id).curr == Hunger::Fed &&
            canImprove && randomInt(0, 9) == 0)
        {
            health.curr = static_cast<Health>(static_cast<int>(health.curr) - 1);
            world.sicknessMap[id].curr = Sickness::None;
        }
        //hunger only
        else if (world.hungerMap.at(id).curr == Hunger::Fed &&
            canImprove && randomInt(0, 9) == 0)
        {
            health.curr = static_cast<Health>(static_cast<int>(health.curr) - 1);
            if (world.sicknessMap.at(id).curr == Sickness::Wasting)
            {
                world.sicknessMap[id].curr = Sickness::Dehydrated;
            }
            else if (world.sicknessMap.at(id).curr == Sickness::Malnourished)
            {
                world.sicknessMap[id].curr = Sickness::None;
            }

        }
        //thirst only
        else if (world.thirstMap.at(id).curr == Thirst::Quenched &&
            canImprove && randomInt(0, 9) == 0)
        {
            health.curr = static_cast<Health>(static_cast<int>(health.curr) - 1);
            if (world.sicknessMap.at(id).curr == Sickness::Wasting)
            {
                world.sicknessMap[id].curr = Sickness::Malnourished;
            }
            else if (world.sicknessMap.at(id).curr == Sickness::Dehydrated)
            {
                world.sicknessMap[id].curr = Sickness::None;
            }
        }
        //fatigue only
        else if (world.fatigueMap.at(id).curr == Fatigue::Rested &&
            canImprove && randomInt(0, 18) == 0)
        {
            health.curr = static_cast<Health>(static_cast<int>(health.curr) - 1);
            if (world.sicknessMap.at(id).curr == Sickness::Delirious)
            {
                world.sicknessMap[id].curr = Sickness::None;
            }
        }
    }
}

void systemMorale(World& world)
{
    for (auto& [id, morale] : world.moraleMap)
    {
        if (world.healthMap.at(id).curr == Health::Healthy)
        {
            morale.curr = Morale::Steady;
        }
        else if (world.healthMap.at(id).curr == Health::Ailing)
        {
            morale.curr = Morale::Anxious;
            if (world.sicknessMap.at(id).curr != Sickness::None &&
                static_cast<int>(world.healthMap.at(id).curr) >= 1)
            {
                morale.curr = Morale::Broken;
            }
        }
        else if (world.healthMap.at(id).curr == Health::Dying)
        {
            morale.curr = Morale::Broken;
        }
    }
}

//for funsies 
// needs to have cure

void systemScurvy(World& world)
{
    for (auto& [id, sickness] : world.sicknessMap)
    {
        if (world.teethMap.at(id).ateLemon == false && 
            sickness.curr != Sickness::Scurvy)
        {
            sickness.curr = Sickness::Scurvy;
            sickness.start = world.currDay;
        }
        else if (sickness.curr == Sickness::Scurvy)
        {
            //14 to 30 day
            if (world.currDay - sickness.start > 14 && world.currDay - sickness.start <= 30)
            {
                if (randomInt(0, 14) == 0)
                {
                    world.fatigueMap[id].lastSlept = world.currDay - 4;
                }

                if (randomInt(0, 9) == 0 && world.healthMap.at(id).curr != Health::Dying)
                {
                    world.healthMap[id].curr = static_cast<Health>(static_cast<int>(world.healthMap.at(id).curr) + 1);
                }
            }
            //after 30 days
            if (world.currDay - sickness.start > 30)
            {
                if (randomInt(0, 9) == 0 && world.teethMap.at(id).num >= 0)
                {
                    world.teethMap[id].num--;
                }
                if (randomInt(0, 6) == 0)
                {
                    world.fatigueMap[id].lastSlept = world.currDay - 4;
                }

                if (randomInt(0, 5) == 0 && world.healthMap.at(id).curr != Health::Dying)
                {
                    world.healthMap[id].curr = static_cast<Health>(static_cast<int>(world.healthMap.at(id).curr) + 1);
                }
            }
        }
    }
}