#pragma once
#include "Command.h"
class BlockUserCommand : public Command
{
public:
	void execute(const std::vector<std::string>& args) override;
};

