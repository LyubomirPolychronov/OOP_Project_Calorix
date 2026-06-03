#pragma once
#include "FitnessGoal.h"
static const double MIN_WEIGHT = 40;
class WeightLossGoal : public FitnessGoal
{
private:
	double goalWeight;
public:
	WeightLossGoal(const Date& start, const Date& end, double wantedWeight);
	void setGoalWeight(double weight);
	bool isGoalAchieved(const UserProfile& profile) const override;
	std::unique_ptr<FitnessGoal> clone() const override;
	std::string getProgress(const UserProfile& profile) const override;
	GoalType getType() const override;
};

