#pragma once
#include <iostream>
#include <exception>
#include <cassert>

using namespace std;

class AcceptSocketException : public exception {
public:
	virtual const char* what() const throw()
	{
		return " accept failed: ";
	}
};
