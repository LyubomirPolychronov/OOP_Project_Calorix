#include "HelpCommand.h"

void HelpCommand::execute(const std::vector<std::string>& args)
{
	if (!args.empty())
	{
		throw InvalidCommand("Usage help. No arguments needed");
	}
	User* user = Calorix::getInstance().getCurrentUser();
	if (!user)
	{
		std::cout << "--- Calorix Available Commands ---\n"
			<< "1. login <username> <password>\n"
			<< "2. register <username> <password> <age> <weight> <height> <gender> <activity_level>\n"
			<< "3. end\n"
			<< "----------------------------------\n";
		return;
	}
	user->help();
}
