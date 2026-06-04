#pragma once
#include <stdexcept>
#include <memory>
#include <string>
#include <iostream>
enum class Gender {
	male,
	female,
};

enum class ActivityLevel {
	SEDENTARY,
	LIGHT,
	MODERATE,
	ACTIVE,
	VERY_ACTIVE,
};

class UserProfile
{
private:
	int age;
	double weight;
	double height;
	Gender gender;
	ActivityLevel al;
public:
	UserProfile(int age, double weight, double height,const Gender& gender, const ActivityLevel& al) : age(age), weight(weight), height(height), gender(gender), al(al) {}
	int getAge() const;
	double getHeight() const;
	double getWeight() const;
	const Gender& getGender() const;
	const ActivityLevel& getActivityLevel() const;
	std::string genderToString() const;
	std::string activityLevelToString() const;
	static Gender stringToGender(const std::string& g);
	static ActivityLevel stringToActivityLevel(const std::string& str);
};

