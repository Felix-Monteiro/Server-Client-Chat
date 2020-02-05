#pragma once
#include <iostream>
#include <exception>
#include <cassert>

using namespace std;

class BytesSendException : public exception {
public:
	virtual const char* what() const throw()
	{
		return "Server: send() error ";
	}
};