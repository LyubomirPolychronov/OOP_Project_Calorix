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
	currentUser = user;
}

Date Calorix::getCurrentDate() const
{
	return currentDate;
}

void Calorix::setCurrentDate(const Date& d)
{
	currentDate = d;
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
