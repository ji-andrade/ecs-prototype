#include "ui/renderer.h"

int main()
{
    //temp
    int maxPerson{ 20 };
    //

    World world;
    makePerson(world, maxPerson);

    while (true)
    {
        mainCurses(world);
        

    }


    return 0;
}
