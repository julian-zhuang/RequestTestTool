#include "RequestTestTool.h"
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <qfiledialog.h>
RequestTestTool::RequestTestTool(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	ui.tableWidget_Header->setColumnCount(2);
	ui.tableWidget_values->setColumnCount(2);
	m_StringList_Header.append(QString::fromLocal8Bit("头标签"));
	m_StringList_Header.append(QString::fromLocal8Bit("值"));
	m_StringList_Values.append(QString::fromLocal8Bit("参数名称"));
	m_StringList_Values.append(QString::fromLocal8Bit("值"));
	m_StringList_Socket.append(QString::fromLocal8Bit("参数类型"));
	m_StringList_Socket.append(QString::fromLocal8Bit("值"));

	ui.lcdNumber_Send->setDecMode();
	ui.lcdNumber_Recv->setDecMode();

	ui.tableWidget_Header->setHorizontalHeaderLabels(m_StringList_Header);
	ui.tableWidget_values->setHorizontalHeaderLabels(m_StringList_Socket);

	ui.tableWidget_Header->setVisible(false);
	ui.tableWidget_values->setHorizontalHeaderLabels(m_StringList_Socket);
	ui.pushButton_Connect->setVisible(true);

	ui.tableWidget_values->horizontalHeader()->setStretchLastSection(true); //均分行
	ui.tableWidget_values->setAlternatingRowColors(true);
	ui.tableWidget_values->verticalHeader()->setVisible(false);   //隐藏列表头 
	ui.tableWidget_values->horizontalHeader()->setStretchLastSection(true);//关键  
	ui.tableWidget_values->setSelectionMode(QAbstractItemView::SingleSelection);//单击选中整行
	ui.tableWidget_values->setSelectionBehavior(QAbstractItemView::SelectRows);

	ui.tableWidget_Header->horizontalHeader()->setStretchLastSection(true); //均分行
	ui.tableWidget_Header->setAlternatingRowColors(true);
	ui.tableWidget_Header->verticalHeader()->setVisible(false);   //隐藏列表头 
	ui.tableWidget_Header->horizontalHeader()->setStretchLastSection(true);//关键  
	ui.tableWidget_Header->setSelectionMode(QAbstractItemView::SingleSelection);//单击选中整行
	ui.tableWidget_Header->setSelectionBehavior(QAbstractItemView::SelectRows);

	connect(ui.comboBox_RequestType, SIGNAL(currentIndexChanged(int)), this, SLOT(RequestTypeClick(int)));
	connect(ui.pushButton_Request, SIGNAL(clicked()), this, SLOT(Sendclick()));
	connect(ui.lineEdit_Address, SIGNAL(editingFinished()), this, SLOT(LineEditEnd()));
	connect(ui.pushButton_Request, SIGNAL(clicked()), this, SLOT(RequestClick()));


	QAction *m_Action = NULL;
	m_Action = new QAction(QString::fromLocal8Bit("添加"));
	connect(m_Action, SIGNAL(triggered()), this, SLOT(AddHeader()));
	ui.tableWidget_Header->addAction(m_Action);
	m_Action = new QAction(QString::fromLocal8Bit("批量添加"));
	connect(m_Action, SIGNAL(triggered()), this, SLOT(AddSHeader()));
	ui.tableWidget_Header->addAction(m_Action);
	m_Action = new QAction(QString::fromLocal8Bit("删除"));
	connect(m_Action, SIGNAL(triggered()), this, SLOT(DelHeader()));
	ui.tableWidget_Header->addAction(m_Action);
	m_Action = new QAction(QString::fromLocal8Bit("清空"));
	connect(m_Action, SIGNAL(triggered()), this, SLOT(CleanHeader()));
	ui.tableWidget_Header->addAction(m_Action);
	ui.tableWidget_Header->setContextMenuPolicy(Qt::ActionsContextMenu);

	m_Action = new QAction(QString::fromLocal8Bit("添加"));
	connect(m_Action, SIGNAL(triggered()), this, SLOT(AddValues()));
	ui.tableWidget_values->addAction(m_Action);
	m_Action = new QAction(QString::fromLocal8Bit("批量添加"));
	connect(m_Action, SIGNAL(triggered()), this, SLOT(AddSValues()));
	ui.tableWidget_values->addAction(m_Action);
	m_Action = new QAction(QString::fromLocal8Bit("删除"));
	connect(m_Action, SIGNAL(triggered()), this, SLOT(DelValues()));
	ui.tableWidget_values->addAction(m_Action);
	m_Action = new QAction(QString::fromLocal8Bit("清空"));
	connect(m_Action, SIGNAL(triggered()), this, SLOT(CleanValues()));

	ui.tableWidget_values->addAction(m_Action);
	ui.tableWidget_values->setContextMenuPolicy(Qt::ActionsContextMenu);

	m_Action = new QAction(QString::fromLocal8Bit("清空"));
	connect(m_Action, SIGNAL(triggered()), this, SLOT(CleanResponse()));
	ui.textBrowser_Response->addAction(m_Action);
	ui.textBrowser_Response->setContextMenuPolicy(Qt::ActionsContextMenu);

	m_Action = new QAction(QString::fromLocal8Bit("清空"));
	connect(m_Action, SIGNAL(triggered()), this, SLOT(CleanRequest()));
	ui.textBrowser_Request->addAction(m_Action);
	ui.textBrowser_Request->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void RequestTestTool::RequestTypeClick(int index)
{
	//Socket
	if (index == 0) {
		ui.tableWidget_Header->setVisible(false);
		ui.tableWidget_values->setHorizontalHeaderLabels(m_StringList_Socket);
		ui.pushButton_Connect->setVisible(true);
		AddressChecking();
		return;
	}
	//Socket-SSL
	if (index == 1) {
		ui.tableWidget_Header->setVisible(false);
		ui.tableWidget_values->setHorizontalHeaderLabels(m_StringList_Socket);
		ui.pushButton_Connect->setVisible(true);
		AddressChecking();
		return;
	}
	//Http-Get
	if (index == 2) {
		ui.tableWidget_Header->setVisible(true);
		ui.tableWidget_values->setHorizontalHeaderLabels(m_StringList_Values);
		ui.pushButton_Connect->setVisible(false);
		AddressChecking();
		return;
	}
	//Http-Post
	if (index == 3) {
		ui.tableWidget_Header->setVisible(true);
		ui.tableWidget_values->setHorizontalHeaderLabels(m_StringList_Values);
		ui.pushButton_Connect->setVisible(false);
		AddressChecking();
		return;
	}
	//Https-Get
	if (index == 4) {
		ui.tableWidget_Header->setVisible(true);
		ui.tableWidget_values->setHorizontalHeaderLabels(m_StringList_Values);
		ui.pushButton_Connect->setVisible(false);
		AddressChecking();
		return;
	}
	//Https-Post
	if (index == 5) {
		ui.tableWidget_Header->setVisible(true);
		ui.tableWidget_values->setHorizontalHeaderLabels(m_StringList_Values);
		ui.pushButton_Connect->setVisible(false);
		AddressChecking();
		return;
	}
	AddressChecking();
}

void RequestTestTool::CleanResponse()
{
	ui.textBrowser_Response->clear();
	ui.lcdNumber_Recv->display(0);
}

void RequestTestTool::CleanHeader()
{
	ui.tableWidget_Header->clear();
	ui.tableWidget_Header->setRowCount(0);
	ui.tableWidget_Header->setHorizontalHeaderLabels(m_StringList_Header);
	
	AddHeader();
	SetTableWidget(ui.tableWidget_Header, ui.tableWidget_Header->rowCount() - 1, 0, "Accept");
	SetTableWidget(ui.tableWidget_Header, ui.tableWidget_Header->rowCount() - 1, 1, "text/html");
	AddHeader();
	SetTableWidget(ui.tableWidget_Header, ui.tableWidget_Header->rowCount() - 1, 0, "Accept-Language");
	SetTableWidget(ui.tableWidget_Header, ui.tableWidget_Header->rowCount() - 1, 1, "zh-CN,zh;q=0.9");
	AddHeader();
	SetTableWidget(ui.tableWidget_Header, ui.tableWidget_Header->rowCount() - 1, 0, "Connection");
	SetTableWidget(ui.tableWidget_Header, ui.tableWidget_Header->rowCount() - 1, 1, "keep-alive");
	AddHeader();
	SetTableWidget(ui.tableWidget_Header, ui.tableWidget_Header->rowCount() - 1, 0, "User-Agent");
	SetTableWidget(ui.tableWidget_Header, ui.tableWidget_Header->rowCount() - 1, 1, "Mozilla/5.0 (Windows NT 10.0; WOW64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/66.0.3359.139 Safari/537.36");
}

void RequestTestTool::CleanValues()
{
	ui.tableWidget_values->clear();
	ui.tableWidget_values->setRowCount(0);
	ui.tableWidget_values->setHorizontalHeaderLabels(m_StringList_Values);
}

void RequestTestTool::CleanRequest()
{
	ui.textBrowser_Request->clear();
	ui.lcdNumber_Send->display(0);
}

void RequestTestTool::AddHeader()
{
	ui.tableWidget_Header->insertRow(ui.tableWidget_Header->rowCount());
}

void RequestTestTool::AddValues()
{
	ui.tableWidget_values->insertRow(ui.tableWidget_values->rowCount());
}

void RequestTestTool::AddSHeader()
{
	CleanHeader();
	return;
	QString FilePath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("选择文件"), "/", "*.txt");
}

void RequestTestTool::AddSValues()
{
	CleanValues();
	QString FilePath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("选择文件"), "/", "*.txt");
}

void RequestTestTool::DelHeader()
{
	ui.tableWidget_Header->removeRow(ui.tableWidget_Header->currentRow());
}

void RequestTestTool::DelValues()
{
	ui.tableWidget_values->removeRow(ui.tableWidget_values->currentRow());
}

void RequestTestTool::RequestClick()
{
	if (ui.comboBox_RequestType->currentIndex() == 2) {
		HttpGetRequest();
		ui.textBrowser_Response->clear();
		ui.lcdNumber_Recv->display(0);
		ui.lcdNumber_Send->display(0);
	}
	if (ui.comboBox_RequestType->currentIndex() == 3) {
		HttpPostRequest();
		ui.textBrowser_Response->clear();
		ui.lcdNumber_Recv->display(0);
		ui.lcdNumber_Send->display(0);
	}
}

void RequestTestTool::LineEditEnd()
{
	AddressChecking();
}

void RequestTestTool::SendRequest()
{
	int writecount = 0;
	if (ui.comboBox_RequestType->currentIndex() == 2 || ui.comboBox_RequestType->currentIndex() == 4) {
		m_socket.write(RequestHeader.str().c_str(), RequestHeader.str().length());
	}

	if (ui.comboBox_RequestType->currentIndex() == 3 || ui.comboBox_RequestType->currentIndex() == 5) {
		m_socket.write(RequestHeader.str().c_str(), RequestHeader.str().length());
		m_socket.write(RequestData.str().c_str(), RequestData.str().length());
	}
	
	ui.lcdNumber_Send->display(writecount);
	disconnect(&m_socket, SIGNAL(connected()), this, SLOT(SendRequest()));
	connect(&m_socket, SIGNAL(readyRead()), this, SLOT(ReadResponse()));
}

void RequestTestTool::ReadResponse()
{
	ResponseData.clear();
	ResponseData = m_socket.readAll();
	ui.lcdNumber_Recv->display(ResponseData.size());
	m_socket.disconnect();
	m_socket.waitForDisconnected(5000);
	ui.textBrowser_Response->clear();
	ui.textBrowser_Response->setText("");
	ui.textBrowser_Response->setText(ResponseData.toStdString().c_str());
}

int RequestTestTool::HttpPostRequest()
{
	RequestHeader.clear();
	RequestHeader.str("");
	RequestHeader << "POST " << Path;
	RequestHeader << " HTTP/1.1\r\n";
	RequestHeader << "Host: " << Host;

	RequestData.str("");
	RequestData.clear();
	//构建POST参数
	for (int i = 0; i < ui.tableWidget_values->rowCount(); i++) {

		if (!ui.tableWidget_values->item(i, 0)->text().length() || !ui.tableWidget_values->item(i, 1)->text().length()) {
			continue;
		}

		RequestData << ui.tableWidget_values->item(i, 0)->text().toStdString() << "="
				    << ui.tableWidget_values->item(i, 1)->text().toStdString();

		if (i + 1 < ui.tableWidget_values->rowCount()) {
			RequestData << "&";
		}
	}

	RequestHeader << "\n";
	//添加Header参数
	for (int i = 0; i < ui.tableWidget_Header->rowCount(); i++) {
		RequestHeader << ui.tableWidget_Header->item(i, 0)->text().toStdString() << ": "
					  << ui.tableWidget_Header->item(i, 1)->text().toStdString() << "\r\n";
	}

	RequestHeader << "Content-Length:" << RequestData.str().length();
	RequestHeader << "\r\n";
	
	ui.textBrowser_Request->clear();
	ui.textBrowser_Request->append(RequestHeader.str().c_str());
	ui.textBrowser_Request->append(RequestData.str().c_str());

	m_socket.connectToHost(Host.c_str(), 80, QTcpSocket::ReadWrite);
	connect(&m_socket, SIGNAL(connected()), this, SLOT(SendRequest()));
	return 0;
}

int RequestTestTool::HttpGetRequest()
{
	RequestHeader.clear();
	RequestHeader.str("");
	RequestHeader << "GET " << Path;

	if (ui.tableWidget_values->rowCount() > 0 ) {
		RequestHeader << "?";
	}

	for (int i = 0; i < ui.tableWidget_values->rowCount(); i++) {
		
		if (!ui.tableWidget_values->item(i, 0)->text().length() || !ui.tableWidget_values->item(i, 1)->text().length()) {
			continue;
		}

		RequestHeader << ui.tableWidget_values->item(i, 0)->text().toStdString() << "="
			   << ui.tableWidget_values->item(i, 1)->text().toStdString();
		
		if (i + 1 < ui.tableWidget_values->rowCount()) {
			RequestHeader << "&";
		}
	}

	RequestHeader << " HTTP/1.1\r\n";
	RequestHeader << "Host: " << Host;

	RequestHeader << "\n";

	for (int i = 0; i < ui.tableWidget_Header->rowCount(); i++) {
		RequestHeader << ui.tableWidget_Header->item(i, 0)->text().toStdString() << ": "
			   << ui.tableWidget_Header->item(i, 1)->text().toStdString() << "\r\n";
	}
	RequestHeader << "\r\n\r\n";

	ui.textBrowser_Request->setText(RequestHeader.str().c_str());

	m_socket.connectToHost(Host.c_str(), 80, QTcpSocket::ReadWrite);
	connect(&m_socket, SIGNAL(connected()), this, SLOT(SendRequest()));
	return 0;
}


bool RequestTestTool::AddressChecking()
{
	int RequestType = ui.comboBox_RequestType->currentIndex();
	QString AddressStr = ui.lineEdit_Address->text();
	
	StrList.clear();
	StrList = AddressStr.split("/");

	if (StrList.count() < 2) {
		ui.pushButton_Request->setEnabled(false);
		return false;
	}

	if (StrList[1] != "") {
		ui.pushButton_Request->setEnabled(false);
		return false;
	}
	if (RequestType == 2 || RequestType == 3) {
		StrList = AddressStr.split("/");
		if (!(StrList[0].toLower() == "http:")) {
			ui.lineEdit_Address->setStyleSheet("background-color:red;");
			ui.pushButton_Request->setEnabled(false);
			return false;
		}
	}
	if (RequestType == 4 || RequestType == 5) {
		StrList = AddressStr.split("/");
		if (!(StrList[0].toLower() == "https:")) {
			ui.lineEdit_Address->setStyleSheet("background-color:red;");
			ui.pushButton_Request->setEnabled(false);
			return false;
		}
		
	}
	ui.lineEdit_Address->setStyleSheet("background-color:white;");
	ui.pushButton_Request->setEnabled(true);
	
	Host = StrList[2].toStdString();

	if (ui.comboBox_RequestType->currentIndex() == 2 || ui.comboBox_RequestType->currentIndex() == 4) {
		
	}
	if (ui.comboBox_RequestType->currentIndex() == 3 || ui.comboBox_RequestType->currentIndex() == 5) {

	}
	Path = "/";
	for (int i = 3; i < StrList.count(); i++) {
		Path += StrList[i].toStdString();
		if ((i + 1) < StrList.count()) {
			Path += "/";
		}
	}
	return true;
}

int RequestTestTool::HttpHeaderInit(int PostOrGet)
{
	
	return 0;
}

int SetTableWidget(QTableWidget * Utable, int URow, int UCol, QString UValus)
{
	QTableWidgetItem *m_Item = NULL;
	if (Utable == NULL) { return -1; }
	m_Item = Utable->item(URow, UCol);
	if (m_Item == NULL) {
		Utable->setItem(URow, UCol, new QTableWidgetItem(UValus));
	}
	else {
		m_Item->setText(UValus);
	}
	return 0;
}
