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
	100�ȴ�����
	200�ȴ�����
	200�������
	299
	300�������
	400�Ͽ�
	500�߳̽���
	���ӳɹ����û�п������󣬳�ʱ���߳̽��˳�.
	���ӳɹ�ǰ���û�п��������߳̽���Զ���ڵȴ�״̬.����л��������ͻ����޸Ĳ������߳̽��˳�
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
