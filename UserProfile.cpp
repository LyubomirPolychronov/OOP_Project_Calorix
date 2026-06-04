#include "UserProfile.h"

int UserProfile::getAge() const
{
    return age;
}

double UserProfile::getHeight() const
{
    return height;
}

double UserProfile::getWeight() const
{
    return weight;
}

const Gender& UserProfile::getGender() const
{
    return gender;
}

std::string UserProfile::genderToString() const
{
    switch (gender) {
    case Gender::male: return "male";
    case Gender::female: return "female";
    default: throw std::invalid_argument("Invalid gender! Choose 'male' or 'female'");
    }
}

std::string UserProfile::activityLevelToString() const
{
    switch (al) {
    case ActivityLevel::SEDENTARY: return "SEDENTARY";
    case ActivityLevel::LIGHT: return "LIGHT";
    case ActivityLevel::MODERATE: return "MODERATE";
    case ActivityLevel::ACTIVE: return "ACTIVE";
    case ActivityLevel::VERY_ACTIVE: return "VERY_ACTIVE";
    default: throw std::invalid_argument("Unknown activity level");
    }
}

Gender UserProfile::stringToGender(const std::string& g)
{
    return g == "male" ? Gender::male : Gender::female;
}

ActivityLevel UserProfile::stringToActivityLevel(const std::string& str)
{
    if (str == "SEDENTARY" || str == "sedentary") return ActivityLevel::SEDENTARY;
    if (str == "LIGHT" || str == "light") return ActivityLevel::LIGHT;
    if (str == "MODERATE" || str == "moderate") return ActivityLevel::MODERATE;
    if (str == "ACTIVE" || str == "active") return ActivityLevel::ACTIVE;
    if (str == "VERY_ACTIVE" || str == "very_active") return ActivityLevel::VERY_ACTIVE;
    throw std::invalid_argument("Invalid activity level! Choose: sedentary, light, moderate, active, very_active.");
}

const ActivityLevel& UserProfile::getActivityLevel() const
{
    return al;
}
