#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_RequestTestTool.h"


class RequestTestTool : public QMainWindow
{
	Q_OBJECT

public:
	RequestTestTool(QWidget *parent = Q_NULLPTR);

public slots:
	void RequestTypeClick(int index);
	
	void CleanReturn();
	void CleanHeader();
	void CleanValues();

	void AddHeader();
	void AddValues();

	void AddSHeader();
	void AddSValues();

	void DelHeader();
	void DelValues();

private:
	Ui::RequestTestToolClass ui;
	QStringList m_StringList_Values;
	QStringList m_StringList_Header;
	QStringList m_StringList_Socket;
};
