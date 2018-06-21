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
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RequestTestToolClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget_Header;
    QTableWidget *tableWidget_values;
    QTextBrowser *textBrowser_return;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_RequestType;
    QPushButton *pushButton_Connect;
    QLineEdit *lineEdit_Address;
    QPushButton *pushButton_Request;
    QLabel *label_RecvDatalenth;
    QLCDNumber *lcdNumber_2;
    QLabel *label_SendDatalenth;
    QLCDNumber *lcdNumber;
    QComboBox *comboBox_ShowType;

    void setupUi(QMainWindow *RequestTestToolClass)
    {
        if (RequestTestToolClass->objectName().isEmpty())
            RequestTestToolClass->setObjectName(QStringLiteral("RequestTestToolClass"));
        RequestTestToolClass->resize(1200, 727);
        RequestTestToolClass->setMinimumSize(QSize(1200, 700));
        RequestTestToolClass->setMaximumSize(QSize(16777215, 16777215));
        centralWidget = new QWidget(RequestTestToolClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tableWidget_Header = new QTableWidget(centralWidget);
        tableWidget_Header->setObjectName(QStringLiteral("tableWidget_Header"));
        tableWidget_Header->setMinimumSize(QSize(600, 300));

        verticalLayout->addWidget(tableWidget_Header);

        tableWidget_values = new QTableWidget(centralWidget);
        tableWidget_values->setObjectName(QStringLiteral("tableWidget_values"));
        tableWidget_values->setMinimumSize(QSize(600, 300));

        verticalLayout->addWidget(tableWidget_values);


        horizontalLayout_2->addLayout(verticalLayout);

        textBrowser_return = new QTextBrowser(centralWidget);
        textBrowser_return->setObjectName(QStringLiteral("textBrowser_return"));
        textBrowser_return->setMinimumSize(QSize(600, 605));

        horizontalLayout_2->addWidget(textBrowser_return);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
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

        label_RecvDatalenth = new QLabel(centralWidget);
        label_RecvDatalenth->setObjectName(QStringLiteral("label_RecvDatalenth"));
        label_RecvDatalenth->setMinimumSize(QSize(0, 30));
        label_RecvDatalenth->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(label_RecvDatalenth);

        lcdNumber_2 = new QLCDNumber(centralWidget);
        lcdNumber_2->setObjectName(QStringLiteral("lcdNumber_2"));

        horizontalLayout->addWidget(lcdNumber_2);

        label_SendDatalenth = new QLabel(centralWidget);
        label_SendDatalenth->setObjectName(QStringLiteral("label_SendDatalenth"));
        label_SendDatalenth->setMinimumSize(QSize(0, 30));
        label_SendDatalenth->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(label_SendDatalenth);

        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));

        horizontalLayout->addWidget(lcdNumber);

        comboBox_ShowType = new QComboBox(centralWidget);
        comboBox_ShowType->setObjectName(QStringLiteral("comboBox_ShowType"));
        comboBox_ShowType->setMinimumSize(QSize(60, 30));

        horizontalLayout->addWidget(comboBox_ShowType);


        verticalLayout_2->addLayout(horizontalLayout);

        RequestTestToolClass->setCentralWidget(centralWidget);

        retranslateUi(RequestTestToolClass);

        QMetaObject::connectSlotsByName(RequestTestToolClass);
    } // setupUi

    void retranslateUi(QMainWindow *RequestTestToolClass)
    {
        RequestTestToolClass->setWindowTitle(QApplication::translate("RequestTestToolClass", "RequestTestTool", Q_NULLPTR));
        textBrowser_return->setHtml(QApplication::translate("RequestTestToolClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
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
        lineEdit_Address->setText(QString());
        pushButton_Request->setText(QApplication::translate("RequestTestToolClass", "\345\217\221\351\200\201", Q_NULLPTR));
        label_RecvDatalenth->setText(QApplication::translate("RequestTestToolClass", " \346\216\245\346\224\266:", Q_NULLPTR));
        label_SendDatalenth->setText(QApplication::translate("RequestTestToolClass", "\345\217\221\351\200\201:", Q_NULLPTR));
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
