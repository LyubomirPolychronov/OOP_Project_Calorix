#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>

#include "Calorix.h"
#include "Admin.h"
#include "CommandFactory.h"
#include "EndCommand.h"
#include "AddFoodCommand.h"
#include "LoginCommand.h"
#include "LogOutCommand.h"
#include "HelpCommand.h"
#include "RegisterCommand.h"
#include "LogFoodCommand.h"
#include "ViewDailySummaryCommand.h"
#include "DataManager.h"
#include "BlockUserCommand.h"
#include "AddExerciseCommand.h"
#include "UpdateFoodCommand.h"
#include <iostream>

int main()
{
	DataManager::loadData();

	CommandFactory factory;
	factory.registerCommand("end", std::make_unique<EndCommand>());
	factory.registerCommand("add-food", std::make_unique<AddFoodCommand>());
	factory.registerCommand("login", std::make_unique<LoginCommand>());
	factory.registerCommand("logout", std::make_unique<LogOutCommand>());
	factory.registerCommand("register", std::make_unique<RegisterCommand>());
	factory.registerCommand("help", std::make_unique<HelpCommand>());
	factory.registerCommand("log-food", std::make_unique<LogFoodCommand>());
	factory.registerCommand("view-summary", std::make_unique<ViewDailySummaryCommand>());
	factory.registerCommand("block-user", std::make_unique<BlockUserCommand>());
	factory.registerCommand("add-exercise", std::make_unique<AddExerciseCommand>());
	factory.registerCommand("update-food", std::make_unique<UpdateFoodCommand>());
	if (Calorix::getInstance().getUserDB().empty()) {
		UserProfile adminProfile(30, 80.0, 180.0, Gender::male, ActivityLevel::MODERATE);
		Calorix::getInstance().getUserDB().push_back(std::make_unique<Admin>("admin", "admin123", adminProfile));
	}
	std::cout << "--- Welcome to Calorix system (Logged in as admin) ---\n";
	std::cout << "Enter command: \n";
	if (!Calorix::getInstance().getUserDB().empty()) {
		Calorix::getInstance().setCurrentUser(Calorix::getInstance().getUserDB().front().get());
	}
	
	std::string line;
	while (std::getline(std::cin, line)) {
		if (line.empty()) continue;

		std::stringstream ss(line);
		std::string commandName;
		ss >> commandName; 

		std::vector<std::string> args;
		std::string arg;
		while (ss >> arg) {
			args.push_back(arg); 
		}

		try {
			factory.executeCommand(commandName, args);
		}
		catch (const std::invalid_argument& e){
			std::cout << "Error: " << e.what() << "\n";
		}
		catch (const std::exception& e) {
			std::cout << "Error: " << e.what() << "\n";
		}

		std::cout << "\nEnter command: \n";
	}

	return 0;
}
