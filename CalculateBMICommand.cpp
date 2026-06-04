#include "CalculateBMICommand.h"
#include "Trainee.h"
void CalculateBMICommand::execute(const std::vector<std::string>& args)
{
	User* user = Calorix::getInstance().getCurrentUser();
	if (!user)
	{
		throw std::invalid_argument("You must be logged in to perform this action");
	}
	Trainee* trainee = dynamic_cast<Trainee*>(user);
	if (!trainee)
	{
		throw std::invalid_argument("Only trainees can calculate BMI");
	}
	if (!args.empty())
	{
		throw std::invalid_argument("Usage: calculate-bmi. No arguments needed");
	}
	trainee->calculateBMI();
}
