#pragma once
#include "Command.h"
class GenerateWorkoutPlanCommand : public Command
{
public:
	void execute(const std::vector<std::string>& args) override;
};

