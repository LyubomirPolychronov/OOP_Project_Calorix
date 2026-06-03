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
	mutable bool isAchieved;
public:
	FitnessGoal(const Date& start, const Date& end);
	virtual ~FitnessGoal() = default;
	virtual bool isGoalAchieved(const UserProfile& profile) const = 0;
	std::string typeToString(const GoalType& type) const;
	virtual GoalType getType() const = 0;
	virtual std::unique_ptr<FitnessGoal> clone() const = 0;
	virtual std::string getProgress(const UserProfile& profile) const = 0;
};

