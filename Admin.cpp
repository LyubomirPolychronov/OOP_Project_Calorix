#include "Admin.h"
#include "Calorix.h"
#include <algorithm>
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

void Admin::blockUser(const std::string& userName)
{
	auto& users = Calorix::getInstance().getUserDB();
	
	auto it = std::remove_if(users.begin(), users.end(), [&userName](const std::unique_ptr<User>& user) {return user->getUsername() == userName; });
	if (it != users.end())
	{
		users.erase(it, users.end()); 
		std::cout << "User " << userName << " has been successfully blocked and removed.\n";
		std::cout << "Changes will be permanently saved to the file upon typing 'end'.\n";
		return;
	}
	throw std::invalid_argument("User with username " + userName + " not found");
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
			return;
		}
	}
	throw std::invalid_argument("Food was not found in data base");
}
