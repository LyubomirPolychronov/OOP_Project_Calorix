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
	static Calorix& getInstance();
	Calorix(const Calorix& other) = delete;
	Calorix& operator=(const Calorix& other) = delete;
	
	User* getCurrentUser() const;
	void setCurrentUser(User* user);

	std::vector<std::unique_ptr<User>>& getUserDB();
	std::vector<Food>& getFoodDB();
	std::vector<Exercise>& getExerciseDB();
};

