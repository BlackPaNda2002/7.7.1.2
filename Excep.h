#pragma once
#include <iostream>
#include <exception>

using namespace std;




class bad_range:public exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "ERROR: Out of range!";
	}
};

class  bad_length :public exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "ERROR: Invalid length!";
	}
};

