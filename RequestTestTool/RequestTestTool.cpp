#include "RequestTestTool.h"

RequestTestTool::RequestTestTool(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//����ѡ��
	ui.tableWidget->verticalHeader()->setVisible(false);   //�����б�ͷ 
	ui.tableWidget->horizontalHeader()->setStretchLastSection(true);//�ؼ�  
	//ui.splitter->setStretchFactor(1, 1);
}
