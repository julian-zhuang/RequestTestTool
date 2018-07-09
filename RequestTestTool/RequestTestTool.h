#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_RequestTestTool.h"
#include "QNetWorkThread.h"
#include <Qqueue>
#include <qbytearray.h>
int SetTableWidget(QTableWidget *Utable, int URow, int UCol, QString UValus);

class RequestTestTool : public QMainWindow
{
	Q_OBJECT

public:
	RequestTestTool(QWidget *parent = Q_NULLPTR);

public slots:
	void RequestTypeChange(int index);
	void LineEditPort();
	void EnableKeepAlive(int UStatus);
	void EnableSSL(int UStatus);
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
	void DisConnectClick();
	void LineEditEnd();
	
	void ThreadSignalProcess(unsigned int Uststus, unsigned int UDatasize);
	void ThreadContorlProcess(unsigned int Uststus,unsigned int* UControlCode);
public:
	int HttpPostRequestDataIni();
	int HttpGetRequestDataIni();
	int SocketRequestDataIni();
	bool AddressChecking();
private:

	Ui::RequestTestToolClass ui;
	QNetWorkThread *m_NetWorkThread;

	QStringList m_StringList_Values;
	QStringList m_StringList_Header;
	QStringList m_StringList_Socket;
	
	QStringList StrList;

	QQueue<int>m_queue;
	/*
	100等待连接
	200等待发送
	200发送完成
	299
	300接收完成
	400断开
	500线程结束
	连接成功如果没有控制需求，超时后线程将退出.
	连接成功前如果没有控制需求，线程将永远处于等待状态.如果切换请求类型或者修改参数表线程将退出
	*/

	bool DisconnectPusbuttonClick;
	bool WaitingSend;
	bool Connecting;
	bool PortCustomize;
	std::stringstream HttpRequestHeader;
	std::stringstream HttpRequestData;
	std::stringstream SocketRequestData;

	std::stringstream RequestData;
	std::stringstream Response;
	std::string Host;
	std::string Path;
};
