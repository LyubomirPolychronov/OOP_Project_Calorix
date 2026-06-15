#include "GenerateWorkoutPlanCommand.h"
#include "Trainee.h"
void GenerateWorkoutPlanCommand::execute(const std::vector<std::string>& args)
{
	User* user = Calorix::getInstance().getCurrentUser();
	if (!user)
	{
		throw InvalidCommand("You must be logged in to perform this action");
	}
	Trainee* trainee = dynamic_cast<Trainee*>(user);
	if (!trainee)
	{
		throw InvalidCommand("Only trainees can generate workout plan");
	}
	if (args.size() < 1)
	{
		throw InvalidCommand("Usage: generate-workout-plan <duration_minutes>");
	}
	int minutes = std::stoi(args[0]);
	trainee->generateWorkoutPlan(minutes, Calorix::getInstance().getExerciseDB());
}
