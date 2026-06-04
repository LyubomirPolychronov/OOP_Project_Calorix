#pragma once
#include "Command.h"
class UpdateFoodCommand : public Command
{
public:
	void execute(const std::vector<std::string>& args) override;
};

