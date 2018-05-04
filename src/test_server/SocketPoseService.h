#ifndef SOCKETPOSESERVICE_H
#define SOCKETPOSESERVICE_H

#include "TinyTcpServer.h"
#include <functional>

class SocketPoseService
{
    typedef std::function<void(int session)> OnConnect;
    typedef std::function<void(int session)> OnDisconnect;
    typedef std::function<void(int session, const char *buf, int len)> OnRecv;
public:
    SocketPoseService();
    ~SocketPoseService();

    void getPose(float pos[3], float rot[3]);

private:
    void onConnect(int session);
    void onDisconnect(int session);
    void onRecv(int session, const char *buf, int len);

    float mPos[3] = { 0.0f, 0.0f, 0.0f };
    float mRot[3] = { 0.0f, 0.0f, 0.0f };
    TinyTcpServer mTcpServer;

    OnConnect onConnectCB = nullptr;
    OnDisconnect onDisconnectCB = nullptr;
    OnRecv onRecvCB = nullptr;
};

#endif // SOCKETPOSESERVICE_H
