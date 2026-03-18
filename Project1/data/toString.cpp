#include "toString.h"

//Physical enum to string
std::string toString(Physic v)
{
    switch (v)
    {
    case Physic::Lean:    return "Lean and sinewy, with little to spare on the bone";
    case Physic::Average: return "Average build, neither remarkable nor wanting";
    case Physic::Stocky:  return "Stocky and broad, carrying his weight close to the ground";
    default:              return "unknown";
    }
}

std::string toString(Eyes v)
{
    switch (v)
    {
    case Eyes::Narrow:   return "narrow, watchful eyes that miss little";
    case Eyes::Wide:     return "wide open eyes, taking in everything at once";
    case Eyes::Piercing: return "piercing eyes that linger a moment too long";
    default:             return "unknown";
    }
}

std::string toString(Nose v)
{
    switch (v)
    {
    case Nose::Flat:    return "a flat, broad nose";
    case Nose::Hooked:  return "a hooked nose, sharp as a crow's beak";
    case Nose::Bulbous: return "a bulbous nose, red at the tip";
    default:            return "unknown";
    }
}

std::string toString(Hair v)
{
    switch (v)
    {
    case Hair::Bald:   return "A bare scalp, shaved or long since surrendered";
    case Hair::Short:  return "Short cropped hair, practical and unadorned";
    case Hair::Matted: return "Matted hair, knotted and unwashed";
    default:           return "unknown";
    }
}

std::string toString(Jaw v)
{
    switch (v)
    {
    case Jaw::Weak:   return "a weak jaw, soft beneath the chin";
    case Jaw::Square: return "a square jaw, set and deliberate";
    case Jaw::Heavy:  return "a heavy jaw, giving his face a brutish cast";
    default:          return "unknown";
    }
}

std::string toString(Skin v)
{
    switch (v)
    {
    case Skin::Pale:      return "pale skin, as though rarely touched by sun";
    case Skin::Tan:       return "tan and weathered from long days outdoors";
    case Skin::Weathered: return "deeply weathered skin, creased and hardened";
    default:              return "unknown";
    }
}

std::string toString(Brow v)
{
    switch (v)
    {
    case Brow::Thick:    return "thick brows that hang heavy over his eyes";
    case Brow::Furrowed: return "a perpetually furrowed brow, as if troubled by some private thought";
    case Brow::Arched:   return "arched brows that lend him an air of quiet skepticism";
    default:             return "unknown";
    }
}
std::string toString(Teeth v)
{
    switch (v)
    {
    case Teeth::Good:    return "teeth that are straight and mostly sound";
    case Teeth::Worn:    return "teeth worn and yellowed, the mouth of a man who has lived roughly";
    case Teeth::Rotting: return "teeth black at the root, the breath foul and the gums receding";
    default:             return "unknown";
    }
}

//Job enum to string
std::string toString(Job v)
{
    switch (v)
    {
    case Job::Doctor:    return "Doctor";
    case Job::Carpenter: return "Carpenter";
    case Job::Barber:    return "Barber";
    case Job::Cook:      return "Cook";
    case Job::Sailor:    return "Sailor";
    case Job::Navigator: return "Navigator";
    case Job::Gunner:    return "Gunner";
    case Job::Priest:    return "Priest";
    case Job::Merchant:  return "Merchant";
    case Job::Soldier:   return "Soldier";
    default:             return "unknown";
    }
}

//Personality enums to string
std::string toString(Temperament v)
{
    switch (v)
    {
    case Temperament::Calm:        return "calm, rarely rattled by what life throws at him";
    case Temperament::Irritable:   return "quick to irritation, with a short fuse and a long memory";
    case Temperament::Melancholic: return "melancholic, given to long silences and dark moods";
    case Temperament::Cheerful:    return "cheerful without obvious cause, as if privy to some private joke";
    default:                       return "unknown";
    }
}

std::string toString(Social v)
{
    switch (v)
    {
    case Social::Withdrawn:    return "withdrawn, keeping his own counsel and little else";
    case Social::Reserved:     return "reserved, polite enough but never quite present";
    case Social::Friendly:     return "friendly in the easy way of men who have nothing to hide";
    case Social::Domineering:  return "domineering, with a habit of filling whatever room he enters";
    default:                   return "unknown";
    }
}

std::string toString(Drive v)
{
    switch (v)
    {
    case Drive::Greedy:    return "Greedy at heart, with an eye always on what others are holding";
    case Drive::Ambitious: return "Ambitious, the kind of man who counts his steps toward something";
    case Drive::Lazy:      return "Lazy in the bone-deep way, doing just enough and no more";
    case Drive::Dutiful:   return "Dutiful, carrying his obligations like a man who knows no other way";
    default:               return "unknown";
    }
}

std::string toString(Bearing v)
{
    switch (v)
    {
    case Bearing::Nervous:    return "nervous in his movements, always half-expecting something to go wrong";
    case Bearing::Confident:  return "confident without arrogance, moving like a man at ease in his own skin";
    case Bearing::Humble:     return "humble to the point of self-effacement, quick to step aside";
    case Bearing::Arrogant:   return "arrogant in the quiet way, as if the world owes him something it has forgotten to pay";
    default:                  return "unknown";
    }
}

//Disposition enums to string

std::string toString(Hobby v)
{
    switch (v)
    {
    case Hobby::Fishing:   return "finds peace at the water's edge, rod in hand and mind elsewhere";
    case Hobby::Gambling:  return "is drawn to the table, chasing the feeling more than the money";
    case Hobby::Reading:   return "is rarely without a book, even if the light is poor";
    case Hobby::Drinking:  return "drinks with purpose, like a man settling an old debt";
    case Hobby::Fighting:  return "seeks out trouble the way other men seek out comfort";
    case Hobby::Opium:     return "is given to opium, seeking the fog it brings when the world presses too close";
    case Hobby::Whoring:   return "spends his coin on women, finding in their company what he cannot find elsewhere";
    default:               return "unknown";
    }
}

std::string toString(Fear v)
{
    switch (v)
    {
    case Fear::Sea:      return "carries a quiet dread of the sea, though he rarely speaks of it";
    case Fear::Heights:  return "keeps his eyes low and his feet flat, never trusting a high place";
    case Fear::Death:    return "thinks of death more than most, and likes it less";
    case Fear::Poverty:  return "has known want before and will do much to avoid knowing it again";
    case Fear::Solitude: return "does not bear being alone well, filling silence however he can";
    default:             return "unknown";
    }
}

std::string toString(Desire v)
{
    switch (v)
    {
    case Desire::Wealth:    return "wants money the way some men want air";
    case Desire::Fame:      return "hungers to be known, to have his name mean something";
    case Desire::Family:    return "wants a home and people in it, simple as that";
    case Desire::Freedom:   return "wants no master, no schedule, no walls he did not choose";
    case Desire::Survival:  return "asks only to live to see the next day, and the one after";
    default:                return "unknown";
    }
}

//Status enum to string
std::string toString(Health v)
{
    switch (v)
    {
    case Health::Healthy:  return "in good health, nothing to complain about";
    case Health::Ailing:  return "weakened, his body struggling to keep pace";
    case Health::Dying:    return "fading, the life going out of him slowly";
    default:               return "unknown";
    }
}

//temporary removal
/*
std::string toString(Sickness v)
{
    switch (v)
    {
    case Sickness::None:          return "Free of sickness";
    case Sickness::Feverish:      return "Burning with fever, his eyes glassy and distant";
    case Sickness::Scurvy:        return "Riddled with scurvy, his gums black and his joints screaming";
    case Sickness::Dysentery:     return "Hollowed out by dysentery, too weak to stand for long";
    case Sickness::Malnourished:  return "Malnourished, his body beginning to turn on itself";
    case Sickness::Dehydrated:    return "Dehydrated, his skin tight and his mind starting to slip";
    case Sickness::Wasting:       return "Wasting away, starved of both food and water, not long for this world";
    case Sickness::Delirious:     return "Delirious from exhaustion, seeing things that are not there";
    default:                      return "unknown";
    }
}
*/

std::string toString(Wound v)
{
    switch (v)
    {
    case Wound::None:    return "Unwounded";
    case Wound::Light:   return "Nursing a light wound, more inconvenience than danger";
    case Wound::Severe:  return "Badly wounded, every movement a reminder of it";
    default:             return "unknown";
    }
}

std::string toString(Morale v)
{
    switch (v)
    {
    case Morale::Steady:    return "steady in his bearing, neither hopeful nor desperate";
    case Morale::Anxious:   return "anxious, scanning the horizon for something he cannot name";
    case Morale::Broken:    return "broken in spirit, going through the motions without belief";
    case Morale::Inspired:  return "lifted by something, moving with purpose and rare conviction";
    default:                return "unknown";
    }
}

std::string toString(Hunger v)
{
    switch (v)
    {
    case Hunger::Fed:      return "well fed, no complaint on that count";
    case Hunger::Hungry:   return "hungry, his stomach making its feelings known";
    case Hunger::Starving: return "starving, the hunger past pain and into something quieter";
    default:               return "unknown";
    }
}

std::string toString(Thirst v)
{
    switch (v)
    {
    case Thirst::Quenched: return "his thirst satisfied for now";
    case Thirst::Thirsty:  return "thirsty, his mouth dry and his temper shorter for it";
    case Thirst::Parched:  return "parched, his lips cracked and his thoughts narrowing to water";
    default:               return "unknown";
    }
}

std::string toString(Fatigue v)
{
    switch (v)
    {
    case Fatigue::Rested:    return "rested, with something left in reserve";
    case Fatigue::Tired:     return "tired, the kind that sits behind the eyes";
    case Fatigue::Exhausted: return "exhausted, running on will alone";
    default:                 return "unknown";
    }
}