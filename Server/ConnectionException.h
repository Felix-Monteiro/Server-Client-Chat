#pragma once
#include <iostream>
#include <exception>
#include <cassert>

using namespace std;

class ConnectionException : public exception {
public:
	virtual const char* what() const throw()
	{
		return "Client: connect() - Failed to connect.";
	}
};
