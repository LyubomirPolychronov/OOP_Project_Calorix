#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Calorix.h"
#include "InvalidCommand.h"
#include "Date.h"
class Command
{
public:
	virtual void execute(const std::vector<std::string>& args) = 0;
	virtual ~Command() = default;
};

