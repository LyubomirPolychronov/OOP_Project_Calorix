#pragma once
#include "Command.h"
#include "Trainee.h"
class ViewDailySummaryCommand : public Command
{
public:
	void execute(const std::vector<std::string>& args) override;
};

