#pragma once
#include "FitnessGoal.h"

static const double BASE_SURPLUS = 300;

class BulkingGoal : public FitnessGoal
{
private:
	double calorieSurplus;
public:
	BulkingGoal(const Date& start, const Date& end, double calories) : FitnessGoal(start, end) {
		calorieSurplus = (calories < BASE_SURPLUS) ? (BASE_SURPLUS) : (calories);
	}
	
	bool isGoalAchieved(const UserProfile& profile) const override {
		return isAchieved;
	}
	GoalType getType() const override {
		return GoalType::BULKING;
	}

	std::unique_ptr<FitnessGoal> clone() const override {
		return std::make_unique<BulkingGoal>(*this);
	}
	std::string getProgress(const UserProfile& profile) const override {
		return "Your current goal is Bulking. You need to maintain a daily calorie surplus of +" + std::to_string(calorieSurplus) + " kcal.\n";
	}
	double getCalorieSurplus() const {
		return calorieSurplus;
	}
};

