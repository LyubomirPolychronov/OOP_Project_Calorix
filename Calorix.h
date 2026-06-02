#pragma once
#include "User.h"
#include "Food.h"
#include "Exercise.h"
class Calorix
{
private:
	std::vector<std::unique_ptr<User>> userDB;
	std::vector<Food> foodDB;
	std::vector<Exercise> exerciseDB;
	User* currentUser = nullptr;

	Calorix() = default;
	~Calorix() = default;

public:
	static Calorix& getInstance() {
		static Calorix calorix;
		return calorix;
	}
	Calorix(const Calorix& other) = delete;
	Calorix& operator=(const Calorix& other) = delete;
	
	User* getCurrentUser() const { return currentUser; }
	void setCurrentUser(User* user) { currentUser = user; }

	std::vector<std::unique_ptr<User>>& getUserDB() { return userDB; }
	std::vector<Food>& getFoodDB() { return foodDB; }
	std::vector<Exercise>& getExerciseDB() { return exerciseDB; }
};

