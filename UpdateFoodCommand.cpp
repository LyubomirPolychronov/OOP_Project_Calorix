#include "UpdateFoodCommand.h"
#include "Admin.h"
#include "Calorix.h"
void UpdateFoodCommand::execute(const std::vector<std::string>& args)
{
	User* current = Calorix::getInstance().getCurrentUser();
	if (!current)
	{
		throw InvalidCommand("You must be logged in to perform this action");
	}
	Admin* admin = dynamic_cast<Admin*>(current);
	if (!admin)
	{
		throw InvalidCommand("Only admins can update the calories from the food Data Base");
	}
	if (args.size() < 2)
	{
		throw InvalidCommand("Usage: update-food <food_name> <new_calories>");
	}
	std::string foodName = args[0];
	double newCals = std::stod(args[1]);
	admin->updateFood(foodName, newCals, Calorix::getInstance().getFoodDB());
	std::cout << "Food " << foodName << " updated successfully. New value will be active after you enter 'end'\n";
}
