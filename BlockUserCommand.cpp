#include "BlockUserCommand.h"
#include "Calorix.h"
#include "Admin.h"
void BlockUserCommand::execute(const std::vector<std::string>& args)
{
	User* user = Calorix::getInstance().getCurrentUser();
	if (!user)
	{
		throw InvalidCommand("You must be logged in to perform this action");
	}
	Admin* admin = dynamic_cast<Admin*>(user);
	if (!admin)
	{
		throw InvalidCommand("Only admins can block users");
	}
	if (args.size() < 1)
	{
		throw InvalidCommand("Usage: block-user <username>");
	}
	std::string name = args[0];
	admin->blockUser(name);
}
