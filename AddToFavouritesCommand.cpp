#include "AddToFavouritesCommand.h"
#include "Trainee.h"
void AddToFavouritesCommand::execute(const std::vector<std::string>& args)
{
	User* user = Calorix::getInstance().getCurrentUser();
	if (!user)
	{
		throw std::invalid_argument("You must be logged in to perform this action");
	}
	Trainee* trainee = dynamic_cast<Trainee*>(user);
	if (!trainee)
	{
		throw std::invalid_argument("Only trainees can add to favourites");
	}
	if (args.size() < 3)
	{
		throw std::invalid_argument("Usage: add-to-favorites <exercise_name> <burned_calories> <muscle_group>");
	}
	std::string exerciseName = args[0];
	double cals = std::stod(args[1]);
	MUSCLE_GROUP muscle = Exercise::stringToMuscleGroup(args[2]);
	Exercise e(exerciseName, cals, muscle);
	trainee->addToFavourites(&e); // dangling pointer
}
