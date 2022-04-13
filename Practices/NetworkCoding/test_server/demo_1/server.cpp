#include "server.h"

#include <cassert>
#include <string>

Server::Server(u_short port)
    : m_port(port),
      m_listenSocket(INVALID_SOCKET),
      m_completePort(NULL),
      lpfnAcceptEx(nullptr),
      m_currentAccetSocket(INVALID_SOCKET),
      m_ioCompletePort(NULL),
      m_running(false),
      m_acceptBuffer(1024) {}

Server::~Server() {
    if (m_listenSocket != INVALID_SOCKET)
        closesocket(m_listenSocket);
    CloseHandle(m_ioCompletePort);
    CloseHandle(m_completePort);
}

bool Server::startAccept() {
    m_completePort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
    if (!m_completePort) {
        return false;
    }
    m_ioCompletePort = CreateIoCompletionPort(INVALID_HANDLE_VALUE, NULL, 0, 0);
    if (!m_ioCompletePort) {
        return false;
    }
    m_listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (m_listenSocket == INVALID_SOCKET) {
        return false;
    }
    CreateIoCompletionPort((HANDLE)m_listenSocket, m_completePort, 0, 0);
}
