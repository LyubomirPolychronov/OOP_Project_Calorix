#pragma once
#include "FitnessGoal.h"
#include "WeightLossGoal.h"
#include "BulkingGoal.h"
#include "MaintenanceGoal.h"
#include <memory>
class GoalFactory
{
public:
	static std::unique_ptr<FitnessGoal> create(const std::string& type, const Date& start, const Date& end, double targetValue = 0.0); 
};

