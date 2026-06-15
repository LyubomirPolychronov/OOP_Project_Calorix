#include "WeightLossGoal.h"

WeightLossGoal::WeightLossGoal(const Date& start, const Date& end, double wantedWeight) : FitnessGoal(start, end) 
{
	setGoalWeight(wantedWeight);
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
	else
	{
		isAchieved = false;
	}
	return isAchieved;
}
std::unique_ptr<FitnessGoal> WeightLossGoal::clone() const {
	return std::make_unique<WeightLossGoal>(*this);
}
std::string WeightLossGoal::getProgress(const UserProfile& profile) const {
	double kgDiff = abs(profile.getWeight() - goalWeight);
	std::ostringstream ss;
	ss << std::fixed << std::setprecision(1) << kgDiff;
	std::string str = ss.str();
	return (!isGoalAchieved(profile)) ? ("You have " + str + " to goal weight\n") : ((kgDiff < 0.1 ? ("You have reached your goal\n") : (" You are even " + str + "under your goal weight\n")));
}
GoalType WeightLossGoal::getType() const {
	return GoalType::WEIGHT_LOSS;
}