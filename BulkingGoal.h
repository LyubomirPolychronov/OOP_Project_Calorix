#pragma once
#include "FitnessGoal.h"

static const double BASE_SURPLUS = 300;

class BulkingGoal : public FitnessGoal
{
private:
	double calorieSurplus;
public:
	BulkingGoal(const Date& start, const Date& end, double calories);
	bool isGoalAchieved(const UserProfile& profile) const override;
	GoalType getType() const override;

	std::unique_ptr<FitnessGoal> clone() const override;
	std::string getProgress(const UserProfile& profile) const override;
	double getCalorieSurplus() const;
};

