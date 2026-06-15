#include "Exercise.h"

int Exercise::nextId = 1;

Exercise::Exercise(const std::string& name, double burnedCalories, const MUSCLE_GROUP& muscleGroup) : 
	name(name), caloriesBurnedPerHour(burnedCalories), muscleGroup(muscleGroup), id(nextId++)
{
}

int Exercise::getId() const {
	return this->id;
}

const std::string& Exercise::getName() const {
	return this->name;
}

double Exercise::getCaloriesBurned() const
{
	return this->caloriesBurnedPerHour;
}

std::string Exercise::getMuscleGroup() const
{
	switch (this->muscleGroup) {
	case MUSCLE_GROUP::CHEST: return "Chest";
	case MUSCLE_GROUP::BACK: return "Back";
	case MUSCLE_GROUP::LEGS: return "Legs";
	case MUSCLE_GROUP::SHOULDERS: return "Shoulders";
	case MUSCLE_GROUP::ARMS: return "Arms";
	case MUSCLE_GROUP::CORE: return "Core";
	case MUSCLE_GROUP::CARDIO: return "Cardio";
	default: return "Unknown";
	}
}

void Exercise::printExercise() const
{
	std::cout << "Exercise: " << name << " | burned calories: " << (caloriesBurnedPerHour) << " | main muscle group: " << getMuscleGroup() << "\n";
}

MUSCLE_GROUP Exercise::stringToMuscleGroup(const std::string& str)
{
	if (str == "CHEST" || str == "chest") return MUSCLE_GROUP::CHEST;
	if (str == "BACK" || str == "back") return MUSCLE_GROUP::BACK;
	if (str == "LEGS" || str == "legs") return MUSCLE_GROUP::LEGS;
	if (str == "SHOULDERS" || str == "shoulders") return MUSCLE_GROUP::SHOULDERS;
	if (str == "ARMS" || str == "arms") return MUSCLE_GROUP::ARMS;
	if (str == "CORE" || str == "core") return MUSCLE_GROUP::CORE;
	if (str == "CARDIO" || str == "cardio") return MUSCLE_GROUP::CARDIO;
	throw std::invalid_argument("Muscle group is not found");
}

std::string Exercise::muscleGroupToString() const
{
	switch (muscleGroup) {
	case MUSCLE_GROUP::CHEST: return "CHEST";
	case MUSCLE_GROUP::BACK: return "BACK";
	case MUSCLE_GROUP::LEGS: return "LEGS";
	case MUSCLE_GROUP::SHOULDERS: return "SHOULDERS";
	case MUSCLE_GROUP::ARMS: return "ARMS";
	case MUSCLE_GROUP::CORE: return "CORE";
	case MUSCLE_GROUP::CARDIO: return "CARDIO";
	default: throw std::invalid_argument("Unknown muscle");
	}
}
