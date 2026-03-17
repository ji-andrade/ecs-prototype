#pragma once
#include <cstdint>
#include <string>

using ID = uint32_t;

//Enum Physical
enum class Physic { Lean, Average, Stocky, Count };
enum class Eyes { Narrow, Wide, Piercing, Count };
enum class Nose { Flat, Hooked, Bulbous, Count };
enum class Hair { Bald, Short, Matted, Count };
enum class Jaw { Weak, Square, Heavy, Count };
enum class Skin { Pale, Tan, Weathered, Count };
enum class Brow { Thick, Furrowed, Arched, Count };
enum class Job { Doctor, Carpenter, Barber, Teacher, Count };
//Enum Personality
enum class Temperament { Calm, Irritable, Melancholic, Cheerful, Count };
enum class Social { Withdrawn, Reserved, Friendly, Domineering, Count };
enum class Drive { Greedy, Ambitious, Lazy, Dutiful, Count };
enum class Bearing { Nervous, Confident, Humble, Arrogant, Count };

//Basic stats
struct Name { std::string val{}; };
struct Age { int curr{}; };

//Structs for physical the enums
struct SPhysic { Physic build; };
struct SEyes   { Eyes   shape; };
struct SNose   { Nose   shape; };
struct SHair   { Hair   style; };
struct SJaw    { Jaw    shape; };
struct SSkin   { Skin   tone; };
struct SBrow   { Brow   shape; };
struct SJob    { Job    curr; };

//Structs for personality the enums
struct STemperament { Temperament curr; };
struct SSocial { Social      curr; };
struct SDrive { Drive       curr; };
struct SBearing { Bearing     curr; };