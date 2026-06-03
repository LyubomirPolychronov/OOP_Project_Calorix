#pragma once
#include <map>
#include <memory>
#include "Command.h"
class CommandFactory
{
private:
	std::map<std::string, std::unique_ptr<Command>> commands;
public:
	CommandFactory() = default;

	void registerCommand(const std::string& name, std::unique_ptr<Command> command);
	void executeCommand(const std::string& name, const std::vector<std::string>& args);
};

