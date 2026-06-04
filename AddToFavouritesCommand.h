#pragma once
#include "Command.h"
class AddToFavouritesCommand : public Command
{
public:
	void execute(const std::vector<std::string>& args) override;
};

