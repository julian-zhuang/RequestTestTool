#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_RequestTestTool.h"


class RequestTestTool : public QMainWindow
{
	Q_OBJECT

public:
	RequestTestTool(QWidget *parent = Q_NULLPTR);

public slots:
	void CleanReturnClick();
	void CleanValueClick();
	void RequestTypeClick(int index);
private:
	Ui::RequestTestToolClass ui;
};
