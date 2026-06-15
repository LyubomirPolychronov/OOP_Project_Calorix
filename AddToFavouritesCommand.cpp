#include "AddToFavouritesCommand.h"
#include "Trainee.h"
void AddToFavouritesCommand::execute(const std::vector<std::string>& args)
{
	User* user = Calorix::getInstance().getCurrentUser();
	if (!user)
	{
		throw InvalidCommand("You must be logged in to perform this action");
	}
	Trainee* trainee = dynamic_cast<Trainee*>(user);
	if (!trainee)
	{
		throw InvalidCommand("Only trainees can add to favourites");
	}
	if (args.size() < 1)
	{
		throw InvalidCommand("Usage: add-to-favorites <exercise_name>");
	}
	std::string name = args[0];
	trainee->addToFavourites(name);
}
