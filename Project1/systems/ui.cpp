#include "ui.h"


void printPerson(const World& world, int input)
{
    if (!world.nameMap.count(input))
    {
        std::cout << "No person with that ID.\n";
        return;
    }
    std::cout << describePerson(world, input) << "\n";
}

//temporary \/
void printGeneral(const World& world)
{
    system("cls");
    std::cout << "Day " << world.currDay << "\n\n";
    for (auto& [id, name] : world.nameMap)
        std::cout <<"ID " << id << " " << world.nameMap.at(id).val << " \n";
}

int playerInput()
{
    std::cout << "\n";
    int input{};
    std::cin >> input;
    system("cls");
    return input;
}
//temporary /\