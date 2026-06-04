#pragma once
#include "Command.h"
class ViewProgressCommand : public Command
{
public:
	void execute(const std::vector<std::string>& args) override;
};

