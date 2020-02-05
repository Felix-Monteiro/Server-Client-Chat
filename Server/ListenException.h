#pragma once
#include <iostream>
#include <exception>
#include <cassert>

using namespace std;

class ListenException : public exception {
public:
	virtual const char* what() const throw()
	{
		return "listen(): Error listening on socket ";
	}
};
