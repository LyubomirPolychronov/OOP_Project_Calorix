#include "NextDayCommand.h"
void NextDayCommand::execute(const std::vector<std::string>& args) {
	if (args.size() < 3)
	{
		throw InvalidCommand("Usage: next-day <day> <month> <year>");
	}
	try {
	Date newDate = Date::stringToDate(args);
	Calorix::getInstance().setCurrentDate(newDate);
	std::cout << "Date successfully advanced to: " << newDate.getDay() << "/" << newDate.getMonth() << "/" << newDate.getYear() << "\n";
	}
	catch (const std::invalid_argument& e) {
		throw InvalidCommand("Your new date is invalid, keeping old date");
	}
}