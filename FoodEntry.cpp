#include "FoodEntry.h"

int FoodEntry::nextId = 1;

FoodEntry::FoodEntry(const Food& food, double quantityInGrams, const Date& date) : food(food), date(date),quantityGrams(quantityInGrams), id(nextId++)
{
	if (this->quantityGrams < 0)
	{
		throw std::invalid_argument("Quantity cannot be negative");
	}
}

const Food& FoodEntry::getFood() const
{
	return this->food;
}

double FoodEntry::getQuantity() const
{
	return this->quantityGrams;
}

const std::string FoodEntry::getDate() const
{
	
	return std::to_string(this->date.getDay()) + "." +
		   std::to_string(this->date.getMonth()) + "." +
		   std::to_string(this->date.getYear());
}
