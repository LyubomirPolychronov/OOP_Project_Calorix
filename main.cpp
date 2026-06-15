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
#include "LogExerciseCommand.h"
#include "ViewProgressCommand.h"
#include "CalculateBMICommand.h"
#include "CalculateBMRCommand.h"
#include "GenerateWorkoutPlanCommand.h"
#include "AddToFavouritesCommand.h"
#include "ViewFavouritesCommand.h"
#include "InvalidCommand.h"
#include "SetGoalsCommand.h"
#include "NextDayCommand.h"
int main()
{
	DataManager::loadData();

	CommandFactory factory;
	factory.registerCommand("register", std::make_unique<RegisterCommand>());
	factory.registerCommand("login", std::make_unique<LoginCommand>());
	factory.registerCommand("logout", std::make_unique<LogOutCommand>());
	factory.registerCommand("help", std::make_unique<HelpCommand>());
	factory.registerCommand("end", std::make_unique<EndCommand>());
	factory.registerCommand("next-day", std::make_unique<NextDayCommand>());

	factory.registerCommand("set-goals", std::make_unique<SetGoalsCommand>());
	factory.registerCommand("log-food", std::make_unique<LogFoodCommand>());
	factory.registerCommand("log-exercise", std::make_unique<LogExerciseCommand>());
	factory.registerCommand("view-summary", std::make_unique<ViewDailySummaryCommand>());
	factory.registerCommand("view-progress", std::make_unique<ViewProgressCommand>());
	factory.registerCommand("calculate-bmi", std::make_unique<CalculateBMICommand>());
	factory.registerCommand("calculate-bmr", std::make_unique<CalculateBMRCommand>());
	factory.registerCommand("generate-workout-plan", std::make_unique<GenerateWorkoutPlanCommand>());
	factory.registerCommand("add-to-favorites", std::make_unique<AddToFavouritesCommand>());
	factory.registerCommand("view-favorites", std::make_unique<ViewFavouritesCommand>());

	factory.registerCommand("block-user", std::make_unique<BlockUserCommand>());
	factory.registerCommand("add-food", std::make_unique<AddFoodCommand>());
	factory.registerCommand("add-exercise", std::make_unique<AddExerciseCommand>());
	factory.registerCommand("update-food", std::make_unique<UpdateFoodCommand>());

	if (Calorix::getInstance().getUserDB().empty()) {
		UserProfile adminProfile(30, 80.0, 180.0, Gender::male, ActivityLevel::MODERATE);
		Calorix::getInstance().getUserDB().push_back(std::make_unique<Admin>("admin", "admin123", adminProfile));
	}
	std::cout << "--- Welcome to Calorix system (Logged in as admin) ---\n";
	std::cout << "--- Initial Date: ";
	Calorix::getInstance().getCurrentDate().printDate();
	std::cout << "\n";
	std::cout << "Enter command: \n";
	User* adminPtr = Calorix::getInstance().getUserDB().front().get();
	if (adminPtr)
	{
		Calorix::getInstance().setCurrentUser(adminPtr);
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
		catch (const InvalidCommand& e) {
			std::cout << "Command error: " << e.what() << "\n";
		}
		catch (const std::invalid_argument& e){
			std::cout << "Invalid argument error: " << e.what() << "\n";
		}
		catch (const std::exception& e) {
			std::cout << "Standard error: " << e.what() << "\n";
		}
		std::cout << "\nEnter command: \n";
	}

	return 0;
}
