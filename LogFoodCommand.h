#pragma once
#include "Command.h"
#include "Trainee.h"
class LogFoodCommand : public Command
{
public:
	void execute(const std::vector<std::string>& args) override;
};

