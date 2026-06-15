#pragma once
#include "Food.h"
#include "Date.h"
#include <stdexcept>
class FoodEntry
{
private:
	int id;
	static int nextId;
	const Food& food;
	double quantityGrams;
	Date date;
public:
	FoodEntry(const Food& food, double quantityInGrams, const Date& date);
	const Food& getFood() const;
	double getQuantity() const;
	const std::string getDate() const;
	Date getDateD() const;
};

