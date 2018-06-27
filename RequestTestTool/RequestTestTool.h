#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_RequestTestTool.h"
#include "QNetWorkThread.h"

int SetTableWidget(QTableWidget *Utable, int URow, int UCol, QString UValus);

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
	void ConnectClick();
	void LineEditEnd();
	
	void ThreadSignalProcess(unsigned int Uststus, unsigned int UDatasize);
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

	std::stringstream HttpRequestHeader;
	std::stringstream HttpRequestData;
	std::stringstream SocketRequestData;

	std::stringstream RequestData;
	std::stringstream Response;
	std::string Host;
	std::string Path;
};
