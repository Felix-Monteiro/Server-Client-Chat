//Client.cpp
#include "Client.h"
#include <iostream>
#include "windows.h"

using namespace std;

Client::Client()
{
}

Client::~Client()
{
}

int Client::Abstract()
{
	Comms::StartUp();//WSAStartup
	return 0;
}

int Client::NewSocket()throw(SocketException)
{
	//Creates a new Socket
	clientSocket = INVALID_SOCKET;
	clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (clientSocket == INVALID_SOCKET)
	{
		throw ScktE;
		WSACleanup();
		return 0;
	}
	else 
	{
		cout << "socket() is OK!" << endl;
	}
}

int Client::Connection()throw(ConnectionException)
{
	//Instructs the client to connect to the server
	clientService.sin_family = AF_INET;
	InetPton(AF_INET, _T("127.0.0.1"), &clientService.sin_addr.s_addr);
	clientService.sin_port = htons(port);

	if (connect(clientSocket, (SOCKADDR*)&clientService, sizeof(clientService)) == SOCKET_ERROR) 
	{
		throw CntE;
		WSACleanup();
		return 0;
	}
	else 
	{
		cout << "Client: connect() is OK." << endl;
		cout << "Client: Can start sending and receiving data..." << endl;
	}
}
int Client::Messages()throw(ClientSendException, ClientReceiveException)
{
	byteCount = SOCKET_ERROR;
	while (1) 
	{
		//Sends a message to the Server
		cout << "Enter your message ";
		cin.getline(buffer, 200);
		byteCount = send(clientSocket, buffer, 200, 0);

		if (byteCount == SOCKET_ERROR) 
		{
			throw CltsendE;
		}
		else 
		{
			cout << "Client: sent " << byteCount << " bytes" << endl;
		}
		if (strcmp(buffer, "QUIT") == 0) 
		{
			break;
		}
		//On receipt of a message the Client sends an automatic confirmation message back to the client 
		byteCount = recv(clientSocket, receiveBuffer, 200, 0);

		if (byteCount == 0 || byteCount == WSAECONNRESET) 
		{
			cout << "Client: Connection Closed." << endl;
		}
		if (byteCount < 0) 
		{
			throw CltrecvE;
		}
		else 
		{
			cout << "Client: recv() is OK." << endl;
			cout << "Client: Received data is: " << receiveBuffer << endl;
			cout << "Client: Bytes received: " << byteCount << endl;

			if (strcmp(buffer, "QUIT") == 0) 
			{
				break;
			}
		}
	}

	system("pause");
	WSACleanup();
	return 0;
}