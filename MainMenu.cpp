#pragma once
#include "MainMenu.h"

#include <iostream>

#include "Profit.h"
#include "Laundering.h"

Profit profit;
Laundering laundering;

MainMenu::MainMenu() {
	runAgain = false;
}

void MainMenu::Run() {
	int i;

	std::cout << "--------------[MainMenu]--------------" << std::endl;
	std::cout << "1. Profit" << std::endl;
	std::cout << "2. Laundering" << std::endl;
	std::cout << "--------------[MainMenu]--------------" << std::endl;
	std::cout << std::endl;
	std::cout << "Pick one of numbers above to proceed: ";

	std::cin >> i;

	std::cout << std::endl << "--------------------------------------" << std::endl << std::endl;

	switch (i) {
	case 1:
		profit.Run();
		break;
	case 2:
		laundering.Run();
		break;
	default:
		std::cout << "Invalid, Please try again." << std::endl;
		runAgain = true;
		break;
	}
}

bool MainMenu::RunAgain() {
	return runAgain;
}