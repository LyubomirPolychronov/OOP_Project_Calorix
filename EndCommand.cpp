#include "EndCommand.h"
#include "DataManager.h"

void EndCommand::execute(const std::vector<std::string>& args)
{
	std::cout << "Saving data and exiting Calorix\n";
	try {
		DataManager::saveData();
		std::cout << "Data saved successfully\n";
	}
	catch (const std::exception& e) {
		std::cout << "Error during savind: " << e.what() << "\n";
	}

	std::cout << "Goodbye\n";
	exit(0);
}
