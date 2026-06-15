#include "AddExerciseCommand.h"
#include "Admin.h"
#include "Calorix.h"
void AddExerciseCommand::execute(const std::vector<std::string>& args)
{
	User* current = Calorix::getInstance().getCurrentUser();
	if (!current)
	{
		throw InvalidCommand("You must be logged in to perform this action");
	}
	Admin* admin = dynamic_cast<Admin*>(current);
	if (!admin)
	{
		throw InvalidCommand("Only admins can add exercises to the exercise database");
	}
	if (args.size() < 3)
	{
		throw InvalidCommand("Usage: add-exercise <name> <calories_burned_per_hour> <muscle-group>");
	}
	std::string name = args[0];
	double calBurned = std::stod(args[1]);
	MUSCLE_GROUP muscle = Exercise::stringToMuscleGroup(args[2]);
	Calorix::getInstance().getExerciseDB().push_back(Exercise(name, calBurned, muscle));
	std::cout << "You have successfully added " << name << " to the data base\n";
}
