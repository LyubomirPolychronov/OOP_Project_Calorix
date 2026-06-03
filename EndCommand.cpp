#include "EndCommand.h"

void EndCommand::execute(const std::vector<std::string>& args)
{
	std::cout << "Saving data and exiting Calorix\n";


	std::cout << "Goodbye\n";
	exit(0);
}
