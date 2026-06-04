#include "DataManager.h"

void DataManager::saveData()
{
	std::ofstream outFoods("foods.txt");
	std::ofstream outUsers("users.txt");
	std::ofstream outExercises("exercises.txt");
	if (!outFoods || !outUsers || !outExercises)
	{
		throw std::runtime_error("Failed to save game");
	}
	for (const auto& food : Calorix::getInstance().getFoodDB()) {
		outFoods << food.getName() << " " << food.getCalories() << " " << food.getProtein() << " "
			<< food.getCarbs() << " " << food.getFats() << "\n";
	}
	for (const auto& user : Calorix::getInstance().getUserDB()) {
		if (dynamic_cast<Admin*>(user.get()))
		{
			outUsers << "Admin" << " ";
		}
		else {
			outUsers << "Trainee" << " ";
		}

		outUsers << user->getUsername() << " password_mask " << user->getProfile().getAge() << " "
			     << user->getProfile().getWeight() << " " << user->getProfile().getHeight() << " " << user->getProfile().genderToString() << " " 
			     << user->getProfile().activityLevelToString() << "\n";
	}
	for (const auto& exercise : Calorix::getInstance().getExerciseDB()) {
		outExercises << exercise.getName() << " " << exercise.getCaloriesBurned() << " " << exercise.muscleGroupToString() << "\n";
	}
}

void DataManager::loadData()
{
	std::ifstream inFoods("foods.txt");
	std::ifstream inUsers("users.txt");
	std::ifstream inExercises("exercises.txt");
	if (inFoods) {
		std::string fName;
		double cals, prot, carbs, fats;
		while (inFoods >> fName >> cals >> prot >> carbs >> fats)
		{
			Food loadedFood(fName, cals, prot, carbs, fats);
			Calorix::getInstance().getFoodDB().push_back(loadedFood);
		}
	}
	if (inUsers) {
		std::string type, uName, uPass, genderStr, activityStr;
		int age;
		double weight, height;
		while (inUsers >> type >> uName >> uPass >> age >> weight >> height >> genderStr >> activityStr)
		{
			Gender g = UserProfile::stringToGender(genderStr);
			ActivityLevel al = UserProfile::stringToActivityLevel(activityStr);
			UserProfile up(age, weight, height, g, al);
			if (type == "Admin")
			{
				Calorix::getInstance().getUserDB().push_back(std::make_unique<Admin>(uName, uPass, up));
			}
			else if (type == "Trainee")
			{
				Calorix::getInstance().getUserDB().push_back(std::make_unique<Trainee>(uName, uPass, up));
			}
		}
	}
	if (inExercises) {
		std::string eName, muscleStr;
		double caloriesBurned;
		while (inExercises >> eName >> caloriesBurned >> muscleStr) {
			MUSCLE_GROUP muscle = Exercise::stringToMuscleGroup(muscleStr);
			Calorix::getInstance().getExerciseDB().push_back(Exercise(eName, caloriesBurned, muscle));
		}
	}
}


