#include <conio.h>
#include "systems/systems.h"
#include "systems/ui.h"

int main()
{
	World world;
	makePerson(world, 10);

	while (true)
	{
		system("cls");
		printGeneral(world);
		printPerson(world, playerInput());
		_getch();
		systemTime(world);
		systemNeeds(world);
		systemHealth(world);
		systemMorale(world);
		systemDisease(world);
	}
}
