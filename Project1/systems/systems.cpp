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
    std::cout << "Type a number for the person you wish to see" << "\n";
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