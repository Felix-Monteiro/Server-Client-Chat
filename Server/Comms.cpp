#include "Comms.h"
#include <iostream>
#include "windows.h"

using namespace std;

Comms::Comms()
{
}

Comms::~Comms()
{
}

int Comms::StartUp()throw(WinSockException)
{
	//The application supports only version 2.2 of Windows Sockets makes a WSAStartup() call
	port = 55555;
	wVersionRequested = MAKEWORD(2, 2);
	wsaerr = WSAStartup(wVersionRequested, &wsaData);

	if (wsaerr != 0)
	{
		throw WinSck;
		return 0;
	}
	else {
		cout << "The Winsock dll found!" << endl;
		cout << "The status: " << wsaData.szSystemStatus << endl;
	}

}

