// Server.cpp
//
#include <iostream>
#include "Server.h"
#include "Comms.h"

using namespace std;

Server::Server()
{
}

Server::~Server()
{
}

int Server::Abstract()
{
	Comms::StartUp();//WSAStartup
	return 0;
}


int Server::NewSocket()throw(SocketException) 
{
	// DLL has made a successful WSAStartup() call, it can proceed to make other Windows Sockets calls
	//Creates a new Socket
	serverSocket = INVALID_SOCKET;
	serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serverSocket == INVALID_SOCKET) 
	{
		throw ScktE;
		WSACleanup();//call WSACleanup() for every successful WSAStartup() call
		return 0;
	}
	else 
	{
		cout << "socket() is OK!" << endl;
	}
}

int Server::SocketBind()throw(BindException,ListenException)
{
	service.sin_family = AF_INET;
	InetPton(AF_INET, _T("127.0.0.1"), &service.sin_addr.s_addr);
	service.sin_port = htons(port);

	//binds the socket to the servers IP address and a valid port
	if (bind(serverSocket, (SOCKADDR*)&service, sizeof(service)) == SOCKET_ERROR) 
	{
		throw BndE;
		closesocket(serverSocket);
		WSACleanup();
		return 0;
	}
	else 
	{
		cout << "bind() is OK!" << endl;
	}

	//Once the socket is bound to a portand IP address it can be placed into a listening state
	if (listen(serverSocket, 1) == SOCKET_ERROR) 
	{

		throw LtnE;
	}
	else 
	{
		cout << "listen() is OK, I'm waiting for connections..." << endl;
	}


}

int Server::Messages()throw(AcceptSocketException, BytesRecvException, BytesSendException)
{
	while (1) 
	{
		//accept function waits for client connection requests.On receiving one it returns a new socket that is connected to the client
		acceptSocket = accept(serverSocket, NULL, NULL);

		if (acceptSocket == INVALID_SOCKET) 
		{
			throw AccScktE;
			return -1;
		}
		else 
		{
			cout << "Server: Client Connected!" << endl;
		}

		bytesSent = SOCKET_ERROR;
		bytesRecv = SOCKET_ERROR;

		while (1) {
			//On receipt of a message the server sends an automatic confirmation message back to the client 
			bytesRecv = recv(acceptSocket, buffer, 200, 0);

			if (bytesRecv == SOCKET_ERROR)
			{
				throw RecvE;

			}
			else 
			{
				cout << "Server: recv() is OK." << endl;
				cout << "Server: Received data is: " << buffer << endl;
				cout << "Server: Bytes received: " << bytesRecv << endl;
			}

			if (strcmp(buffer, "QUIT") == 0) 
			{
				break;
			}

			//Sends a message to the Client
			cout << "Enter Your message" << endl;
			cin.getline(sendBuffer, 200);
			bytesSent = send(acceptSocket, sendBuffer, strlen(sendBuffer), 0);
			if (bytesSent == SOCKET_ERROR)
			{
				throw SendE;
			}

			else {
				cout << "Server: sent " << bytesSent << " bytes" << endl;
				if (strcmp(sendBuffer, "QUIT") == 0) 
				{
					break;
				}
			}
		}
	}
	system("pause");
	WSACleanup();
	return 0;
}