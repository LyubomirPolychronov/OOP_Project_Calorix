#pragma once
#include <iostream>
#include "Admin.h"
#include "Trainee.h"
#include <fstream>
#include "Calorix.h"
class DataManager
{
public:
	static void saveData();
	static void loadData();
};

