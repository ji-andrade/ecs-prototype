#include <conio.h>
#include "systems/systems.h"

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
	}
}
