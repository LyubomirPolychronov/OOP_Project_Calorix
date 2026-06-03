#pragma once
#include "Command.h"
class LogOutCommand : public Command
{
public:
	void execute(const std::vector<std::string>& args) override;
};

