#include "RequestTestTool.h"

RequestTestTool::RequestTestTool(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.tableWidget_values->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选择
	ui.tableWidget_values->verticalHeader()->setVisible(false);   //隐藏列表头 
	ui.tableWidget_values->horizontalHeader()->setStretchLastSection(true);//关键  
	ui.tableWidget_values->horizontalHeader()->setVisible(false);
	ui.lineEdit_Key->setVisible(false);
	ui.label_key->setVisible(ui.lineEdit_Key->isVisible());
	
	connect(ui.pushButton_LeftClean, SIGNAL(clicked()), this, SLOT(CleanValueClick()));
	connect(ui.pushButton_RightClean, SIGNAL(clicked()), this, SLOT(CleanReturnClick()));
	connect(ui.comboBox_RequestType, SIGNAL(currentIndexChanged(int)), this, SLOT(RequestTypeClick(int)));
}

void RequestTestTool::CleanReturnClick()
{
	ui.textBrowser_return->clear();
}

void RequestTestTool::CleanValueClick()
{
	ui.tableWidget_values->clear();
	ui.tableWidget_values->setRowCount(0);
}

void RequestTestTool::RequestTypeClick(int index)
{
	//Socket
	if (index == 0) {
		ui.lineEdit_Key->setVisible(false);
		ui.label_key->setVisible(ui.lineEdit_Key->isVisible());
		ui.comboBox_DataType->setVisible(!ui.lineEdit_Key->isVisible());
	}
	//Socket-SSL
	if (index == 1) {
		ui.lineEdit_Key->setVisible(false);
		ui.label_key->setVisible(ui.lineEdit_Key->isVisible());
	}
	//Http-Get
	if (index == 2) {
		ui.lineEdit_Key->setVisible(true);
		ui.label_key->setVisible(ui.lineEdit_Key->isVisible());
		ui.comboBox_DataType->setVisible(!ui.lineEdit_Key->isVisible());
	}
	//Http-Post
	if (index == 3) {
		ui.lineEdit_Key->setVisible(true);
		ui.label_key->setVisible(ui.lineEdit_Key->isVisible());
		ui.comboBox_DataType->setVisible(!ui.lineEdit_Key->isVisible());
	}
	//Https-Get
	if (index == 4) {
		ui.lineEdit_Key->setVisible(true);
		ui.label_key->setVisible(ui.lineEdit_Key->isVisible());
		ui.comboBox_DataType->setVisible(!ui.lineEdit_Key->isVisible());
	}
	//Https-Post
	if (index == 5) {
		ui.lineEdit_Key->setVisible(true);
		ui.label_key->setVisible(ui.lineEdit_Key->isVisible());
		ui.comboBox_DataType->setVisible(!ui.lineEdit_Key->isVisible());
	}
}