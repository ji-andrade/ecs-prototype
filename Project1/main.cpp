#include "ui/renderer.h"
#include <windows.h>


int main()
{
    World world;
    makePerson(world, 20);

    mainCurses(world);

    return 0;
}
