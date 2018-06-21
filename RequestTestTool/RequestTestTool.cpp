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
	connect(m_Action, SIGNAL(triggered()), this, SLOT(CleanReturn()));
	ui.textBrowser_return->addAction(m_Action);
	ui.textBrowser_return->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void RequestTestTool::RequestTypeClick(int index)
{
	//Socket
	if (index == 0) {
		ui.tableWidget_Header->setVisible(false);
		ui.tableWidget_values->setHorizontalHeaderLabels(m_StringList_Socket);
		ui.pushButton_Connect->setVisible(true);
		return;
	}
	//Socket-SSL
	if (index == 1) {
		ui.tableWidget_Header->setVisible(false);
		ui.tableWidget_values->setHorizontalHeaderLabels(m_StringList_Socket);
		ui.pushButton_Connect->setVisible(true);
		return;
	}
	//Http-Get
	if (index == 2) {
		ui.tableWidget_Header->setVisible(true);
		ui.tableWidget_values->setHorizontalHeaderLabels(m_StringList_Values);
		ui.pushButton_Connect->setVisible(false);
		return;
	}
	//Http-Post
	if (index == 3) {
		ui.tableWidget_Header->setVisible(true);
		ui.tableWidget_values->setHorizontalHeaderLabels(m_StringList_Values);
		ui.pushButton_Connect->setVisible(false);
		return;
	}
	//Https-Get
	if (index == 4) {
		ui.tableWidget_Header->setVisible(true);
		ui.tableWidget_values->setHorizontalHeaderLabels(m_StringList_Values);
		ui.pushButton_Connect->setVisible(false);
		return;
	}
	//Https-Post
	if (index == 5) {
		ui.tableWidget_Header->setVisible(true);
		ui.tableWidget_values->setHorizontalHeaderLabels(m_StringList_Values);
		ui.pushButton_Connect->setVisible(false);
		return;
	}
}

void RequestTestTool::CleanReturn()
{
	ui.textBrowser_return->clear();
}

void RequestTestTool::CleanHeader()
{
	ui.tableWidget_Header->clear();
	ui.tableWidget_Header->setRowCount(0);
	ui.tableWidget_Header->setHorizontalHeaderLabels(m_StringList_Header);
}

void RequestTestTool::CleanValues()
{
	ui.tableWidget_values->clear();
	ui.tableWidget_values->setRowCount(0);
	ui.tableWidget_values->setHorizontalHeaderLabels(m_StringList_Values);
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
