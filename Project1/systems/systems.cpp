#include "systems.h"

void systemTick(World& world)
{
    systemTime(world);
    systemNeeds(world);
    systemHealth(world);
    systemMorale(world);
    systemDisease(world);
}

void systemTime(World& world)
{
    world.time.currDay++;
    world.time.weekDay = static_cast<DaysOfWeek>((static_cast<int>(world.time.weekDay) + 1) % 7);

    if (world.time.currDay > daysInMonth[static_cast<int>(world.time.yearMonth)])
    {
        world.time.currDay = 1;
        if (static_cast<int>(world.time.yearMonth) >= 11)
        {
            world.time.year++;
            world.time.yearMonth = MonthsOfYear::January;
        }
        else
        {
            world.time.yearMonth = static_cast<MonthsOfYear>(static_cast<int>(world.time.yearMonth) + 1);
        }
    }
}

static void systemHunger(World& world)
{
    for (auto& [id, hunger] : world.hungerMap)
    {
        if (world.time.currDay - hunger.lastAte < HUNGER_FED_DAYS)
        {
            hunger.curr = Hunger::Fed;
        }
        else if (world.time.currDay - hunger.lastAte < HUNGER_HUNGRY_DAYS)
        {
            hunger.curr = Hunger::Hungry;
        }
        else
        {
            hunger.curr = Hunger::Starving;
        }
    }
}

static void systemThirst(World& world)
{
    for (auto& [id, thirst] : world.thirstMap)
    {
        if (world.time.currDay - thirst.lastDrink < THIRST_QUENCHED_DAYS)
        {
            thirst.curr = Thirst::Quenched;
        }
        else if (world.time.currDay - thirst.lastDrink < THIRST_THIRSTY_DAYS)
        {
            thirst.curr = Thirst::Thirsty;
        }
        else
        {
            thirst.curr = Thirst::Parched;
        }
    }
}

static void systemFatigue(World& world)
{
    for (auto& [id, fatigue] : world.fatigueMap)
    {
        if (world.time.currDay - fatigue.lastSlept < FATIGUE_RESTED_DAYS)
        {
            fatigue.curr = Fatigue::Rested;
        }
        else if (world.time.currDay - fatigue.lastSlept < FATIGUE_TIRED_DAYS)
        {
            fatigue.curr = Fatigue::Tired;
        }
        else
        {
            fatigue.curr = Fatigue::Exhausted;
        }
    }
}

void systemNeeds(World& world)
{
    systemHunger(world);
    systemThirst(world);
    systemFatigue(world);
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
            sickness.scurvyStart = world.time.currDay;
        }
        else if (sickness.scurvy)
        {
            //14 to 30 day
            if (world.time.currDay - sickness.scurvyStart > SCURVY_EARLY_DAYS &&
                world.time.currDay - sickness.scurvyStart <= SCURVY_LATE_DAYS)
            {
                if (randomInt(0, 14) == 0)
                {
                    fatigue.lastSlept = world.time.currDay - 4;
                }

                if (randomInt(0, 9) == 0 && health.curr != Health::Dying)
                {
                    health.curr = static_cast<Health>(static_cast<int>(health.curr) + 1);
                }
            }
            //after 30 days
            else if (world.time.currDay - sickness.scurvyStart > SCURVY_LATE_DAYS)
            {
                if (randomInt(0, 9) == 0 && teeth.num > 0)
                {
                    teeth.num--;
                }
                if (randomInt(0, 6) == 0)
                {
                    fatigue.lastSlept = world.time.currDay - 4;
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