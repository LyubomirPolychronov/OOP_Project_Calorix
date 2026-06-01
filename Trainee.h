#pragma once
#include "User.h"
#include "FoodEntry.h"
#include "ExerciseEntry.h"
#include "GoalFactory.h"
class Trainee : public User
{
private:
	std::vector<FoodEntry> foodDiary;
	std::vector<ExerciseEntry> exerciseDiary;
	std::vector<ExerciseEntry> favoriteExercises;
	std::unique_ptr<FitnessGoal> currentGoal;
public:
	Trainee(const std::string& name, const std::string& pass, const UserProfile& profile):
		User(name,pass,profile), currentGoal(nullptr) { }

	void setGoal(const std::string& type, const Date& start, const Date& end, double targetValue) {
		currentGoal = GoalFactory::create(type, start, end, targetValue);
	}
};

