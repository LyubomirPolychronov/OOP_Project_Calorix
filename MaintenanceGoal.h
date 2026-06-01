#pragma once
#include "FitnessGoal.h"
class MaintenanceGoal: public FitnessGoal
{
public:
	MaintenanceGoal(const Date& start, const Date& end) : FitnessGoal(start,end){}
	
	bool isGoalAchieved(const UserProfile& profile) override {
		return isAchieved;
	}

	std::unique_ptr<FitnessGoal> clone() const override {
		return std::make_unique<MaintenanceGoal>(*this);
	}

	GoalType getType() const override {
		return GoalType::MAINTENANCE;
	}
};

