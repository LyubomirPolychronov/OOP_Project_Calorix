#include "MaintenanceGoal.h"
MaintenanceGoal::MaintenanceGoal(const Date& start, const Date& end) : FitnessGoal(start, end) {}

bool MaintenanceGoal::isGoalAchieved(const UserProfile& profile) const {
	return true;
}
std::unique_ptr<FitnessGoal> MaintenanceGoal::clone() const {
	return std::make_unique<MaintenanceGoal>(*this);
}
std::string MaintenanceGoal::getProgress(const UserProfile& profile)const {
	return "Your current goal is Maintenance. Aim to keep your net calorie balance close to 0 kcal.\n";
}
GoalType MaintenanceGoal::getType() const {
	return GoalType::MAINTENANCE;
}