#include "ExerciseEntry.h"

int ExerciseEntry::nextId = 1;

ExerciseEntry::ExerciseEntry(const Exercise& e, int duration, const Date& date) : exercise(e), durationInMinutes(duration), date(date), id(nextId++)
{
}

const Exercise& ExerciseEntry::getExercise() const
{
	return exercise;
}

int ExerciseEntry::getDuration() const
{
	return durationInMinutes;
}

double ExerciseEntry::calculateBurnedCalories() const
{
	return (durationInMinutes / 60.0) * (exercise.getCaloriesBurned());
}
