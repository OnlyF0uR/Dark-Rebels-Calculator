#pragma once

#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>

#include "Laundering.h"

void Laundering::Run() {
	double totalAmount = GetAmount();
	bool isMember = IsMember();

	std::cout << std::endl;

	double multiplier = isMember ? 0.8 : 0.7;

	std::cout << "--------------[Result]--------------" << std::endl;

	std::cout << "Total (100%): " << totalAmount << std::endl;

	double playerAmount = totalAmount * multiplier;
	std::cout << "What the player get (" << (multiplier * 100) << "%): " << playerAmount << std::endl;

	double laundererAmount = totalAmount * 0.2;
	std::cout << "What the launderer gets (20%): " << laundererAmount << std::endl;

	double crewAmount = totalAmount - (playerAmount + laundererAmount);
	std::cout << "What we get (" << ((1 - (multiplier + 0.2)) * 100) << "%): " << crewAmount << std::endl;

	std::cout << "--------------[Result]--------------" << std::endl;

	system("pause");
}

double Laundering::GetAmount() {
	int totalAmount;
	std::cout << "Fill in the amount of money: ";
	std::cin >> totalAmount;

	std::cin.ignore();
	return totalAmount;
}

bool Laundering::IsMember() {
	std::string isMember = "";
	std::cout << "Fill in whether the player is a crewmember or not (Yes/No): ";
	std::getline(std::cin, isMember);
	boost::to_lower(isMember);

	if (isMember.compare("yes") == 0) {
		return true;
	}

	return false;
}