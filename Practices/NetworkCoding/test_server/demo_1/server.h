#ifndef SERVER_H
#define SERVER_H

#define WIN32_LEAN_AND_MEAN

#include <mswsock.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#include <cstdio>
#include <functional>
#include <iostream>
#include <vector>

#include "server_socket.h"

class Server {
public:
    Server(u_short port);
    ~Server();
    bool startAccept();
    void waitingForAccept();
    void waitingForIO();
    bool isRunning() const { return m_running; }
    void stop() { m_running = false; }
    typedef std::function<void(ServerSocket::pointer)> HandleNewConnect;
    HandleNewConnect newConn;
    ServerSocket::HandleRecvFunction socketRecv;
    ServerSocket::HandleClose socketRecv;
    ServerSocket::HandleError socketRecv;

private:
    u_short m_port;
    SOCKET m_listenSocket;
    HANDLE m_completePort;
    LPFN_ACCEPTEX lpfnAcceptEx;
    SOCKET m_currentAccetSocket;
    WSAOVERLAPPED m_acceptUnit;
    HANDLE m_ioCompletePort;
    bool m_running;
    std::vector<char> m_acceptBuffer;
    bool tryNewConn();
};

#endif
