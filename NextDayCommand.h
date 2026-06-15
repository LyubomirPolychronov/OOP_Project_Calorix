#pragma once
#include "Command.h"
class NextDayCommand : public Command
{
public:
	void execute(const std::vector<std::string>& args) override;
};

