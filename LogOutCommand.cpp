#include "LogOutCommand.h"

void LogOutCommand::execute(const std::vector<std::string>& args)
{
	if (!args.empty())
	{
		throw std::invalid_argument("Usage logout. No arguments needed");
	}
	User* user = Calorix::getInstance().getCurrentUser();
	if (!user)
	{
		throw std::invalid_argument("Error: no user is currently logged in");
	}
	user->logout();
	Calorix::getInstance().setCurrentUser(nullptr);
	
}
