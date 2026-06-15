#include "CalculateBMRCommand.h"
#include "Trainee.h"
void CalculateBMRCommand::execute(const std::vector<std::string>& args)
{
	User* user = Calorix::getInstance().getCurrentUser();
	if (!user)
	{
		throw InvalidCommand("You must be logged in to perform this action");
	}
	Trainee* trainee = dynamic_cast<Trainee*>(user);
	if (!trainee)
	{
		throw InvalidCommand("Only trainees can calculate BMR");
	}
	if (!args.empty())
	{
		throw InvalidCommand("Usage: calculate-bmr. No arguments needed");
	}
	trainee->calculateBMR();
}
