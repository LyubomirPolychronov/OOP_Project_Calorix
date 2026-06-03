#include "LoginCommand.h"

void LoginCommand::execute(const std::vector<std::string>& args)
{
	if (args.size() < 2)
	{
		throw std::invalid_argument("Usage: login <username> <password>");
	}
	if (Calorix::getInstance().getCurrentUser() != nullptr)
	{
		throw std::invalid_argument("User already logged in");
	}
	std::string username = args[0];
	std::string password = args[1];
	for (const auto& user : Calorix::getInstance().getUserDB()) {
		if (user->checkLogin(username,password))
		{
			user->login(username, password);
			Calorix::getInstance().setCurrentUser(user.get());
			return;
		}
	}
	throw std::invalid_argument("Username or password is incorrect");
}
