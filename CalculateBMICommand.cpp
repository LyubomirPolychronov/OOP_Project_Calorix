#include "CalculateBMICommand.h"
#include "Trainee.h"
void CalculateBMICommand::execute(const std::vector<std::string>& args)
{
	User* user = Calorix::getInstance().getCurrentUser();
	if (!user)
	{
		throw InvalidCommand("You must be logged in to perform this action");
	}
	Trainee* trainee = dynamic_cast<Trainee*>(user);
	if (!trainee)
	{
		throw InvalidCommand("Only trainees can calculate BMI");
	}
	if (!args.empty())
	{
		throw InvalidCommand("Usage: calculate-bmi. No arguments needed");
	}
	trainee->calculateBMI();
}
