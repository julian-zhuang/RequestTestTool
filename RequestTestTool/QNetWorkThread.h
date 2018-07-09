#pragma once

#define THREAD_START 100
#define THREAD_CONNECT_SUCCESS 1021
#define THREAD_CONNECT_TIMEOUT 102
#define THREAD_SEND_SUCCESS_COUNT 103
#define THREAD_SEND_SUCCESS 104
#define THREAD_SEND_TIMEOUT 105
#define THREAD_SEND_FALLED 2324
#define THREAD_RECV_SUCCESS_COUNT 106
#define THREAD_RECV_SUCCESS 107
#define THREAD_RECV_TIMEOUT 108
#define THREAD_CONNECTED 109
#define THREAD_END 110

#define THREAD_SSL_SUCCESSFUL 111
#define THREAD_SSL_FALLED 112

#define THREAD_CONTROL_CONTINUE 8978;
#define THREAD_CONTROL_STOP 8975;
#define THREAD_CONTROL_NEXT 89348;

#include <QThread>
#include <qtcpsocket.h>
#include <qsslsocket.h>
#include <QThread>

#include <iostream>
#include <string>
#include <sstream> 
#include <fstream>

class QNetWorkThread : public QThread
{
	Q_OBJECT

signals :
	void ThreadStatusSignals(unsigned int Uststus, unsigned int UDatasize);
	/*
	100 线程开始
	400 连接错误
	500 发送中状态
	600 读取中状态
	700 线程结束
	*/
	void ThreadContorlSignals(unsigned int Uststus,unsigned int *UContorl);
public:
	QNetWorkThread() = delete;
	QNetWorkThread(QNetWorkThread &) = delete;
	QNetWorkThread(std::string UHost, unsigned int UPort, bool USSLEnadble, std::stringstream &URequestData, std::stringstream &UResponseData)
		:Host(UHost), Port(UPort), RequestData(URequestData), ResponseData(UResponseData), SSLEnadble(USSLEnadble) {
		TimeOut = 5000;
		isEncryption = false;
	};
	/*
	UHost : 地址
	UPort : 端口
	USSLStatus : 是否开启SSL
	URequestData : 需要发送的数据
	UResponse : 接收数据
	*/
	~QNetWorkThread();
	void SetTimeOut(unsigned int UtimeOut);
	void SetKeepAlive(bool Ubool);//是否启用长连接

	void run();
public slots:
	void NW_Connected();//连接成功
	void NW_Disconnect();//连接断开
	void NW_Error(QAbstractSocket::SocketError socketError);//发生错误
	void NW_SSLError();//SSL错误
	void NW_Encrypted();//SSL握手成功
private:
	unsigned int m_ContorlCode = 0;
	int WaitForControl(unsigned int Uststus);
	int EstablishConnection();
	int SendRequestData();
	int RecvResponseData();
	unsigned int TimeOut;
	int IRecvCout;
	std::string Host;
	unsigned int Port;
	bool once;
	bool SSLEnadble;
	bool isEncryption;
	bool IsKeepAlive;
	std::stringstream &RequestData; //请求数据
	std::stringstream &ResponseData;//相应数据

	QSslSocket m_SSLsocket;
	QTcpSocket m_socket;
};
