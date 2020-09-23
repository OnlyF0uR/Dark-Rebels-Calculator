#pragma once

#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>

#include "Profit.h"

void Profit::Run() {
	double totalAmount = GetAmount();
	std::string role = GetRole();

	std::cout << std::endl;

	double multiplier = 0.;

	if (role.compare("outsider") == 0) {
		multiplier = 0.5;
	}
	else if (role.compare("follower") == 0) {
		multiplier = 0.6;
	}
	else if (role.compare("rebel") == 0) {
		multiplier = 0.7;
	}

	std::cout << "--------------[Result]--------------" << std::endl;

	std::cout << "Total (100%): " << totalAmount << std::endl;

	double playerAmount = totalAmount * multiplier;
	std::cout << "What the player get (" << (multiplier * 100) << "%): " << playerAmount << std::endl;

	double crewAmount = totalAmount - playerAmount;
	std::cout << "What we get (" << ((1 - multiplier) * 100) << "%): " << crewAmount << std::endl;

	std::cout << "--------------[Result]--------------" << std::endl;

	system("pause");
}

double Profit::GetAmount() {
	int totalAmount;
	std::cout << "Fill in the amount of money: ";
	std::cin >> totalAmount;

	std::cin.ignore();
	return totalAmount;
}

std::string Profit::GetRole() {
	std::string role = "";
	std::cout << "Fill in the role of the player (Outsider/Follower/Rebel): ";
	std::getline(std::cin, role);
	boost::to_lower(role);

	return role;
}