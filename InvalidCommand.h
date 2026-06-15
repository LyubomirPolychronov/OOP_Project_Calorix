#pragma once
#include <exception>
#include <string>
class InvalidCommand : public std::exception
{
	std::string message;

public:
	InvalidCommand(const std::string& msg);
	InvalidCommand();
	const char* what() const noexcept override;
};

