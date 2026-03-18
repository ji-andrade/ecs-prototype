#include "systems.h"

void systemTime(World& world)
{
    world.currDay++;
}

void systemNeeds(World& world)
{
    //hunger
    for (auto& [id, hunger] : world.hungerMap)
    {
        if (world.currDay - hunger.lastAte < HUNGER_FED_DAYS)
        {
            hunger.curr = Hunger::Fed;
        }
        else if (world.currDay - hunger.lastAte < HUNGER_HUNGRY_DAYS)
        {
            hunger.curr = Hunger::Hungry;
        }
        else
        {
            hunger.curr = Hunger::Starving;
        }
    }
    //Thirst
    for (auto& [id, thirst] : world.thirstMap)
    {
        if (world.currDay - thirst.lastDrink < THIRST_QUENCHED_DAYS)
        {
            thirst.curr = Thirst::Quenched;
        }
        else if (world.currDay - thirst.lastDrink < THIRST_THIRSTY_DAYS)
        {
            thirst.curr = Thirst::Thirsty;
        }
        else
        {
            thirst.curr = Thirst::Parched;
        }
    }
    //Fatigue
    for (auto& [id, fatigue] : world.fatigueMap)
    {
        if (world.currDay - fatigue.lastSlept < FATIGUE_RESTED_DAYS)
        {
            fatigue.curr = Fatigue::Rested;
        }
        else if (world.currDay - fatigue.lastSlept < FATIGUE_TIRED_DAYS)
        {
            fatigue.curr = Fatigue::Tired;
        }
        else
        {
            fatigue.curr = Fatigue::Exhausted;
        }
    }
}
//health
void systemHealth(World& world)
{
    //degrade health
    for (auto& [id, health] : world.healthMap)
    {
        bool canDegrade = health.curr != Health::Dying;
        bool canImprove = health.curr != Health::Healthy;

        auto& sickness = world.sicknessMap.at(id);
        auto& hunger = world.hungerMap.at(id);
        auto& thirst = world.thirstMap.at(id);
        auto& fatigue = world.fatigueMap.at(id);

        //thirst and hunger
        if (thirst.curr == Thirst::Parched &&
            hunger.curr == Hunger::Starving &&
            canDegrade)
        {
            health.curr = static_cast<Health>(static_cast<int>(health.curr) + 1);
            sickness.wasting = true;
        }
        //hunger only
        else if (hunger.curr == Hunger::Starving && 
            canDegrade && randomInt(0, 3) == 0)
        {
            health.curr = static_cast<Health>(static_cast<int>(health.curr) + 1);
            sickness.malnourished = true;
        }
        //thirst only
        else if (thirst.curr == Thirst::Parched && 
            canDegrade && randomInt(0, 3) == 0)
        {
            health.curr = static_cast<Health>(static_cast<int>(health.curr) + 1);
            sickness.dehydrated = true;

        }      
        //fatigue only
        else if (fatigue.curr == Fatigue::Exhausted && 
            canDegrade && randomInt(0, 5) == 0)
        {
            health.curr = static_cast<Health>(static_cast<int>(health.curr) + 1);
            sickness.delirious = true;
        }

        //recovery 
        
        //thirst and hunger
        else if (thirst.curr == Thirst::Quenched &&
            hunger.curr == Hunger::Fed &&
            canImprove && randomInt(0, 9) == 0)
        {
            health.curr = static_cast<Health>(static_cast<int>(health.curr) - 1);
            sickness.wasting = false;
            sickness.malnourished = false;
            sickness.dehydrated = false;
        }
        //hunger only
        else if (hunger.curr == Hunger::Fed &&
            canImprove && randomInt(0, 9) == 0)
        {
            health.curr = static_cast<Health>(static_cast<int>(health.curr) - 1);
            if (sickness.wasting)
            {
                sickness.wasting = false;
                sickness.dehydrated = true;
            }
            else if (sickness.malnourished)
            {
                sickness.malnourished = false;
            }

        }
        //thirst only
        else if (thirst.curr == Thirst::Quenched &&
            canImprove && randomInt(0, 9) == 0)
        {
            health.curr = static_cast<Health>(static_cast<int>(health.curr) - 1);
            if (sickness.wasting)
            {
                sickness.wasting = false;
                sickness.malnourished = true;
            }
            else if (sickness.dehydrated)
            {
                sickness.dehydrated = false;
            }
        }
        //fatigue only
        else if (fatigue.curr == Fatigue::Rested &&
            canImprove && randomInt(0, 18) == 0)
        {
            health.curr = static_cast<Health>(static_cast<int>(health.curr) - 1);
            if (sickness.delirious)
            {
                sickness.delirious = false;
            }
        }
    }
}

//need to add thirst and hunger affect morale
void systemMorale(World& world)
{
    for (auto& [id, morale] : world.moraleMap)
    {
        auto& thirst = world.thirstMap.at(id);
        auto& hunger = world.hungerMap.at(id);
        auto& fatigue = world.fatigueMap.at(id);
        auto& sickness = world.sicknessMap.at(id);
        auto& health = world.healthMap.at(id);

        if (health.curr == Health::Healthy)
        {
            morale.curr = Morale::Steady;
            if (thirst.curr == Thirst::Quenched &&
                hunger.curr == Hunger::Fed &&
               fatigue.curr == Fatigue::Rested &&
                randomInt(0, 4) == 0)
            {
                morale.curr = Morale::Inspired;
            }
        }
        else if (health.curr == Health::Ailing)
        {
            morale.curr = Morale::Anxious;
            if (sickness.feverish  ||
                sickness.scurvy    ||
                sickness.dysentery ||
                sickness.wasting)  
             
            {
                morale.curr = Morale::Broken;
            }
        }
        else if (health.curr == Health::Dying)
        {
            morale.curr = Morale::Broken;
        }
    }
}
// needs to have cure scurvy
//currently no vitamin C system
static void updateScurvy(World& world)
{
    for (auto& [id, sickness] : world.sicknessMap)
    {
        auto& fatigue = world.fatigueMap.at(id);
        auto& health = world.healthMap.at(id);
        auto& teeth = world.teethMap.at(id);

        if (!teeth.ateLemon && !sickness.scurvy)
        {
            sickness.scurvy = true;
            sickness.scurvyStart = world.currDay;
        }
        else if (sickness.scurvy)
        {
            //14 to 30 day
            if (world.currDay - sickness.scurvyStart > SCURVY_EARLY_DAYS &&
                world.currDay - sickness.scurvyStart <= SCURVY_LATE_DAYS)
            {
                if (randomInt(0, 14) == 0)
                {
                    fatigue.lastSlept = world.currDay - 4;
                }

                if (randomInt(0, 9) == 0 && health.curr != Health::Dying)
                {
                    health.curr = static_cast<Health>(static_cast<int>(health.curr) + 1);
                }
            }
            //after 30 days
            else if (world.currDay - sickness.scurvyStart > SCURVY_LATE_DAYS)
            {
                if (randomInt(0, 9) == 0 && teeth.num > 0)
                {
                    teeth.num--;
                }
                if (randomInt(0, 6) == 0)
                {
                    fatigue.lastSlept = world.currDay - 4;
                }

                if (randomInt(0, 5) == 0 && health.curr != Health::Dying)
                {
                    health.curr = static_cast<Health>(static_cast<int>(health.curr) + 1);
                }
            }
        }
    }
}

void systemDisease(World& world)
{
    updateScurvy(world);
}