#include "toString.h"

//Physical enum to string
std::string toString(Physic v)
{
    switch (v)
    {
    case Physic::Lean: return    "Lean and sinewy, with little to spare on the bone";
    case Physic::Average: return "Average build, neither remarkable nor wanting";
    case Physic::Stocky: return  "Stocky and broad, carrying his weight close to the ground";
    default:             return "unknown";
    }
}
//he has
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
    case Hair::Bald:   return "a bare scalp, shaved or long since surrendered";
    case Hair::Short:  return "short cropped hair, practical and unadorned";
    case Hair::Matted: return "matted hair, knotted and unwashed";
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
//Job enum to string
std::string toString(Job v)
{
    switch (v)
    {
    case Job::Barber:    return "Barber";
    case Job::Doctor:    return "Doctor";
    case Job::Carpenter: return "Carpenter";
    case Job::Teacher:   return "Teacher";
    default:             return "unknown";
    }
}
//Personality enums to string
std::string toString(Temperament v)
{
    switch (v)
    {
    case Temperament::Calm:       return "calm, rarely rattled by what life throws at him";
    case Temperament::Irritable:  return "quick to irritation, with a short fuse and a long memory";
    case Temperament::Melancholic: return "melancholic, given to long silences and dark moods";
    case Temperament::Cheerful:   return "cheerful without obvious cause, as if privy to some private joke";
    default:                      return "unknown";
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
//Dispoition enums to string
std::string toString(Hobby v)
{
    switch (v)
    {
    case Hobby::Fishing:   return "finds peace at the water's edge, rod in hand and mind elsewhere";
    case Hobby::Gambling:  return "is drawn to the table, chasing the feeling more than the money";
    case Hobby::Reading:   return "is rarely without a book, even if the light is poor";
    case Hobby::Drinking:  return "drinks with purpose, like a man settling an old debt";
    case Hobby::Fighting:  return "seeks out trouble the way other men seek out comfort";
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