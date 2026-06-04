#include "CalculateBMRCommand.h"
#include "Trainee.h"
void CalculateBMRCommand::execute(const std::vector<std::string>& args)
{
	User* user = Calorix::getInstance().getCurrentUser();
	if (!user)
	{
		throw std::invalid_argument("You must be logged in to perform this action");
	}
	Trainee* trainee = dynamic_cast<Trainee*>(user);
	if (!trainee)
	{
		throw std::invalid_argument("Only trainees can calculate BMR");
	}
	if (!args.empty())
	{
		throw std::invalid_argument("Usage: calculate-bmr. No arguments needed");
	}
	trainee->calculateBMR();
}
