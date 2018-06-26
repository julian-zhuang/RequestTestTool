#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_RequestTestTool.h"
#include <qtcpsocket.h>
#include <qsslsocket.h>
#include <iostream>
#include <string>
#include <sstream>  
#include <QThread>

#define THREAD_START 100
#define THREAD_CONNECT_SUCCESS 1021
#define THREAD_CONNECT_TIMEOUT 102
#define THREAD_SEND_SUCCESS_COUNT 103
#define THREAD_SEND_SUCCESS 104
#define THREAD_SEND_TIMEOUT 105
#define THREAD_RECV_SUCCESS_COUNT 106
#define THREAD_RECV_SUCCESS 107
#define THREAD_RECV_TIMEOUT 108
#define THREAD_CONNECTED 109
#define THREAD_END 110

#define THREAD_SSL_SUCCESSFUL 111
#define THREAD_SSL_FALLED 112

int SetTableWidget(QTableWidget *Utable, int URow, int UCol, QString UValus);


class NetWorkThread :public QThread
{
	Q_OBJECT

signals:
	void ThreadSignals(unsigned int Uststus, unsigned int UDatasize);
	/*
	100 线程开始
	400 连接错误
	500 发送中状态
	600 读取中状态
	700 线程结束
	*/
public:
	NetWorkThread() = delete;
	NetWorkThread(NetWorkThread &) = delete;
	NetWorkThread(std::string UHost, unsigned int UPort, bool USSLStatus, std::stringstream &URequestData, std::stringstream &UResponse) 
				  :Host(UHost), Port(UPort), RequestData(URequestData), Response(UResponse) , SSLStats(USSLStatus){
		TimeOut = 5000;
		SSLStats = false;
		isEncryption = false;
	};
	/*
	UHost : 地址
	UPort : 端口
	USSLStatus : 是否开启SSL
	URequestData : 需要发送的数据
	UResponse : 接收数据
	*/
	~NetWorkThread();
	void SetTimeOut(unsigned int UtimeOut);
	void run();
public slots:
	void NW_Disconnect();
	void NW_Error(QAbstractSocket::SocketError socketError);
	void NWSSLError();
	void NW_Encrypted();
private:
	unsigned int TimeOut;
	int IRecvCout;
	std::string Host;
	unsigned int Port;
	bool SSLStats;
	bool isEncryption;
	std::stringstream &RequestData;
	std::stringstream &Response;
	
};

class RequestTestTool : public QMainWindow
{
	Q_OBJECT

public:
	RequestTestTool(QWidget *parent = Q_NULLPTR);

public slots:
	void RequestTypeClick(int index);
	
	void CleanResponse();
	void CleanHeader();
	void CleanValues();
	void CleanRequest();

	void AddHeader();
	void AddValues();

	void AddSHeader();
	void AddSValues();

	void DelHeader();
	void DelValues();

	void RequestClick();
	void LineEditEnd();
	
	void ThreadSignalProcess(unsigned int Uststus, unsigned int UDatasize);
public:
	int HttpPostRequestDataIni();
	int HttpGetRequestDataIni();
	int HttpSPostRequesDataInit();
	int HttpSGetRequestDataIni();
	/*int SocketRequest();
	int SocketSSLRequest();*/
	bool AddressChecking();
private:
	Ui::RequestTestToolClass ui;
	NetWorkThread *m_NetWorkThread;

	QStringList m_StringList_Values;
	QStringList m_StringList_Header;
	QStringList m_StringList_Socket;
	
	QStringList StrList;

	std::stringstream HttpRequestHeader;
	std::stringstream HttpRequestData;

	std::stringstream RequestData;
	std::stringstream Response;
	std::string Host;
	std::string Path;
};
