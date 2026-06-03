#include "FitnessGoal.h"

FitnessGoal::FitnessGoal(const Date& start, const Date& end) : startDate(start), deadline(end), isAchieved(false)
{
}

std::string FitnessGoal::typeToString(const GoalType& type) const
{
	switch (type) {
	case GoalType::WEIGHT_LOSS: return "weight_loss";
	case GoalType::BULKING: return "bulking";
	case GoalType::MAINTENANCE: return "maintenance";
	default: throw std::invalid_argument("Unknown type");
	}
}
