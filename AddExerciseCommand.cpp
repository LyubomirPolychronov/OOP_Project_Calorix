#include "AddExerciseCommand.h"
#include "Admin.h"
#include "Calorix.h"
void AddExerciseCommand::execute(const std::vector<std::string>& args)
{
	User* current = Calorix::getInstance().getCurrentUser();
	if (!current)
	{
		throw std::invalid_argument("You must be logged in to perform this action");
	}
	Admin* admin = dynamic_cast<Admin*>(current);
	if (!admin)
	{
		throw std::invalid_argument("Only admins can add exercises to the exercise database");
	}
	if (args.size() < 3)
	{
		throw std::invalid_argument("Usage: add-exercise <name> <calories_burned_per_hour> <muscle-group>");
	}
	std::string name = args[0];
	double calBurned = std::stod(args[1]);
	MUSCLE_GROUP muscle = Exercise::stringToMuscleGroup(args[2]);
	Calorix::getInstance().getExerciseDB().push_back(Exercise(name, calBurned, muscle));
}
