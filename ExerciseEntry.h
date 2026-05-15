#pragma once
#include "Exercise.h"
#include "Date.h"
class ExerciseEntry
{
private:
	int id;
	static int nextId;
	const Exercise& exercise;
	int durationInMinutes;
	Date date;

public:
	ExerciseEntry(const Exercise& e, int duration, const Date& date);
	const Exercise& getExercise() const;
	int getDuration() const;
	double calculateBurnedCalories() const;
};

