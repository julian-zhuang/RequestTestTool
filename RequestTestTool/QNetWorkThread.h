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
	void ThreadSignals(unsigned int Uststus, unsigned int UDatasize);
	/*
	100 线程开始
	400 连接错误
	500 发送中状态
	600 读取中状态
	700 线程结束
	*/
public:
	QNetWorkThread() = delete;
	QNetWorkThread(QNetWorkThread &) = delete;
	QNetWorkThread(std::string UHost, unsigned int UPort, bool USSLStatus, std::stringstream &URequestData, std::stringstream &UResponseData)
		:Host(UHost), Port(UPort), RequestData(URequestData), ResponseData(UResponseData), SSLStats(USSLStatus) {
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
	void run();
public slots:
	void NW_Disconnect();
	void NW_Error(QAbstractSocket::SocketError socketError);
	void NWSSLError();
	void NW_Encrypted();
private:
	int EstablishConnection();
	int SendRequestData();
	int RecvResponseData();
	unsigned int TimeOut;
	int IRecvCout;
	std::string Host;
	unsigned int Port;
	bool once;
	bool SSLStats;
	bool isEncryption;

	std::stringstream &RequestData; //请求数据
	std::stringstream &ResponseData;//相应数据

	QSslSocket m_SSLsocket;
	QTcpSocket m_socket;
};
