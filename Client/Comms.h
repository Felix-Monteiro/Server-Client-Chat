#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include "iostream"
#include <tchar.h>
#include <iostream>
#include "windows.h"
//Comms Exceptions
#include "WinSockException.h"

class Comms
{
public:
	WSADATA wsaData;
	int wsaerr;
	WORD wVersionRequested;
	int port;

	Comms();
	~Comms();
	virtual int Abstract() = 0;
	int StartUp();

private:
	WinSockException WinSck;
};
