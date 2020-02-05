#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include "iostream"
#include <tchar.h>
#include "Comms.h"
#include <iostream>
#include "windows.h"
//Client Exceptions
#include"SocketException.h"
#include"ConnectionException.h"
#include "ClientSendException.h"
#include "ClientReceiveException.h"

class Client : public Comms
{
public:

	SOCKET clientSocket;
	sockaddr_in clientService;
	int byteCount;
	char buffer[200];
	char receiveBuffer[200] = "";

	Client();
	~Client();
	int Abstract();
	int NewSocket();
	int Connection();
	int Messages();

private:

	SocketException ScktE;
	ConnectionException CntE;
	ClientSendException CltsendE;
	ClientReceiveException CltrecvE;
};
