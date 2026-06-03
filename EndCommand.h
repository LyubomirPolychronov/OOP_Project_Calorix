#pragma once
#include "Command.h"
class EndCommand : public Command
{
public:
	void execute(const std::vector<std::string>& args) override;
};

