#pragma once
#include <winsock2.h>
#include <ws2tcpip.h>
#include "iostream"
#include <tchar.h>
#include "Comms.h"
//Server Exceptions
#include "SocketException.h"
#include "BindException.h"
#include "ListenException.h"
#include "AcceptSocketException.h"
#include "BytesRecvException.h"
#include "BytesSendException.h"

class Server :public Comms
{
public:

	SOCKET serverSocket, acceptSocket;
	sockaddr_in service;
	SOCKADDR_STORAGE from;
	int retval, fromlen, socket_type;
	char servstr[NI_MAXSERV], hoststr[NI_MAXHOST];
	DWORD threadId;
	int bytesSent;
	int bytesRecv;
	char buffer[200] = "";
	char sendBuffer[200];

	Server();
	~Server();
	int Abstract();
	int NewSocket();
	int SocketBind();
	int Messages();

private:

	SocketException ScktE;
	BindException BndE;
	ListenException LtnE;
	AcceptSocketException AccScktE;
	BytesRecvException RecvE;
	BytesSendException SendE;
};



