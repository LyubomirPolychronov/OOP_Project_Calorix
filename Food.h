#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
class Food
{
private:
	int id;
	static int nextId;
	std::string name;
	double caloriesPer100g, proteinPer100g, carbsPer100g, fatPer100g;
public: 
	Food(const std::string& name, double caloriesPer100g, double proteinPer100g, double carbsPer100g, double fatPer100g);
	
	int getId() const;
	const std::string& getName() const;
	double getProtein() const;
	double getCalories() const;
	double getFats() const;
	double getCarbs() const;
	void setCalories(double newCals);
};

   