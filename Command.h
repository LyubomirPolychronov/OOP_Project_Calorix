#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Calorix.h"

class Command
{
public:
	virtual void execute(const std::vector<std::string>& args) = 0;
	virtual ~Command() = default;
};

