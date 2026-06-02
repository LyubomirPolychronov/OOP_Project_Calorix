#pragma once
#include "Command.h"
class EndCommand : public Command
{
public:
	void execute(const std::vector<std::string>& args) override {
		std::cout << "Saving data and exiting Calorix\n";


		std::cout << "Goodbye\n";
		exit(0);
	}
};

