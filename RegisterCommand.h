#pragma once
#include "Command.h"
#include "Trainee.h"
class RegisterCommand : public Command
{
public:
	void execute(const std::vector<std::string>& args) override;
};

