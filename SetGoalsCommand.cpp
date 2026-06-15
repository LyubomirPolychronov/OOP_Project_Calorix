#include "SetGoalsCommand.h"
#include "Trainee.h"
void SetGoalsCommand::execute(const std::vector<std::string>& args)
{
	User* user = Calorix::getInstance().getCurrentUser();
	if (!user)
	{
		throw InvalidCommand("You must be logged in to perform this action");
	}
	Trainee* trainee = dynamic_cast<Trainee*>(user);
	if (!trainee)
	{
		throw InvalidCommand("Only trainees can set goals");
	}
	if (args.size() < 8)
	{
		throw InvalidCommand("Usage: set-goals <goal-type> <target-value> <start-date> <end-date>");
	}
	std::string type = args[0];
	double target = std::stod(args[1]);
	std::vector<std::string> start = { args[2], args[3], args[4] };
	Date startDate = Date::stringToDate(start);
	std::vector<std::string> end = { args[5], args[6], args[7] };
	Date endDate = Date::stringToDate(end);
	trainee->setGoal(type, target, startDate, endDate);
	std::cout << "Fitness goal " << type << " has been set successfully\n";
}
