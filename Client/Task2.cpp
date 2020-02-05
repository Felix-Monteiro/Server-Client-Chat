//Task 2(Setup for the Client): This file contains the 'main' function. Program execution begins and ends there.
#include "Client.h"
#include "Server.h"
#include "Comms.h"
#include <iostream>

using namespace std;

int main()
{
	Server srv;
	Client clt;

	try
	{


#ifdef ServerCode
		srv.Abstract();
		srv.NewSocket();
		srv.SocketBind();
		srv.Messages();
#endif // ServerCode
#define ClientCode
#ifdef ClientCode
		clt.Abstract();
		clt.NewSocket();
		clt.Connection();
		clt.Messages();
#endif // ClientCode

	}

#ifdef ServerCode
	catch (BindException & x)
	{
		cout << x.what() << WSAGetLastError() << endl;
	}
	catch (ListenException & u)
	{
		cout << u.what() << WSAGetLastError() << endl;
	}
	catch (AcceptSocketException & l)
	{
		cout << stderr << l.what() << WSAGetLastError() << endl;
	}
	catch (BytesRecvException & r)
	{
		cout << r.what() << WSAGetLastError() << endl;
	}
	catch (BytesSendException & s)
	{
		cout << s.what() << WSAGetLastError() << endl;
	}
	catch (SocketException & y)
	{
		cout << y.what() << WSAGetLastError() << endl;
	}
	catch (WinSockException & e)
	{
		cout << "WinSock Exception Error:" << e.what() << endl;
	}
#endif // ServerCode


#ifdef ClientCode
	catch (ConnectionException & o)
	{
		cout << o.what() << endl;
	}
	catch (ClientSendException & j)
	{
		cout << j.what() << WSAGetLastError() << endl;
	}
	catch (ClientReceiveException & d)
	{
		cout << d.what() << WSAGetLastError() << endl;
	}
#endif // ClientCode
}