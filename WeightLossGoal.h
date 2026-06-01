#pragma once
#include "FitnessGoal.h"
static const double MIN_WEIGHT = 40;
class WeightLossGoal : public FitnessGoal
{
private:
	double goalWeight;
public:
	WeightLossGoal(const Date& start, const Date& end, double wantedWeight): FitnessGoal(start, end), goalWeight(wantedWeight){}
	void setGoalWeight(double weight) {
		if (weight <= MIN_WEIGHT)
		{
			throw std::invalid_argument("Your goal weight should be no less than" + std::to_string(MIN_WEIGHT));
		}
		goalWeight = weight;
	}
	bool isGoalAchieved(const UserProfile& profile) override {
		if (profile.getWeight() <= goalWeight)
		{
			 isAchieved = true;
		}
		return isAchieved;
	}

	std::unique_ptr<FitnessGoal> clone() const override{
		return std::make_unique<WeightLossGoal>(*this);
	}

	GoalType getType() const override {
		return GoalType::WEIGHT_LOSS;
	}
};

