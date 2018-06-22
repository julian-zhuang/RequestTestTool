/********************************************************************************
** Form generated from reading UI file 'RequestTestTool.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REQUESTTESTTOOL_H
#define UI_REQUESTTESTTOOL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RequestTestToolClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget_Header;
    QTableWidget *tableWidget_values;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QTextBrowser *textBrowser_Request;
    QTextBrowser *textBrowser_Response;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_RequestType;
    QPushButton *pushButton_Connect;
    QLabel *label;
    QLineEdit *lineEdit_Address;
    QPushButton *pushButton_Request;
    QLabel *label_SendDatalenth;
    QLCDNumber *lcdNumber_Send;
    QLabel *label_RecvDatalenth;
    QLCDNumber *lcdNumber_Recv;
    QComboBox *comboBox_ShowType;

    void setupUi(QMainWindow *RequestTestToolClass)
    {
        if (RequestTestToolClass->objectName().isEmpty())
            RequestTestToolClass->setObjectName(QStringLiteral("RequestTestToolClass"));
        RequestTestToolClass->resize(1200, 700);
        RequestTestToolClass->setMinimumSize(QSize(1200, 700));
        RequestTestToolClass->setMaximumSize(QSize(16777215, 16777215));
        centralWidget = new QWidget(RequestTestToolClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(5);
        widget = new QWidget(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableWidget_Header = new QTableWidget(widget);
        tableWidget_Header->setObjectName(QStringLiteral("tableWidget_Header"));
        tableWidget_Header->setMinimumSize(QSize(300, 300));

        verticalLayout->addWidget(tableWidget_Header);

        tableWidget_values = new QTableWidget(widget);
        tableWidget_values->setObjectName(QStringLiteral("tableWidget_values"));
        tableWidget_values->setMinimumSize(QSize(300, 300));

        verticalLayout->addWidget(tableWidget_values);

        splitter->addWidget(widget);
        widget1 = new QWidget(splitter);
        widget1->setObjectName(QStringLiteral("widget1"));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        textBrowser_Request = new QTextBrowser(widget1);
        textBrowser_Request->setObjectName(QStringLiteral("textBrowser_Request"));
        textBrowser_Request->setMinimumSize(QSize(300, 0));

        verticalLayout_2->addWidget(textBrowser_Request);

        textBrowser_Response = new QTextBrowser(widget1);
        textBrowser_Response->setObjectName(QStringLiteral("textBrowser_Response"));
        textBrowser_Response->setMinimumSize(QSize(300, 0));

        verticalLayout_2->addWidget(textBrowser_Response);

        splitter->addWidget(widget1);

        verticalLayout_3->addWidget(splitter);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        comboBox_RequestType = new QComboBox(centralWidget);
        comboBox_RequestType->setObjectName(QStringLiteral("comboBox_RequestType"));
        comboBox_RequestType->setMinimumSize(QSize(100, 30));
        comboBox_RequestType->setMaximumSize(QSize(100, 30));

        horizontalLayout->addWidget(comboBox_RequestType);

        pushButton_Connect = new QPushButton(centralWidget);
        pushButton_Connect->setObjectName(QStringLiteral("pushButton_Connect"));
        pushButton_Connect->setMinimumSize(QSize(60, 30));
        pushButton_Connect->setMaximumSize(QSize(30, 30));

        horizontalLayout->addWidget(pushButton_Connect);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(label);

        lineEdit_Address = new QLineEdit(centralWidget);
        lineEdit_Address->setObjectName(QStringLiteral("lineEdit_Address"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineEdit_Address->sizePolicy().hasHeightForWidth());
        lineEdit_Address->setSizePolicy(sizePolicy1);
        lineEdit_Address->setMinimumSize(QSize(557, 30));
        lineEdit_Address->setMaximumSize(QSize(65535, 30));

        horizontalLayout->addWidget(lineEdit_Address);

        pushButton_Request = new QPushButton(centralWidget);
        pushButton_Request->setObjectName(QStringLiteral("pushButton_Request"));
        pushButton_Request->setMinimumSize(QSize(60, 30));
        pushButton_Request->setMaximumSize(QSize(60, 30));

        horizontalLayout->addWidget(pushButton_Request);

        label_SendDatalenth = new QLabel(centralWidget);
        label_SendDatalenth->setObjectName(QStringLiteral("label_SendDatalenth"));
        label_SendDatalenth->setMinimumSize(QSize(0, 30));
        label_SendDatalenth->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(label_SendDatalenth);

        lcdNumber_Send = new QLCDNumber(centralWidget);
        lcdNumber_Send->setObjectName(QStringLiteral("lcdNumber_Send"));
        lcdNumber_Send->setMaximumSize(QSize(16777215, 30));
        lcdNumber_Send->setDigitCount(5);

        horizontalLayout->addWidget(lcdNumber_Send);

        label_RecvDatalenth = new QLabel(centralWidget);
        label_RecvDatalenth->setObjectName(QStringLiteral("label_RecvDatalenth"));
        label_RecvDatalenth->setMinimumSize(QSize(0, 30));
        label_RecvDatalenth->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(label_RecvDatalenth);

        lcdNumber_Recv = new QLCDNumber(centralWidget);
        lcdNumber_Recv->setObjectName(QStringLiteral("lcdNumber_Recv"));
        lcdNumber_Recv->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(lcdNumber_Recv);

        comboBox_ShowType = new QComboBox(centralWidget);
        comboBox_ShowType->setObjectName(QStringLiteral("comboBox_ShowType"));
        comboBox_ShowType->setMinimumSize(QSize(60, 30));
        comboBox_ShowType->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(comboBox_ShowType);


        verticalLayout_3->addLayout(horizontalLayout);

        RequestTestToolClass->setCentralWidget(centralWidget);

        retranslateUi(RequestTestToolClass);

        QMetaObject::connectSlotsByName(RequestTestToolClass);
    } // setupUi

    void retranslateUi(QMainWindow *RequestTestToolClass)
    {
        RequestTestToolClass->setWindowTitle(QApplication::translate("RequestTestToolClass", "RequestTestTool", Q_NULLPTR));
        textBrowser_Request->setHtml(QApplication::translate("RequestTestToolClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\351\230\277\350\213\217\345\244\247\345\253\202\346\211\223\346\211\253\345\276\227</p></body></html>", Q_NULLPTR));
        textBrowser_Response->setHtml(QApplication::translate("RequestTestToolClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\351\230\277\350\213\217\345\244\247\345\253\202\346\211\223\346\211\253\345\276\227</p></body></html>", Q_NULLPTR));
        comboBox_RequestType->clear();
        comboBox_RequestType->insertItems(0, QStringList()
         << QApplication::translate("RequestTestToolClass", "Socket", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "Socket-SSL", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "Http-Get", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "Http-Post", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "Https-Get", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "Https-Post", Q_NULLPTR)
        );
        pushButton_Connect->setText(QApplication::translate("RequestTestToolClass", "\350\277\236\346\216\245", Q_NULLPTR));
        label->setText(QApplication::translate("RequestTestToolClass", "https://", Q_NULLPTR));
        lineEdit_Address->setText(QApplication::translate("RequestTestToolClass", "http://www.baidu.com", Q_NULLPTR));
        pushButton_Request->setText(QApplication::translate("RequestTestToolClass", "\345\217\221\351\200\201", Q_NULLPTR));
        label_SendDatalenth->setText(QApplication::translate("RequestTestToolClass", "\345\217\221\351\200\201:", Q_NULLPTR));
        label_RecvDatalenth->setText(QApplication::translate("RequestTestToolClass", " \346\216\245\346\224\266:", Q_NULLPTR));
        comboBox_ShowType->clear();
        comboBox_ShowType->insertItems(0, QStringList()
         << QApplication::translate("RequestTestToolClass", "ASCLL", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "16\350\277\233\345\210\266", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "10\350\277\233\345\210\266", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "2  \350\277\233\345\210\266", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class RequestTestToolClass: public Ui_RequestTestToolClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REQUESTTESTTOOL_H
