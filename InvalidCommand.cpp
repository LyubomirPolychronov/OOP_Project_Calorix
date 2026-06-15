#include "InvalidCommand.h"

InvalidCommand::InvalidCommand(const std::string& msg) : message(msg)
{
}

InvalidCommand::InvalidCommand() : message("Invalid command")
{
}

const char* InvalidCommand::what() const noexcept
{
	return message.c_str();
}
