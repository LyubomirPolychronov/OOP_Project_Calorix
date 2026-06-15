#include "Food.h"

int Food::nextId = 1;

Food::Food(const std::string& name, double caloriesPer100g, double proteinPer100g, double carbsPer100g, double fatPer100g)
	: name(name), caloriesPer100g(caloriesPer100g), proteinPer100g(proteinPer100g), carbsPer100g(carbsPer100g), fatPer100g(fatPer100g), id(nextId++)
{
	if (name.empty())
	{
		throw std::invalid_argument("Invalid name");
	}
	if (caloriesPer100g < 0 || proteinPer100g < 0 || carbsPer100g < 0 || fatPer100g < 0)
	{
		throw std::invalid_argument("Nutritional values cannot be negative");
	}
}

int Food::getId() const 
{
	return this->id;
}

const std::string& Food::getName() const
{
	return this->name;
}

double Food::getProtein() const
{
	return this->proteinPer100g;
}

double Food::getCalories() const
{
	return this->caloriesPer100g;
}

double Food::getFats() const
{
	return this->fatPer100g;
}

double Food::getCarbs() const
{
	return this->carbsPer100g;
}

void Food::setCalories(double newCals)
{
	if (newCals < 0)
	{
		throw std::invalid_argument("Calories should be a positive number");
	}
	caloriesPer100g = newCals;
}

void Food::setNextId(int id)
{
	nextId = id;
}

