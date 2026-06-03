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

const std::string& Exercise::getMuscleGroup() const
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
	std::cout << "Exercise: " << name << " | burned calories: " << std::to_string(caloriesBurnedPerHour) << " | main muscle group: " << getMuscleGroup() << "\n";
}
