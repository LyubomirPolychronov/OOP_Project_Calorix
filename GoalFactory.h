#pragma once
#include "FitnessGoal.h"
#include "WeightLossGoal.h"
#include "BulkingGoal.h"
#include "MaintenanceGoal.h"
#include <memory>
class GoalFactory
{
public:
	static std::unique_ptr<FitnessGoal> create(const std::string& type, const Date& start, const Date& end, double targetValue = 0.0) {
		if (type == "WEIGHT_LOSS" || type == "weight_loss")
		{
			return std::make_unique<WeightLossGoal>(start,end,targetValue);
		}
		else if(type == "BULKING" || type == "bulking")
		{
			return std::make_unique<BulkingGoal>(start, end, targetValue);
		}
		else if (type == "MAINTENANCE" || type == "maintenance")
		{
			return std::make_unique<MaintenanceGoal>(start, end);
		}
		throw std::invalid_argument("Unknown type: " + type);
	}
};

