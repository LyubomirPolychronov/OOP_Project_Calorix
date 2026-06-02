#pragma once
#include "Command.h"
#include "Admin.h"
#include "Calorix.h"

class AddFoodCommand : public Command
{
public:

	void execute(const std::vector<std::string>& args) override {
		if (args.size() < 5)
		{
			throw std::invalid_argument("Usage: add-food <name> <cals> <prot> <carbs> <fats>");
		}
		User* current = Calorix::getInstance().getCurrentUser();
		if (!current)
		{
			throw std::invalid_argument("You must be logged in to perform this action");
		}
		Admin* admin = dynamic_cast<Admin*>(current);
		if (!admin)
		{
			throw std::invalid_argument("Only admins can add food to the food database");
		}

		std::string name = args[0];
		double cals = std::stod(args[1]);
		double prot = std::stod(args[2]);
		double carbs = std::stod(args[3]);
		double fats = std::stod(args[4]);

		Food newFood = admin->addFood(name, cals, prot, carbs, fats);
		Calorix::getInstance().getFoodDB().push_back(newFood);
	}

};

