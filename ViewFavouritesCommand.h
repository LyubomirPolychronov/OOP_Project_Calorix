#pragma once
#include "Command.h"
class ViewFavouritesCommand : public Command
{
public:
	void execute(const std::vector<std::string>& args) override;
};

