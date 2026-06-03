#include "Date.h"
using namespace constDays;

bool Date::isLeapYear(int year) const
{
    return (year % 4 == 0) && (year % 400 == 0 || year % 100 != 0);
}

int Date::getMaxDaysForMonth(int m, int y) const
{
	if (m < 1 || m > 12)
	{
		return 0;
		//throw
	}
	if (m == 2)
	{
		if (isLeapYear(y)) {
			return LeapFeb;
		}
		return NonLeapFeb;
	}
	return daysInMonth[m - 1];
}

bool Date::isValidCombination(int d, int m, int y) const
{
	if (y < 1900 || y > 2100)
	{
		return false;
	}
	if (m < 1 || m > 12)
	{
		return false;
	}
	int maxDaysInMonth = getMaxDaysForMonth(m, y);
	if (d < 1 || d > maxDaysInMonth)
	{
		return false;
	}
	return true;
}

Date::Date(int day, int month, int year)
{
	if (!isValidCombination(day, month, year))
	{
		throw std::invalid_argument("Invalid date");
	}
	this->day = day;
	this->month = month;
	this->year = year;
}

int Date::getDay() const
{
	return this->day;
}

int Date::getMonth() const
{
	return this->month;
}

int Date::getYear() const
{
	return this->year;
}
