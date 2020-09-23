#include <iostream>

#include "MainMenu.h"

MainMenu mainMenu;

int main() {

	do {
		mainMenu.Run();
	} while (mainMenu.RunAgain());

	return 0;
}