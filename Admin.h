#pragma once
#include "User.h"
#include "Food.h"
#include "Exercise.h"
class Admin : public User
{

public:
	Admin(const std::string& name, const std::string& pass, const UserProfile& profile);

	void login(const std::string& username, const std::string& password) override;
	void logout() override;
	void help() const override;
	void blockUser(const std::string& userName);
	Food addFood(const std::string& name, double caloriesPer100, double protein, double carbs, double fat);
	Exercise addExercise(const std::string& name, double caloriesBurned, const MUSCLE_GROUP& muscle);
	void updateFood(const std::string& name, double newCalories, std::vector<Food>& foodDB);

};

