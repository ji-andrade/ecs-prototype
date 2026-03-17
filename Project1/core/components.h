#pragma once
#include <cstdint>
#include <string>

using ID = uint32_t;

//Enum Physical
enum class Physic { Lean, Average, Stocky, Count };
enum class Eyes   { Narrow, Wide, Piercing, Count };
enum class Nose   { Flat, Hooked, Bulbous, Count };
enum class Hair   { Bald, Short, Matted, Count };
enum class Jaw    { Weak, Square, Heavy, Count };
enum class Skin   { Pale, Tan, Weathered, Count };
enum class Brow   { Thick, Furrowed, Arched, Count };
enum class Job    { Doctor, Carpenter, Barber, Teacher, Count };

//Enum Personality
enum class Temperament { Calm, Irritable, Melancholic, Cheerful, Count };
enum class Social      { Withdrawn, Reserved, Friendly, Domineering, Count };
enum class Drive       { Greedy, Ambitious, Lazy, Dutiful, Count };
enum class Bearing     { Nervous, Confident, Humble, Arrogant, Count };

//Disposition 
enum class Hobby  { Fishing, Gambling, Reading, Drinking, Fighting, Count };
enum class Fear   { Sea, Heights, Death, Poverty, Solitude, Count };
enum class Desire { Wealth, Fame, Family, Freedom, Survival, Count };

// Current status 
enum class Health { Healthy, Wounded, Dying, Count };
enum class Sickness { None, Feverish, Scurvy, Dysentery, Malnourished, Dehydrated, Wasting, Delirious, Count };
enum class Wound { None, Light, Severe, Count };
enum class Morale { Steady, Anxious, Broken, Inspired, Count };
enum class Hunger { Fed, Hungry, Starving, Count };
enum class Thirst { Quenched, Thirsty, Parched, Count };
enum class Fatigue { Rested, Tired, Exhausted, Count };

//Basic 
struct Name { std::string val{}; };
struct Age  { int curr{};        };

//Structs for physical enums
struct SPhysic { Physic build; };
struct SEyes   { Eyes   shape; };
struct SNose   { Nose   shape; };
struct SHair   { Hair   style; };
struct SJaw    { Jaw    shape; };
struct SSkin   { Skin   tone;  };
struct SBrow   { Brow   shape; };
struct SJob    { Job    curr;  };

//Structs for personality enums
struct STemperament { Temperament curr; };
struct SSocial      { Social      curr; };
struct SDrive       { Drive       curr; };
struct SBearing     { Bearing     curr; };

//Struct for disposition enums
struct SHobby  { Hobby      curr; };
struct SFear   { Fear       curr; };
struct SDesire { Desire     curr; };

//Struct for status enum
struct SHealth   { Health     curr; };
struct SSickness { Sickness   curr; };
struct SWound    { Wound      curr; };
struct SMorale   { Morale     curr; };
struct SHunger   { Hunger     curr; int lastAte; };
struct SThirst   { Thirst     curr; int lastDrink; };
struct SFatigue  { Fatigue    curr; int lastSlept;
};