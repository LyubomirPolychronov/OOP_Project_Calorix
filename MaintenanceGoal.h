#pragma once
#include "FitnessGoal.h"
class MaintenanceGoal: public FitnessGoal
{
public:
	MaintenanceGoal(const Date& start, const Date& end);
	
	bool isGoalAchieved(const UserProfile& profile) const override;
	std::unique_ptr<FitnessGoal> clone() const override;
	std::string getProgress(const UserProfile& profile)const override;
	GoalType getType() const override;
};

