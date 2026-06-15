#pragma once
#include "User.h"
#include "FoodEntry.h"
#include "ExerciseEntry.h"
#include "GoalFactory.h"
#include <functional>
#include <algorithm>
#include "Calorix.h"
class Trainee : public User
{
private:
	std::vector<FoodEntry> foodDiary;
	std::vector<ExerciseEntry> exerciseDiary;
	std::vector<const Exercise*> favoriteExercises;
	std::unique_ptr<FitnessGoal> currentGoal;

public:
	Trainee(const std::string& name, const std::string& pass, const UserProfile& profile); 
	
	void login(const std::string& username, const std::string& password) override;
	void logout() override;
	void help() const override;
	void setGoal(const std::string& type, double targetValue, const Date& start, const Date& end);
	void logFood(const Food& food, double quantityGrams, const Date& date);
	void logExercise(const Exercise& e, int duration,const Date& date);
	void viewDailySummary() const;
	void viewProgress() const;
	void calculateBMI() const; 
	double calculateBMR() const;
	std::vector<const Exercise*> generateWorkoutPlan(int duration, const std::vector<Exercise>& allExercises) const;
	void addToFavourites(const std::string& exerciseName);
	void viewFavourites() const;
};

