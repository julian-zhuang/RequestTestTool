#include "RequestTestTool.h"
#include <qfiledialog.h>
#include <qmessagebox.h>

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
		ui.lineEdit_ConnectPort->setVisible(true);
		ui.label_Port->setVisible(true);
		AddressChecking();
		return;
	}
	//Http-Get
	if (index == 2) {
		ui.tableWidget_Header->setVisible(true);
		ui.tableWidget_values->setHorizontalHeaderLabels(m_StringList_Values);
		ui.lineEdit_ConnectPort->setVisible(false);
		ui.label_Port->setVisible(false);
		AddressChecking();
		return;
	}
	//Http-Post
	if (index == 3) {
		ui.tableWidget_Header->setVisible(true);
		ui.tableWidget_values->setHorizontalHeaderLabels(m_StringList_Values);
		ui.lineEdit_ConnectPort->setVisible(false);
		ui.label_Port->setVisible(false);
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
	SocketRequestData.clear();
	SocketRequestData.str("");

	HttpRequestHeader.clear();
	HttpRequestHeader.str("");

	HttpRequestData.clear();
	HttpRequestData.str("");

	RequestData.clear();
	RequestData.str("");

	Response.clear();
	Response.str("");

	ui.textBrowser_Response->clear();
	ui.textBrowser_Request->clear();

	ui.lcdNumber_Recv->display(0);
	ui.lcdNumber_Send->display(0);

	if (ui.checkBox_IsSSL->checkState() == Qt::PartiallyChecked) {
		switch (QMessageBox::information(NULL, "Information", "Enable SSL?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, QMessageBox::No))
		{
		case QMessageBox::Yes:
			ui.checkBox_IsSSL->setCheckState(Qt::Checked);
		case QMessageBox::No:
			ui.checkBox_IsSSL->setCheckState(Qt::Unchecked);
		case QMessageBox::Cancel:
			ui.checkBox_IsSSL->setCheckState(Qt::Unchecked);
			return;
		default:
			ui.checkBox_IsSSL->setCheckState(Qt::Unchecked);
			break;
		}
	}

	if (ui.comboBox_RequestType->currentIndex() == 0) {

		SocketRequestDataIni();

		if (ui.checkBox_IsSSL->checkState() == Qt::Unchecked) {
			m_NetWorkThread = new QNetWorkThread(Host, 80, false, RequestData, Response);
		}

		if (ui.checkBox_IsSSL->checkState() == Qt::Checked) {
			m_NetWorkThread = new QNetWorkThread(Host, 443, true, RequestData, Response);
		}

		connect(m_NetWorkThread, SIGNAL(ThreadSignals(unsigned int, unsigned int)), this, SLOT(ThreadSignal(unsigned int, unsigned int)));
		m_NetWorkThread->start();

	}

	if (ui.comboBox_RequestType->currentIndex() == 1) {

		
		HttpGetRequestDataIni();

		if (ui.checkBox_IsSSL->checkState() == Qt::Unchecked) {
			m_NetWorkThread = new QNetWorkThread(Host, 80, false, RequestData, Response);
		}

		if (ui.checkBox_IsSSL->checkState() == Qt::Checked) {
			m_NetWorkThread = new QNetWorkThread(Host, 443, true, RequestData, Response);
		}
		

		connect(m_NetWorkThread, SIGNAL(ThreadSignals(unsigned int, unsigned int)), this, SLOT(ThreadSignalProcess(unsigned int, unsigned int)));
		m_NetWorkThread->start();
		
	}

	if (ui.comboBox_RequestType->currentIndex() == 2 ) {
		HttpPostRequestDataIni();

		if (ui.checkBox_IsSSL->checkState() == Qt::Unchecked) {
			m_NetWorkThread = new QNetWorkThread(Host, 80, false, RequestData, Response);
		}

		if (ui.checkBox_IsSSL->checkState() == Qt::Checked) {
			m_NetWorkThread = new QNetWorkThread(Host, 443, true, RequestData, Response);
		}

		connect(m_NetWorkThread, SIGNAL(ThreadSignals(unsigned int, unsigned int)), this, SLOT(ThreadSignalProcess(unsigned int, unsigned int)));
		m_NetWorkThread->start();
	}
}

void RequestTestTool::ConnectClick()
{
}

void RequestTestTool::LineEditEnd()
{
	AddressChecking();
}

void RequestTestTool::ThreadSignalProcess(unsigned int Uststus, unsigned int UDatasize)
{
	int m_int = UDatasize;
	switch (Uststus)
	{
	case THREAD_START:
		//线程开始
		ui.pushButton_Request->setEnabled(false);
		break;
	case THREAD_CONNECT_TIMEOUT:
		//连接超时
		disconnect(m_NetWorkThread, SIGNAL(ThreadSignals(unsigned int, unsigned int)), this, SLOT(ThreadSignalProcess(unsigned int, unsigned int)));
		if (m_NetWorkThread) {
			//delete m_NetWorkThread;
		}
		m_NetWorkThread = NULL;
		ui.comboBox_RequestType->setEnabled(true);
		ui.pushButton_Connect->setText(QString::fromLocal8Bit("连接"));
		ui.pushButton_Connect->setEnabled(true);
		ui.pushButton_Request->setText(QString::fromLocal8Bit("发送"));
		ui.pushButton_Request->setEnabled(true);
		QMessageBox::about(NULL, "Information", QString::fromLocal8Bit("连接超时"));
		break;
	case THREAD_CONNECT_SUCCESS:
		//连接成功
		ui.pushButton_Connect->setText(QString::fromLocal8Bit("断开"));
		ui.pushButton_Request->setText(QString::fromLocal8Bit("终止"));
		break;
	case THREAD_SEND_SUCCESS_COUNT:
		//发送数据计数
		ui.lcdNumber_Send->display(m_int);
		break;
	case THREAD_SEND_SUCCESS:
		//发送完成
		ui.textBrowser_Request->clear();
		ui.textBrowser_Request->setText(RequestData.str().c_str());
		break;
	case THREAD_RECV_TIMEOUT:
		//读取超时
		disconnect(m_NetWorkThread, SIGNAL(ThreadSignals(unsigned int, unsigned int)), this, SLOT(ThreadSignalProcess(unsigned int, unsigned int)));
		if (m_NetWorkThread) {
			//delete m_NetWorkThread;
		}
		m_NetWorkThread = NULL;
		ui.comboBox_RequestType->setEnabled(true);
		ui.pushButton_Connect->setText(QString::fromLocal8Bit("连接"));
		ui.pushButton_Connect->setEnabled(true);
		ui.pushButton_Request->setText(QString::fromLocal8Bit("发送"));
		ui.pushButton_Request->setEnabled(true);
		QMessageBox::about(NULL, "Information", QString::fromLocal8Bit("读取超时"));

		break;
	case THREAD_RECV_SUCCESS_COUNT:
		//读取计数
		ui.lcdNumber_Recv->display(m_int);
		break;
	case THREAD_RECV_SUCCESS:
		//读取完成
		ui.textBrowser_Response->clear();
		ui.textBrowser_Response->setText(Response.str().c_str());
		break;
	case THREAD_CONNECTED:
		//连接断开
		disconnect(m_NetWorkThread, SIGNAL(ThreadSignalProcess(unsigned int, unsigned int)), this, SLOT(ThreadSignalProcess(unsigned int, unsigned int)));
		if (m_NetWorkThread) {
			//delete m_NetWorkThread;
		}
		m_NetWorkThread = NULL;
		ui.comboBox_RequestType->setEnabled(true);
		ui.pushButton_Connect->setText(QString::fromLocal8Bit("连接"));
		ui.pushButton_Connect->setEnabled(true);
		ui.pushButton_Request->setText(QString::fromLocal8Bit("发送"));
		ui.pushButton_Request->setEnabled(true);
		QMessageBox::about(NULL, "Information", QString::fromLocal8Bit("连接断开"));
		break;
	case THREAD_SSL_FALLED:
		QMessageBox::about(NULL, "Information", QString::fromLocal8Bit("SSL建立握手失败"));
		break;
	case THREAD_END:
		//线程结束
		disconnect(m_NetWorkThread, SIGNAL(ThreadSignals(unsigned int, unsigned int)), this, SLOT(ThreadSignalProcess(unsigned int, unsigned int)));
		if (m_NetWorkThread) {
			//delete m_NetWorkThread;
		}
		m_NetWorkThread = NULL;
		ui.comboBox_RequestType->setEnabled(true);
		ui.pushButton_Connect->setText(QString::fromLocal8Bit("连接"));
		ui.pushButton_Connect->setEnabled(true);
		ui.pushButton_Request->setText(QString::fromLocal8Bit("发送"));
		ui.pushButton_Request->setEnabled(true);
		QMessageBox::about(NULL, "Information", QString::fromLocal8Bit("本次通讯结束！"));
		break;
	
	default:
		break;
	}
}

int RequestTestTool::HttpPostRequestDataIni()
{
	HttpRequestHeader.str("");
	HttpRequestHeader << "POST" << " " << Path << " " << "HTTP/1.1\r\n";
	HttpRequestHeader << "Host:" << " " << Host << "\r\n";

	HttpRequestData.str("");
	HttpRequestData.clear();
	//构建POST参数
	for (int i = 0; i < ui.tableWidget_values->rowCount(); i++) {

		if (!ui.tableWidget_values->item(i, 0)->text().length() || !ui.tableWidget_values->item(i, 1)->text().length()) {
			continue;
		}

		HttpRequestData 
				<< ui.tableWidget_values->item(i, 0)->text().toStdString() << "="
				<< ui.tableWidget_values->item(i, 1)->text().toStdString();

		if (i + 1 < ui.tableWidget_values->rowCount()) {
			HttpRequestData << "&";
		}
	}

	HttpRequestHeader << "\r\n";
	//添加Header参数
	for (int i = 0; i < ui.tableWidget_Header->rowCount(); i++) {
		HttpRequestHeader
				<< ui.tableWidget_Header->item(i, 0)->text().toStdString() << ": "
				<< ui.tableWidget_Header->item(i, 1)->text().toStdString() << "\r\n";
	}

	//HttpRequestHeader << "Content-Length:" << HttpRequestData.str().length();
	HttpRequestHeader << "\r\n";

	RequestData.clear();
	RequestData.str("");
	RequestData << HttpRequestHeader.str() << HttpRequestData.str();

	return 0;
}

int RequestTestTool::HttpGetRequestDataIni()
{
	HttpRequestHeader.clear();
	HttpRequestHeader.str("");
	HttpRequestHeader << "GET" << " " << Path;

	if (ui.tableWidget_values->rowCount() > 0) {
		HttpRequestHeader << "?";
	}

	//添加GET参数
	for (int i = 0; i < ui.tableWidget_values->rowCount(); i++) {

		if (ui.tableWidget_values->item(i, 0) == NULL) {
			continue;
		}

		if (ui.tableWidget_values->item(i, 1) == NULL) {
			continue;
		}

		HttpRequestHeader
			<< ui.tableWidget_values->item(i, 0)->text().toStdString() 
			<< "="
			<< ui.tableWidget_values->item(i, 1)->text().toStdString();

		if (i + 1 < ui.tableWidget_values->rowCount()) {
			HttpRequestHeader << "&";
		}
	}

	//构建头
	HttpRequestHeader << " " << "HTTP/1.1\r\n";
	HttpRequestHeader << "Host: " << Host << "\r\n";

	for (int i = 0; i < ui.tableWidget_Header->rowCount(); i++) {
		HttpRequestHeader
			<< ui.tableWidget_Header->item(i, 0)->text().toStdString() << ": "
			<< ui.tableWidget_Header->item(i, 1)->text().toStdString() << "\r\n";
	}
	HttpRequestHeader << "\r\n";

	RequestData.clear();
	RequestData.str("");
	RequestData << HttpRequestHeader.str();

	return 0;
}

int RequestTestTool::SocketRequestDataIni()
{
	SocketRequestData.str("");
	for (int i = 0; i < ui.tableWidget_values->rowCount(); i++) {
		if (ui.tableWidget_values->item(i, 0) == NULL) {
			continue;
		}
		if (ui.tableWidget_values->item(i, 1) == NULL) {
			continue;
		}
		if (ui.tableWidget_values->item(i, 0)->text().length() < 3) {
			continue;
		}
		if (ui.tableWidget_values->item(i, 1)->text().length() == 0) {
			continue;
		}
		if (ui.tableWidget_values->item(i, 0)->text() == "Int") {
			int m_Int = ui.tableWidget_values->item(i, 1)->text().toInt();
			SocketRequestData.write((const char*)&(m_Int), sizeof(int));
		}
		if (ui.tableWidget_values->item(i, 0)->text() == "UInt") {
			unsigned int m_UInt = ui.tableWidget_values->item(i, 1)->text().toUInt();
			SocketRequestData.write((const char*)&(m_UInt), sizeof(unsigned int));
		}
		if (ui.tableWidget_values->item(i, 0)->text() == "Char") {
			SocketRequestData.write(ui.tableWidget_values->item(i, 1)->text().toStdString().c_str(), 1);
		}
		if (ui.tableWidget_values->item(i, 0)->text() == "Double") {
			double m_Double = ui.tableWidget_values->item(i, 1)->text().toDouble();
			SocketRequestData.write((char*)&m_Double, sizeof(double));
		}
		if (ui.tableWidget_values->item(i, 0)->text() == "String") {
			SocketRequestData.write(ui.tableWidget_values->item(i, 1)->text().toStdString().c_str(), ui.tableWidget_values->item(i, 1)->text().length());
		}
	}
	RequestData.clear();
	RequestData.str("");
	RequestData << SocketRequestData.str();
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
