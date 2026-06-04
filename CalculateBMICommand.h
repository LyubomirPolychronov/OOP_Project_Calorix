#pragma once
#include "Command.h"
class CalculateBMICommand : public Command
{
public:
	void execute(const std::vector<std::string>& args) override;
};

