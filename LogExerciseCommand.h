#pragma once
#include "Command.h"
class LogExerciseCommand : public Command
{
public:
	void execute(const std::vector<std::string>& args) override;
};

