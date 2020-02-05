#pragma once
#include <iostream>
#include <exception>
#include <cassert>

using namespace std;

class WinSockException : public exception {
public:
	virtual const char* what() const throw()
	{
		return "The Winsock dll not found!";
	}
};
