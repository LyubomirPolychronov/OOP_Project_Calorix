#include "Admin.h"

Admin::Admin(const std::string& name, const std::string& pass, const UserProfile& profile) : User(name,pass,profile)
{
}

void Admin::login(const std::string& username, const std::string& password) {
	std::cout << "You have successfully logged in as an admin\n";
}

void Admin::logout()
{
	std::cout << "User " << this->getUsername() << " has successfully logged out.\n";
}

void Admin::help() const
{
	std::cout << "--- Admin Available Commands ---\n"
		<< "1. block-user <username>\n"
		<< "2. add-food <name> <calories_per_100g> <protein_per_100g> <carbs_per_100g> <fat_per_100g>\n"
		<< "3. add-exercise <name> <calories_burned_per_hour> <muscle-group>\n"
		<< "4. update-food <food-name> <new-calories>\n"
		<< "----------------------------------\n";
}

Food Admin::addFood(const std::string& name, double caloriesPer100, double protein, double carbs, double fat)
{
	Food item(name, caloriesPer100, protein, carbs, fat);
	return item;
}

Exercise Admin::addExercise(const std::string& name, double caloriesBurned, const MUSCLE_GROUP& muscle)
{
	Exercise exercise(name, caloriesBurned, muscle);
	return exercise;
}

void Admin::updateFood(const std::string& name, double newCalories, std::vector<Food>& foodDB)
{
	for (auto& food : foodDB) {
		if (name == food.getName())
		{
			food.setCalories(newCalories);
			std::cout << "Food updated successfully\n";
			return;
		}
	}
	std::cout << "Food was not found. Do you want to add new food.\n";

}
