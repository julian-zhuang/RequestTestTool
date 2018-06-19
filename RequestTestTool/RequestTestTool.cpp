#include "RequestTestTool.h"

RequestTestTool::RequestTestTool(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选择
	ui.tableWidget->verticalHeader()->setVisible(false);   //隐藏列表头 
	ui.tableWidget->horizontalHeader()->setStretchLastSection(true);//关键  
	//ui.splitter->setStretchFactor(1, 1);
}
