#include "RegisterCommand.h"

void RegisterCommand::execute(const std::vector<std::string>& args)
{
	if (args.size() < 7)
	{
		throw std::invalid_argument("Usage: register <username> <password> <age> <weight> <height> <gender> <acticity_level>");
	}
	std::string name = args[0];
	std::string password = args[1];
	int age = std::stoi(args[2]);
	double weight = std::stod(args[3]);
	double height = std::stod(args[4]);
	Gender gender = UserProfile::stringToGender(args[5]);
	ActivityLevel al = UserProfile::stringToActivityLevel(args[6]);
	
	for (const auto& user : Calorix::getInstance().getUserDB()) {
		if (user->getUsername() == name)
		{
			throw std::invalid_argument("Username already exists. Please choose another one");
		}
	}
	UserProfile up(age, weight, height, gender, al);
	Calorix::getInstance().getUserDB().push_back(std::make_unique<Trainee>(name, password, up));
	std::cout << "Registration successful\n";
}
