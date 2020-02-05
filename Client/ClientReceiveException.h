#pragma once
#include <iostream>
#include <exception>
#include <cassert>

using namespace std;

class ClientReceiveException : public exception {
public:
	virtual const char* what() const throw()
	{
		return "Client: send() error ";
	}
};
