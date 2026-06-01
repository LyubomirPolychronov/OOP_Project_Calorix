#pragma once
#include "Date.h"
#include "UserProfile.h"

enum class GoalType {
	WEIGHT_LOSS,
	BULKING,
	MAINTENANCE,
};

class FitnessGoal
{
protected:
	Date startDate;
	Date deadline;
	bool isAchieved;
public:
	FitnessGoal(const Date& start, const Date& end):startDate(start), deadline(end), isAchieved(false){}
	virtual ~FitnessGoal() = default;
	virtual bool isGoalAchieved(const UserProfile& profile) = 0;
	const std::string& typeToString(const GoalType& type) {
		switch (type) {
		case GoalType::WEIGHT_LOSS: return "weight_loss";
		case GoalType::BULKING: return "bulking";
		case GoalType::MAINTENANCE: return "maintenance";
		default: throw std::invalid_argument("Unknown type");
		}
	}
	virtual GoalType getType() const = 0;
	virtual std::unique_ptr<FitnessGoal> clone() const = 0;
};

