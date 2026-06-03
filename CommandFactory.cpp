#include "CommandFactory.h"

void CommandFactory::registerCommand(const std::string& name, std::unique_ptr<Command> command)
{
	commands[name] = std::move(command);
}

void CommandFactory::executeCommand(const std::string& name, const std::vector<std::string>& args)
{
	auto it = commands.find(name);
	if (it != commands.end())
	{
		it->second->execute(args);
	}
	else
	{
		throw std::invalid_argument("Unknown command " + name);
	}
}
