#pragma once

namespace constDays {
	const int LeapFeb = 29;
	const int NonLeapFeb = 28;
}

class Date
{
private:
	int day, month, year;
	
	const int daysInMonth[12]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	bool isLeapYear(int year) const;
	int getMaxDaysForMonth(int m, int y) const;
	bool isValidCombination(int d, int m, int y) const;

public:
	 Date(int day, int month, int year);
	 int getDay() const;
	 int getMonth() const;
	 int getYear() const;
};

