#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_RequestTestTool.h"
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <iostream>
#include <string>
#include <sstream>  
#include<QMessageBox>
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
	void LineEditEnd();
	
	void SendRequest();
	void ReadResponse();
public:
	int HttpPostRequest();
	int HttpGetRequest();
	/*int HttpSPostRequest();
	int HttpSGetRequest();
	int SocketRequest();
	int SocketSSLRequest();*/
	bool AddressChecking();
private:
	int HttpHeaderInit(int PostOrGet);
	Ui::RequestTestToolClass ui;
	QStringList m_StringList_Values;
	QStringList m_StringList_Header;
	QStringList m_StringList_Socket;
	QTcpSocket m_socket;
	QStringList StrList;
	QByteArray ResponseData;
	std::stringstream RequestHeader;
	std::stringstream RequestData;

	std::string Host;
	std::string Path;
};
