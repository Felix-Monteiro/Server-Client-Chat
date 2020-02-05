#pragma once
#include <iostream>
#include <exception>
#include <cassert>

using namespace std;

class SocketException : public exception {
public:
	virtual const char* what() const throw()
	{
		return "Error at socket(): ";
	}
};