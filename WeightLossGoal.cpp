#include "WeightLossGoal.h"

WeightLossGoal::WeightLossGoal(const Date& start, const Date& end, double wantedWeight) : FitnessGoal(start, end), goalWeight(wantedWeight) 
{
}
void WeightLossGoal::setGoalWeight(double weight) {
	if (weight <= MIN_WEIGHT)
	{
		throw std::invalid_argument("Your goal weight should be no less than" + std::to_string(MIN_WEIGHT));
	}
	goalWeight = weight;
}
bool WeightLossGoal::isGoalAchieved(const UserProfile& profile) const {
	if (profile.getWeight() <= goalWeight)
	{
		isAchieved = true;
	}
	return isAchieved;
}
std::unique_ptr<FitnessGoal> WeightLossGoal::clone() const {
	return std::make_unique<WeightLossGoal>(*this);
}
std::string WeightLossGoal::getProgress(const UserProfile& profile) const {
	double kgDiff = abs(profile.getWeight() - goalWeight);
	return (!isGoalAchieved(profile)) ? ("You have " + std::to_string(kgDiff) + " to goal weight\n") : ("You have reached your goal and you are even " + std::to_string(kgDiff) + "under your goal weight\n");
}
GoalType WeightLossGoal::getType() const {
	return GoalType::WEIGHT_LOSS;
}