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
	m_StringList_Header.append(QString::fromLocal8Bit("ͷ��ǩ"));
	m_StringList_Header.append(QString::fromLocal8Bit("ֵ"));
	m_StringList_Values.append(QString::fromLocal8Bit("��������"));
	m_StringList_Values.append(QString::fromLocal8Bit("ֵ"));
	m_StringList_Socket.append(QString::fromLocal8Bit("��������"));
	m_StringList_Socket.append(QString::fromLocal8Bit("ֵ"));

	ui.lcdNumber_Send->setDecMode();
	ui.lcdNumber_Recv->setDecMode();

	ui.tableWidget_Header->setHorizontalHeaderLabels(m_StringList_Header);
	ui.tableWidget_values->setHorizontalHeaderLabels(m_StringList_Socket);

	ui.tableWidget_Header->setVisible(false);
	ui.tableWidget_values->setHorizontalHeaderLabels(m_StringList_Socket);
	ui.pushButton_Connect->setVisible(true);

	ui.tableWidget_values->horizontalHeader()->setStretchLastSection(true); //������
	ui.tableWidget_values->setAlternatingRowColors(true);
	ui.tableWidget_values->verticalHeader()->setVisible(false);   //�����б�ͷ 
	ui.tableWidget_values->horizontalHeader()->setStretchLastSection(true);//�ؼ�  
	ui.tableWidget_values->setSelectionMode(QAbstractItemView::SingleSelection);//����ѡ������
	ui.tableWidget_values->setSelectionBehavior(QAbstractItemView::SelectRows);

	ui.tableWidget_Header->horizontalHeader()->setStretchLastSection(true); //������
	ui.tableWidget_Header->setAlternatingRowColors(true);
	ui.tableWidget_Header->verticalHeader()->setVisible(false);   //�����б�ͷ 
	ui.tableWidget_Header->horizontalHeader()->setStretchLastSection(true);//�ؼ�  
	ui.tableWidget_Header->setSelectionMode(QAbstractItemView::SingleSelection);//����ѡ������
	ui.tableWidget_Header->setSelectionBehavior(QAbstractItemView::SelectRows);

	connect(ui.comboBox_RequestType, SIGNAL(currentIndexChanged(int)), this, SLOT(RequestTypeClick(int)));
	//connect(ui.pushButton_Request, SIGNAL(clicked()), this, SLOT(Sendclick()));
	connect(ui.lineEdit_Address, SIGNAL(editingFinished()), this, SLOT(LineEditEnd()));
	connect(ui.pushButton_Request, SIGNAL(clicked()), this, SLOT(RequestClick()));


	QAction *m_Action = NULL;
	m_Action = new QAction(QString::fromLocal8Bit("���"));
	connect(m_Action, SIGNAL(triggered()), this, SLOT(AddHeader()));
	ui.tableWidget_Header->addAction(m_Action);
	m_Action = new QAction(QString::fromLocal8Bit("�������"));
	connect(m_Action, SIGNAL(triggered()), this, SLOT(AddSHeader()));
	ui.tableWidget_Header->addAction(m_Action);
	m_Action = new QAction(QString::fromLocal8Bit("ɾ��"));
	connect(m_Action, SIGNAL(triggered()), this, SLOT(DelHeader()));
	ui.tableWidget_Header->addAction(m_Action);
	m_Action = new QAction(QString::fromLocal8Bit("���"));
	connect(m_Action, SIGNAL(triggered()), this, SLOT(CleanHeader()));
	ui.tableWidget_Header->addAction(m_Action);
	ui.tableWidget_Header->setContextMenuPolicy(Qt::ActionsContextMenu);

	m_Action = new QAction(QString::fromLocal8Bit("���"));
	connect(m_Action, SIGNAL(triggered()), this, SLOT(AddValues()));
	ui.tableWidget_values->addAction(m_Action);
	m_Action = new QAction(QString::fromLocal8Bit("�������"));
	connect(m_Action, SIGNAL(triggered()), this, SLOT(AddSValues()));
	ui.tableWidget_values->addAction(m_Action);
	m_Action = new QAction(QString::fromLocal8Bit("ɾ��"));
	connect(m_Action, SIGNAL(triggered()), this, SLOT(DelValues()));
	ui.tableWidget_values->addAction(m_Action);
	m_Action = new QAction(QString::fromLocal8Bit("���"));
	connect(m_Action, SIGNAL(triggered()), this, SLOT(CleanValues()));

	ui.tableWidget_values->addAction(m_Action);
	ui.tableWidget_values->setContextMenuPolicy(Qt::ActionsContextMenu);

	m_Action = new QAction(QString::fromLocal8Bit("���"));
	connect(m_Action, SIGNAL(triggered()), this, SLOT(CleanResponse()));
	ui.textBrowser_Response->addAction(m_Action);
	ui.textBrowser_Response->setContextMenuPolicy(Qt::ActionsContextMenu);

	m_Action = new QAction(QString::fromLocal8Bit("���"));
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
	QString FilePath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("ѡ���ļ�"), "/", "*.txt");
}

void RequestTestTool::AddSValues()
{
	CleanValues();
	QString FilePath = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("ѡ���ļ�"), "/", "*.txt");
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
		HttpRequestHeader.clear();
		HttpRequestHeader.str("");

		HttpRequestData.clear();
		HttpRequestData.str(""); 
		
		RequestData.clear();
		RequestData.str("");

		Response.clear();
		Response.str("");

		ui.textBrowser_Response->clear();
		ui.lcdNumber_Recv->display(0);
		ui.lcdNumber_Send->display(0);
		HttpGetRequestDataIni();
		
	}
	if (ui.comboBox_RequestType->currentIndex() == 3) {
		HttpRequestHeader.clear();
		HttpRequestHeader.str("");

		HttpRequestData.clear();
		HttpRequestData.str("");

		RequestData.clear();
		RequestData.str("");

		Response.clear();
		Response.str("");

		ui.textBrowser_Response->clear();
		ui.lcdNumber_Recv->display(0);
		ui.lcdNumber_Send->display(0);
		HttpPostRequestDataIni();
		
	}
	//ui.pushButton_Connect->setEnabled(false);
	//ui.pushButton_Request->setEnabled(false);
	//ui.comboBox_RequestType->setEnabled(false);

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
		//�߳̿�ʼ
		ui.pushButton_Request->setEnabled(false);
		break;
	case THREAD_CONNECT_TIMEOUT:
		//���ӳ�ʱ
		disconnect(m_NetWorkThread, SIGNAL(ThreadSignals(unsigned int, unsigned int)), this, SLOT(ThreadSignal(unsigned int, unsigned int)));
		delete m_NetWorkThread;
		m_NetWorkThread = NULL;
		ui.comboBox_RequestType->setEnabled(true);
		ui.pushButton_Connect->setText(QString::fromLocal8Bit("����"));
		ui.pushButton_Connect->setEnabled(true);
		ui.pushButton_Request->setText(QString::fromLocal8Bit("����"));
		ui.pushButton_Request->setEnabled(true);
		ui.textBrowser_Response->clear();
		ui.textBrowser_Response->setText(QString::fromLocal8Bit("���ӳ�ʱ"));
		break;
	case THREAD_CONNECT_SUCCESS:
		//���ӳɹ�
		ui.pushButton_Connect->setText(QString::fromLocal8Bit("�Ͽ�"));
		ui.pushButton_Request->setText(QString::fromLocal8Bit("��ֹ"));
		break;
	case THREAD_SEND_SUCCESS_COUNT:
		//�������ݼ���
		ui.lcdNumber_Send->display(m_int);
		break;
	case THREAD_SEND_SUCCESS:
		//�������
		ui.textBrowser_Request->clear();
		ui.textBrowser_Request->setText(RequestData.str().c_str());
		break;
	case THREAD_RECV_TIMEOUT:
		//��ȡ��ʱ
		disconnect(m_NetWorkThread, SIGNAL(ThreadSignals(unsigned int, unsigned int)), this, SLOT(ThreadSignal(unsigned int, unsigned int)));
		//delete m_NetWorkThread;
		//m_NetWorkThread = NULL;
		ui.comboBox_RequestType->setEnabled(true);
		ui.pushButton_Connect->setText(QString::fromLocal8Bit("����"));
		ui.pushButton_Connect->setEnabled(true);
		ui.pushButton_Request->setText(QString::fromLocal8Bit("����"));
		ui.pushButton_Request->setEnabled(true);
		ui.textBrowser_Response->clear();
		ui.textBrowser_Response->setText(QString::fromLocal8Bit("��ȡ��ʱ"));

		break;
	case THREAD_RECV_SUCCESS_COUNT:
		//��ȡ����
		ui.lcdNumber_Recv->display(m_int);
		break;
	case THREAD_RECV_SUCCESS:
		//��ȡ���
		ui.textBrowser_Response->clear();
		ui.textBrowser_Response->setText(Response.str().c_str());
		break;
	case THREAD_CONNECTED:
		//���ӶϿ�
		disconnect(m_NetWorkThread, SIGNAL(ThreadSignals(unsigned int, unsigned int)), this, SLOT(ThreadSignal(unsigned int, unsigned int)));
		//delete m_NetWorkThread;
		//m_NetWorkThread = NULL;
		ui.comboBox_RequestType->setEnabled(true);
		ui.pushButton_Connect->setText(QString::fromLocal8Bit("����"));
		ui.pushButton_Connect->setEnabled(true);
		ui.pushButton_Request->setText(QString::fromLocal8Bit("����"));
		ui.pushButton_Request->setEnabled(true);
		ui.textBrowser_Response->clear();
		ui.textBrowser_Response->setText(QString::fromLocal8Bit("���ӶϿ�"));
		break;
	case THREAD_END:
		//�߳̽���
		disconnect(m_NetWorkThread, SIGNAL(ThreadSignals(unsigned int, unsigned int)), this, SLOT(ThreadSignal(unsigned int, unsigned int)));
		//delete m_NetWorkThread;
		//m_NetWorkThread = NULL;
		ui.comboBox_RequestType->setEnabled(true);
		ui.pushButton_Connect->setText(QString::fromLocal8Bit("����"));
		ui.pushButton_Connect->setEnabled(true);
		ui.pushButton_Request->setText(QString::fromLocal8Bit("����"));
		ui.pushButton_Request->setEnabled(true);
		ui.textBrowser_Response->setText(QString::fromStdString(Response.str()));
		break;
	default:
		break;
	}
}

int RequestTestTool::HttpPostRequestDataIni()
{
	HttpRequestHeader.str("");
	HttpRequestHeader << "POST " << Path;
	HttpRequestHeader << " HTTP/1.1\r\n";
	HttpRequestHeader << "Host: " << Host;

	HttpRequestData.str("");
	HttpRequestData.clear();
	//����POST����
	for (int i = 0; i < ui.tableWidget_values->rowCount(); i++) {

		if (!ui.tableWidget_values->item(i, 0)->text().length() || !ui.tableWidget_values->item(i, 1)->text().length()) {
			continue;
		}

		HttpRequestData << ui.tableWidget_values->item(i, 0)->text().toStdString() << "="
				    << ui.tableWidget_values->item(i, 1)->text().toStdString();

		if (i + 1 < ui.tableWidget_values->rowCount()) {
			HttpRequestData << "&";
		}
	}

	HttpRequestHeader << "\n";
	//���Header����
	for (int i = 0; i < ui.tableWidget_Header->rowCount(); i++) {
		HttpRequestHeader << ui.tableWidget_Header->item(i, 0)->text().toStdString() << ": "
					  << ui.tableWidget_Header->item(i, 1)->text().toStdString() << "\r\n";
	}

	//HttpRequestHeader << "Content-Length:" << HttpRequestData.str().length();
	HttpRequestHeader << "\r\n";

	RequestData << HttpRequestHeader.str() << HttpRequestData.str();
	ui.textBrowser_Request->clear();

	m_NetWorkThread = new NetWorkThread(Host, 80, false, RequestData, Response);
	connect(m_NetWorkThread, SIGNAL(ThreadSignals(unsigned int, unsigned int)), this, SLOT(ThreadSignalProcess(unsigned int, unsigned int)));
	m_NetWorkThread->start();
	return 0;
}

int RequestTestTool::HttpGetRequestDataIni()
{
	HttpRequestHeader.clear();
	HttpRequestHeader.str("");
	HttpRequestHeader << "GET " << Path;

	if (ui.tableWidget_values->rowCount() > 0 ) {
		HttpRequestHeader << "?";
	}

	for (int i = 0; i < ui.tableWidget_values->rowCount(); i++) {
		
		if (!ui.tableWidget_values->item(i, 0)->text().length() || !ui.tableWidget_values->item(i, 1)->text().length()) {
			continue;
		}

		HttpRequestHeader << ui.tableWidget_values->item(i, 0)->text().toStdString() << "="
			   << ui.tableWidget_values->item(i, 1)->text().toStdString();
		
		if (i + 1 < ui.tableWidget_values->rowCount()) {
			HttpRequestHeader << "&";
		}
	}

	HttpRequestHeader << " HTTP/1.1\r\n";
	HttpRequestHeader << "Host: " << Host;

	HttpRequestHeader << "\n";

	for (int i = 0; i < ui.tableWidget_Header->rowCount(); i++) {
		HttpRequestHeader << ui.tableWidget_Header->item(i, 0)->text().toStdString() << ": "
			   << ui.tableWidget_Header->item(i, 1)->text().toStdString() << "\r\n";
	}
	HttpRequestHeader << "\r\n\r\n";

	RequestData.clear();
	RequestData.str("");
	RequestData << HttpRequestHeader.str();
	ui.textBrowser_Request->clear();
	
	m_NetWorkThread = new NetWorkThread(Host, 80, false, RequestData, Response);
	connect(m_NetWorkThread, SIGNAL(ThreadSignals(unsigned int, unsigned int)), this, SLOT(ThreadSignalProcess(unsigned int, unsigned int)));
	m_NetWorkThread->start();
	return 0;
}

int RequestTestTool::HttpSPostRequesDataInit()
{
	HttpRequestHeader.clear();
	HttpRequestHeader.str("");
	HttpRequestHeader << "POST " << Path;
	HttpRequestHeader << " HTTP/1.1\r\n";
	HttpRequestHeader << "Host: " << Host;

	RequestData.str("");
	RequestData.clear();
	//����POST����
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

	HttpRequestHeader << "\n";
	//���Header����
	for (int i = 0; i < ui.tableWidget_Header->rowCount(); i++) {
		HttpRequestHeader << ui.tableWidget_Header->item(i, 0)->text().toStdString() << ": "
			<< ui.tableWidget_Header->item(i, 1)->text().toStdString() << "\r\n";
	}

	HttpRequestHeader << "Content-Length:" << RequestData.str().length();
	HttpRequestHeader << "\r\n";

	RequestData << HttpRequestHeader.str() << HttpRequestData.str();
	m_NetWorkThread = new NetWorkThread(Host, 80, true, RequestData, Response);
	connect(m_NetWorkThread, SIGNAL(ThreadSignals(unsigned int, unsigned int)), this, SLOT(ThreadSignal(unsigned int, unsigned int)));
	m_NetWorkThread->start();
	return 0;
}

int RequestTestTool::HttpSGetRequestDataIni()
{
	HttpRequestHeader.clear();
	HttpRequestHeader.str("");
	HttpRequestHeader << "GET " << Path;

	if (ui.tableWidget_values->rowCount() > 0) {
		HttpRequestHeader << "?";
	}

	for (int i = 0; i < ui.tableWidget_values->rowCount(); i++) {

		if (!ui.tableWidget_values->item(i, 0)->text().length() || !ui.tableWidget_values->item(i, 1)->text().length()) {
			continue;
		}

		HttpRequestHeader << ui.tableWidget_values->item(i, 0)->text().toStdString() << "="
			<< ui.tableWidget_values->item(i, 1)->text().toStdString();

		if (i + 1 < ui.tableWidget_values->rowCount()) {
			HttpRequestHeader << "&";
		}
	}

	HttpRequestHeader << "\n";

	for (int i = 0; i < ui.tableWidget_Header->rowCount(); i++) {
		HttpRequestHeader << ui.tableWidget_Header->item(i, 0)->text().toStdString() << ": "
			<< ui.tableWidget_Header->item(i, 1)->text().toStdString() << "\r\n";
	}
	HttpRequestHeader << "\r\n\r\n";

	RequestData << HttpRequestHeader.str();
	m_NetWorkThread = new NetWorkThread(Host, 80, true, RequestData, Response);
	connect(m_NetWorkThread, SIGNAL(ThreadSignals(unsigned int, unsigned int)), this, SLOT(ThreadSignal(unsigned int, unsigned int)));
	m_NetWorkThread->start();
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

NetWorkThread::~NetWorkThread()
{
	
}

void NetWorkThread::SetTimeOut(unsigned int UtimeOut)
{
	TimeOut = UtimeOut * 100;
}

void NetWorkThread::run()
{

	emit ThreadSignals(THREAD_START,0);
	QTcpSocket m_socket;
	connect(&m_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(Myerror(QAbstractSocket::SocketError)),Qt::DirectConnection);
	connect(&m_socket, SIGNAL(disconnected()), this, SLOT(Disconnect()), Qt::DirectConnection);
	int RequestDataLenth = RequestData.str().length();
	int  SentSuccessfully = 0;
	int  RecvDataCount = 1;
	const char *m_RequestData = RequestData.str().c_str();
	std::string vb = RequestData.str();
	m_socket.connectToHost(Host.c_str(), Port);
	if (!m_socket.waitForConnected(TimeOut)) {
		emit ThreadSignals(THREAD_CONNECT_TIMEOUT, 0); //���ӳ�ʱ
		return;
	}
	emit ThreadSignals(THREAD_CONNECT_SUCCESS, 0);
	while (RequestDataLenth - SentSuccessfully > 0 )
	{
		SentSuccessfully = m_socket.write(m_RequestData + SentSuccessfully, RequestDataLenth - SentSuccessfully);
		emit ThreadSignals(THREAD_SEND_SUCCESS_COUNT, SentSuccessfully); //���ͼ���
	}

	emit ThreadSignals(THREAD_SEND_SUCCESS, SentSuccessfully); //�������

	/*if (m_socket.waitForReadyRead(TimeOut)) {
		m_socket.disconnect();
		emit ThreadSignals(THREAD_SEND_TIMEOUT, 0);
		return;
	}*/
	QByteArray ResponseData;
	QByteArray ResponseData_Tmp;
	Response.clear();
	Response.str("");
	ResponseData.clear();
	ResponseData_Tmp.clear();
	if (!m_socket.waitForReadyRead(TimeOut)) {
		emit ThreadSignals(THREAD_RECV_TIMEOUT, 0); //���ռ���
		return;
	}
	while (RecvDataCount) {
		ResponseData_Tmp.clear();
		ResponseData_Tmp = m_socket.readAll();
		RecvDataCount = ResponseData_Tmp.size();
		ResponseData.append(ResponseData_Tmp);
		emit ThreadSignals(THREAD_RECV_SUCCESS_COUNT, ResponseData.size()); //���ռ���
	}
	Response << ResponseData.toStdString();
	emit ThreadSignals(THREAD_RECV_SUCCESS, 0);
	m_socket.disconnect();
	emit ThreadSignals(THREAD_END,0);
	return;
}

void NetWorkThread::Disconnect()
{
	int a = 0;
}

void NetWorkThread::Myerror(QAbstractSocket::SocketError socketError)
{
	int a = socketError;
}
