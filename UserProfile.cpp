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

const ActivityLevel& UserProfile::getActivityLevel() const
{
    return al;
}
