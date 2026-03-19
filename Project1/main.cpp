#include "ui/renderer.h"

int main()
{
    World world;
    makePerson(world, 20);

    mainCurses(world);

    return 0;
}
