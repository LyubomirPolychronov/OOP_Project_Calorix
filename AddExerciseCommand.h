#pragma once
#include "Command.h"
class AddExerciseCommand : public Command
{
public:
	void execute(const std::vector<std::string>& args) override;
};

