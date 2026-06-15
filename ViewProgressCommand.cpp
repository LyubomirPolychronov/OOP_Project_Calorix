#include "ViewProgressCommand.h"
#include "Trainee.h"
void ViewProgressCommand::execute(const std::vector<std::string>& args)
{
	User* user = Calorix::getInstance().getCurrentUser();
	if (!user)
	{
		throw InvalidCommand("You must be logged in to perform this action");
	}
	Trainee* trainee = dynamic_cast<Trainee*>(user);
	if (!trainee)
	{
		throw InvalidCommand("Only trainees can view-progress");
	}
	if (!args.empty())
	{
		throw InvalidCommand("Usage: view-progress. No arguments needed");
	}
	trainee->viewProgress();
}
