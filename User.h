#pragma once
#include <string>
#include <vector>
#include <memory>
#include "UserProfile.h"
class User
{
protected:
	int id;
	static int nextId;
	std::string username;
	std::string password;
	UserProfile profile;

public:
	 User(const std::string& username, const std::string& password, const UserProfile& prof);
	 virtual ~User(){}
	 virtual void registerUser(const std::string& username, const std::string& pass,int age, double weight, double height, const Gender& gender) = 0;
	 virtual void login(const std::string& username, const std::string& password) = 0;
	 virtual void logout() = 0;
	 virtual void help() = 0;

	 bool checkLogin(const std::string& username, const std::string& password) const;
	 const std::string& getUsername() const;
	 int getId() const;

};

