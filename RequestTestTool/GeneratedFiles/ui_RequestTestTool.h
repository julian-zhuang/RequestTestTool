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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RequestTestToolClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget_Header;
    QTableWidget *tableWidget_values;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QComboBox *comboBox_ShowType_3;
    QTextBrowser *textBrowser_Request;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *comboBox_ShowType_2;
    QTextBrowser *textBrowser_Response;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_RequestType;
    QPushButton *pushButton_Connect;
    QLineEdit *lineEdit_Address;
    QPushButton *pushButton_Request;
    QLabel *label_SendDatalenth;
    QLCDNumber *lcdNumber_Send;
    QLabel *label_RecvDatalenth;
    QLCDNumber *lcdNumber_Recv;

    void setupUi(QMainWindow *RequestTestToolClass)
    {
        if (RequestTestToolClass->objectName().isEmpty())
            RequestTestToolClass->setObjectName(QStringLiteral("RequestTestToolClass"));
        RequestTestToolClass->resize(1200, 700);
        RequestTestToolClass->setMinimumSize(QSize(1200, 700));
        RequestTestToolClass->setMaximumSize(QSize(16777215, 16777215));
        centralWidget = new QWidget(RequestTestToolClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(2);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(2, 2, 2, 2);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget_Header = new QTableWidget(centralWidget);
        tableWidget_Header->setObjectName(QStringLiteral("tableWidget_Header"));
        tableWidget_Header->setMinimumSize(QSize(300, 300));

        verticalLayout->addWidget(tableWidget_Header);

        tableWidget_values = new QTableWidget(centralWidget);
        tableWidget_values->setObjectName(QStringLiteral("tableWidget_values"));
        tableWidget_values->setMinimumSize(QSize(300, 300));

        verticalLayout->addWidget(tableWidget_values);


        gridLayout->addLayout(verticalLayout, 0, 0, 2, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 25));
        label_2->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(label_2);

        comboBox_ShowType_3 = new QComboBox(centralWidget);
        comboBox_ShowType_3->setObjectName(QStringLiteral("comboBox_ShowType_3"));
        comboBox_ShowType_3->setMinimumSize(QSize(60, 30));
        comboBox_ShowType_3->setMaximumSize(QSize(60, 30));

        horizontalLayout_3->addWidget(comboBox_ShowType_3);


        verticalLayout_3->addLayout(horizontalLayout_3);

        textBrowser_Request = new QTextBrowser(centralWidget);
        textBrowser_Request->setObjectName(QStringLiteral("textBrowser_Request"));
        textBrowser_Request->setMinimumSize(QSize(300, 0));

        verticalLayout_3->addWidget(textBrowser_Request);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 25));
        label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(label);

        comboBox_ShowType_2 = new QComboBox(centralWidget);
        comboBox_ShowType_2->setObjectName(QStringLiteral("comboBox_ShowType_2"));
        comboBox_ShowType_2->setMinimumSize(QSize(60, 30));
        comboBox_ShowType_2->setMaximumSize(QSize(60, 30));

        horizontalLayout_2->addWidget(comboBox_ShowType_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        textBrowser_Response = new QTextBrowser(centralWidget);
        textBrowser_Response->setObjectName(QStringLiteral("textBrowser_Response"));
        textBrowser_Response->setEnabled(true);
        textBrowser_Response->setMinimumSize(QSize(300, 0));

        verticalLayout_2->addWidget(textBrowser_Response);


        gridLayout->addLayout(verticalLayout_2, 1, 1, 1, 1);

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

        lineEdit_Address = new QLineEdit(centralWidget);
        lineEdit_Address->setObjectName(QStringLiteral("lineEdit_Address"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_Address->sizePolicy().hasHeightForWidth());
        lineEdit_Address->setSizePolicy(sizePolicy);
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


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 2);

        RequestTestToolClass->setCentralWidget(centralWidget);

        retranslateUi(RequestTestToolClass);

        QMetaObject::connectSlotsByName(RequestTestToolClass);
    } // setupUi

    void retranslateUi(QMainWindow *RequestTestToolClass)
    {
        RequestTestToolClass->setWindowTitle(QApplication::translate("RequestTestToolClass", "RequestTestTool", Q_NULLPTR));
        label_2->setText(QApplication::translate("RequestTestToolClass", "\345\216\237\345\247\213\350\257\267\346\261\202\346\225\260\346\215\256", Q_NULLPTR));
        comboBox_ShowType_3->clear();
        comboBox_ShowType_3->insertItems(0, QStringList()
         << QApplication::translate("RequestTestToolClass", "ASCLL", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "16\350\277\233\345\210\266", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "10\350\277\233\345\210\266", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "2  \350\277\233\345\210\266", Q_NULLPTR)
        );
        textBrowser_Request->setHtml(QApplication::translate("RequestTestToolClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\351\230\277\350\213\217\345\244\247\345\253\202\346\211\223\346\211\253\345\276\227</p></body></html>", Q_NULLPTR));
        label->setText(QApplication::translate("RequestTestToolClass", "\345\216\237\345\247\213\345\223\215\345\272\224\346\225\260\346\215\256", Q_NULLPTR));
        comboBox_ShowType_2->clear();
        comboBox_ShowType_2->insertItems(0, QStringList()
         << QApplication::translate("RequestTestToolClass", "ASCLL", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "16\350\277\233\345\210\266", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "10\350\277\233\345\210\266", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "2  \350\277\233\345\210\266", Q_NULLPTR)
        );
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
        lineEdit_Address->setText(QApplication::translate("RequestTestToolClass", "http://coolaf.com/tool/params", Q_NULLPTR));
        pushButton_Request->setText(QApplication::translate("RequestTestToolClass", "\345\217\221\351\200\201", Q_NULLPTR));
        label_SendDatalenth->setText(QApplication::translate("RequestTestToolClass", "\345\217\221\351\200\201:", Q_NULLPTR));
        label_RecvDatalenth->setText(QApplication::translate("RequestTestToolClass", " \346\216\245\346\224\266:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RequestTestToolClass: public Ui_RequestTestToolClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REQUESTTESTTOOL_H
