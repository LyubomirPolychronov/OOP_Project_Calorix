#include "BulkingGoal.h"
BulkingGoal::BulkingGoal(const Date& start, const Date& end, double calories) : FitnessGoal(start, end) {
	calorieSurplus = (calories < BASE_SURPLUS) ? (BASE_SURPLUS) : (calories);
}

bool BulkingGoal::isGoalAchieved(const UserProfile& profile) const {
	return isAchieved;
}
GoalType BulkingGoal::getType() const {
	return GoalType::BULKING;
}

std::unique_ptr<FitnessGoal> BulkingGoal::clone() const {
	return std::make_unique<BulkingGoal>(*this);
}
std::string BulkingGoal::getProgress(const UserProfile& profile) const {
	return "Your current goal is Bulking. You need to maintain a daily calorie surplus of +" + std::to_string(calorieSurplus) + " kcal.\n";
}
double BulkingGoal::getCalorieSurplus() const {
	return calorieSurplus;
}