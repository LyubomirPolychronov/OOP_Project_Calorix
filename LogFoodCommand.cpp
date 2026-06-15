#include "LogFoodCommand.h"

void LogFoodCommand::execute(const std::vector<std::string>& args)
{
	User* current = Calorix::getInstance().getCurrentUser();
	if (!current)
	{
		throw InvalidCommand("You must be logged in to perform this action");
	}
	Trainee* trainee = dynamic_cast<Trainee*>(current);
	if (!trainee)
	{
		throw InvalidCommand("Only trainees can log-food");
	}
	if (args.size() < 5)
	{
		throw InvalidCommand("Usage: log-food <Food> <quantity> <Date(day,month,year)> ");
	}
	std::string foodName = args[0];
	double quantity = stod(args[1]);
	int day = stoi(args[2]);
	int month = stoi(args[3]);
	int year = stoi(args[4]);
	Date date(day, month, year);
	for (const auto& food : Calorix::getInstance().getFoodDB()) {
		if (food.getName() == foodName)
		{
			trainee->logFood(food, quantity, date);
			//std::cout << "Food " + foodName + " has succussfully been logged\n";
			return;
		}
	}
	throw InvalidCommand("Food not found in DataBase");
}
