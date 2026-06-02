#pragma once
#include "FitnessGoal.h"
class MaintenanceGoal: public FitnessGoal
{
public:
	MaintenanceGoal(const Date& start, const Date& end) : FitnessGoal(start,end){}
	
	bool isGoalAchieved(const UserProfile& profile) const override {
		return isAchieved;
	}
	std::unique_ptr<FitnessGoal> clone() const override {
		return std::make_unique<MaintenanceGoal>(*this);
	}
	std::string getProgress(const UserProfile& profile)const override {
		return "Your current goal is Maintenance. Aim to keep your net calorie balance close to 0 kcal.\n";
	}
	GoalType getType() const override {
		return GoalType::MAINTENANCE;
	}
};

