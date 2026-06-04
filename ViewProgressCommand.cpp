#include "ViewProgressCommand.h"
#include "Trainee.h"
void ViewProgressCommand::execute(const std::vector<std::string>& args)
{
	User* user = Calorix::getInstance().getCurrentUser();
	if (!user)
	{
		throw std::invalid_argument("You must be logged in to perform this action");
	}
	Trainee* trainee = dynamic_cast<Trainee*>(user);
	if (!trainee)
	{
		throw std::invalid_argument("Only trainees can view-progress");
	}
	if (!args.empty())
	{
		throw std::invalid_argument("Usage: view-progress. No arguments needed");
	}
	trainee->viewProgress();
}
