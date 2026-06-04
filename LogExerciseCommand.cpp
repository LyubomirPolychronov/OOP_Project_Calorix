#include "LogExerciseCommand.h"
#include "Trainee.h"
void LogExerciseCommand::execute(const std::vector<std::string>& args)
{
	User* user = Calorix::getInstance().getCurrentUser();
	if (!user)
	{
		throw std::invalid_argument("You must be logged in to perform this action");
	}
	Trainee* trainee = dynamic_cast<Trainee*>(user);
	if (!trainee)
	{
		throw std::invalid_argument("Only trainees can log-exercises");
	}
	if (args.size() < 5)
	{
		throw std::invalid_argument("Usage: log-exercise <exercise-name> <duration_minutes> <day> <month> <year>");
	}
	std::string exerciseName = args[0];
	int minutes = std::stoi(args[1]);
	int day = std::stoi(args[2]);
	int month = std::stoi(args[3]);
	int year = std::stoi(args[4]);
	Date date(day, month, year);
	for (const auto& exercise : Calorix::getInstance().getExerciseDB()) {
		if (exercise.getName() == exerciseName)
		{
			trainee->logExercise(exercise, minutes, date);
			std::cout << "You have successfully logged the exercise " << exercise.getName() << "\n";
			return;
		}
	}
	throw std::invalid_argument("Exercise not found in data base");
}
