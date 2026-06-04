#pragma once
#include <iostream>
#include <string>

enum class MUSCLE_GROUP {
	CHEST,
	BACK,
	LEGS,
	SHOULDERS,
	ARMS,
	CORE,
	CARDIO,
};

class Exercise
{
private:
	int id;
	static int nextId;
	std::string name;
	double caloriesBurnedPerHour;
	MUSCLE_GROUP muscleGroup;

public:
	Exercise(const std::string& name, double burnedCalories, const MUSCLE_GROUP& muscleGroup);
	int getId() const;
	const std::string& getName() const;
	double getCaloriesBurned() const;
	const std::string& getMuscleGroup() const;
	void printExercise() const;
	static MUSCLE_GROUP stringToMuscleGroup(const std::string& str);
	std::string muscleGroupToString() const;
};

