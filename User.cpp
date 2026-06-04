#include "User.h"

int User::nextId = 1;

User::User(const std::string& username, const std::string& password, const UserProfile& prof) : username(username), password(password), profile(prof)
{
	this->id = nextId++;
}

bool User::checkLogin(const std::string& username, const std::string& password) const
{
	return (this->username == username && this->password == password);
}

const std::string& User::getUsername() const
{
	return this->username;
}

int User::getId() const
{
	return this->id;
}

const UserProfile& User::getProfile() const
{
	return profile;
}

