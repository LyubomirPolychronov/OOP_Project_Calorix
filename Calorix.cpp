#include "Calorix.h"

Calorix& Calorix::getInstance()
{
	static Calorix calorix;
	return calorix;
}

User* Calorix::getCurrentUser() const
{
	return currentUser;
}

void Calorix::setCurrentUser(User* user)
{
	if (!user)
	{
		throw std::invalid_argument("Invalid User");
	}
	currentUser = user;
}

std::vector<std::unique_ptr<User>>& Calorix::getUserDB()
{
	return userDB;
}

std::vector<Food>& Calorix::getFoodDB()
{
	return foodDB;
}

std::vector<Exercise>& Calorix::getExerciseDB()
{
	return exerciseDB;
}
