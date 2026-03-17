#include <conio.h>
#include "systems.h"

int main()
{
	World world;

	makePerson(world);
	while (true)
	{
		system("cls");
		printGeneral(world);
		printPerson(world, playerInput());
		_getch();
	}

	

}
