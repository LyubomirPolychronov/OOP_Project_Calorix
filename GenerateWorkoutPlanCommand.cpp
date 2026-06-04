#include "GenerateWorkoutPlanCommand.h"
#include "Trainee.h"
void GenerateWorkoutPlanCommand::execute(const std::vector<std::string>& args)
{
	User* user = Calorix::getInstance().getCurrentUser();
	if (!user)
	{
		throw std::invalid_argument("You must be logged in to perform this action");
	}
	Trainee* trainee = dynamic_cast<Trainee*>(user);
	if (!trainee)
	{
		throw std::invalid_argument("Only trainees can generate workout plan");
	}
	if (args.size() < 1)
	{
		throw std::invalid_argument("Usage: generate-workout-plan <duration_minutes>");
	}
	int minutes = std::stoi(args[0]);
	trainee->generateWorkoutPlan(minutes, Calorix::getInstance().getExerciseDB());
}
