#include "ViewFavouritesCommand.h"
#include "Trainee.h"
void ViewFavouritesCommand::execute(const std::vector<std::string>& args)
{
	User* user = Calorix::getInstance().getCurrentUser();
	if (!user)
	{
		throw InvalidCommand("You must be logged in to perform this action");
	}
	Trainee* trainee = dynamic_cast<Trainee*>(user);
	if (!trainee)
	{
		throw InvalidCommand("Only trainees can view favourites");
	}
	if (!args.empty())
	{
		throw InvalidCommand("Usage: view-favorites. No arguments needed");
	}
	trainee->viewFavourites();
}
