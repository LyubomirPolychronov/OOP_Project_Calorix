#include "ViewDailySummaryCommand.h"

void ViewDailySummaryCommand::execute(const std::vector<std::string>& args)
{
	User* current = Calorix::getInstance().getCurrentUser();
	if (!current)
	{
		throw std::invalid_argument("You must be logged in to perform this action");
	}
	Trainee* trainee = dynamic_cast<Trainee*>(current);
	if (!trainee)
	{
		throw std::invalid_argument("Only trainees can view daily summary");
	}
	if (!args.empty())
	{
		throw std::invalid_argument("Usage: view-summary - no arguments needed");
	}
	trainee->viewDailySummary();
}
