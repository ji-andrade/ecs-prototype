#include "ui/renderer.h"

int main()
{
    //temp
    int maxPerson{ 20 };
    //

    World world;
    makePerson(world, maxPerson);

    mainCurses(world);

    return 0;
}
