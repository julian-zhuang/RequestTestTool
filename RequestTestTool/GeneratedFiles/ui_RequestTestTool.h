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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QComboBox *comboBox_RequestType;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_About;
    QHBoxLayout *horizontalLayout_6;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox_DataType;
    QLabel *label_key;
    QLineEdit *lineEdit_Key;
    QLabel *label_Value;
    QLineEdit *lineEdit_Value;
    QPushButton *pushButton_ADDS;
    QPushButton *pushButton_3;
    QTableWidget *tableWidget_values;
    QHBoxLayout *horizontalLayout;
    QLabel *label_SendDatalenth;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_LeftDel;
    QPushButton *pushButton_LeftClean;
    QWidget *widget_3;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_Address;
    QLineEdit *lineEdit_Address;
    QPushButton *pushButton_Connect_2;
    QPushButton *pushButton_Connect;
    QTextBrowser *textBrowser_return;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_ConnectStatus;
    QLabel *label_RecvDatalenth;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_8;
    QPushButton *pushButton_RightClean;

    void setupUi(QMainWindow *RequestTestToolClass)
    {
        if (RequestTestToolClass->objectName().isEmpty())
            RequestTestToolClass->setObjectName(QStringLiteral("RequestTestToolClass"));
        RequestTestToolClass->resize(1200, 730);
        RequestTestToolClass->setMinimumSize(QSize(1200, 730));
        centralWidget = new QWidget(RequestTestToolClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        comboBox_RequestType = new QComboBox(widget);
        comboBox_RequestType->setObjectName(QStringLiteral("comboBox_RequestType"));
        comboBox_RequestType->setMinimumSize(QSize(100, 30));
        comboBox_RequestType->setMaximumSize(QSize(100, 30));

        horizontalLayout_5->addWidget(comboBox_RequestType);

        horizontalSpacer = new QSpacerItem(897, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        pushButton_About = new QPushButton(widget);
        pushButton_About->setObjectName(QStringLiteral("pushButton_About"));
        pushButton_About->setMinimumSize(QSize(60, 30));
        pushButton_About->setMaximumSize(QSize(60, 30));

        horizontalLayout_5->addWidget(pushButton_About);


        verticalLayout_3->addWidget(widget);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(600, 600));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, 5, -1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        comboBox_DataType = new QComboBox(widget_2);
        comboBox_DataType->setObjectName(QStringLiteral("comboBox_DataType"));
        comboBox_DataType->setMinimumSize(QSize(100, 30));
        comboBox_DataType->setMaximumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(comboBox_DataType);

        label_key = new QLabel(widget_2);
        label_key->setObjectName(QStringLiteral("label_key"));

        horizontalLayout_2->addWidget(label_key);

        lineEdit_Key = new QLineEdit(widget_2);
        lineEdit_Key->setObjectName(QStringLiteral("lineEdit_Key"));
        lineEdit_Key->setMinimumSize(QSize(50, 30));
        lineEdit_Key->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_2->addWidget(lineEdit_Key);

        label_Value = new QLabel(widget_2);
        label_Value->setObjectName(QStringLiteral("label_Value"));

        horizontalLayout_2->addWidget(label_Value);

        lineEdit_Value = new QLineEdit(widget_2);
        lineEdit_Value->setObjectName(QStringLiteral("lineEdit_Value"));
        lineEdit_Value->setMinimumSize(QSize(50, 30));
        lineEdit_Value->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_2->addWidget(lineEdit_Value);

        pushButton_ADDS = new QPushButton(widget_2);
        pushButton_ADDS->setObjectName(QStringLiteral("pushButton_ADDS"));
        pushButton_ADDS->setMinimumSize(QSize(60, 30));
        pushButton_ADDS->setMaximumSize(QSize(60, 30));

        horizontalLayout_2->addWidget(pushButton_ADDS);

        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(60, 30));
        pushButton_3->setMaximumSize(QSize(60, 30));

        horizontalLayout_2->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_2);

        tableWidget_values = new QTableWidget(widget_2);
        if (tableWidget_values->columnCount() < 2)
            tableWidget_values->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_values->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_values->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget_values->rowCount() < 2)
            tableWidget_values->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_values->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_values->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_values->setItem(0, 0, __qtablewidgetitem4);
        tableWidget_values->setObjectName(QStringLiteral("tableWidget_values"));

        verticalLayout->addWidget(tableWidget_values);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_SendDatalenth = new QLabel(widget_2);
        label_SendDatalenth->setObjectName(QStringLiteral("label_SendDatalenth"));
        label_SendDatalenth->setMinimumSize(QSize(0, 30));
        label_SendDatalenth->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(label_SendDatalenth);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        pushButton_LeftDel = new QPushButton(widget_2);
        pushButton_LeftDel->setObjectName(QStringLiteral("pushButton_LeftDel"));
        pushButton_LeftDel->setMinimumSize(QSize(60, 30));
        pushButton_LeftDel->setMaximumSize(QSize(60, 30));

        horizontalLayout->addWidget(pushButton_LeftDel);

        pushButton_LeftClean = new QPushButton(widget_2);
        pushButton_LeftClean->setObjectName(QStringLiteral("pushButton_LeftClean"));
        pushButton_LeftClean->setMinimumSize(QSize(60, 30));
        pushButton_LeftClean->setMaximumSize(QSize(60, 30));

        horizontalLayout->addWidget(pushButton_LeftClean);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        horizontalLayout_6->addWidget(widget_2);

        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(600, 600));
        gridLayout_2 = new QGridLayout(widget_3);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, -1, -1, -1);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 0);
        label_Address = new QLabel(widget_3);
        label_Address->setObjectName(QStringLiteral("label_Address"));

        horizontalLayout_3->addWidget(label_Address);

        lineEdit_Address = new QLineEdit(widget_3);
        lineEdit_Address->setObjectName(QStringLiteral("lineEdit_Address"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit_Address->sizePolicy().hasHeightForWidth());
        lineEdit_Address->setSizePolicy(sizePolicy);
        lineEdit_Address->setMinimumSize(QSize(280, 30));
        lineEdit_Address->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_3->addWidget(lineEdit_Address);

        pushButton_Connect_2 = new QPushButton(widget_3);
        pushButton_Connect_2->setObjectName(QStringLiteral("pushButton_Connect_2"));
        pushButton_Connect_2->setMinimumSize(QSize(60, 30));
        pushButton_Connect_2->setMaximumSize(QSize(60, 30));

        horizontalLayout_3->addWidget(pushButton_Connect_2);

        pushButton_Connect = new QPushButton(widget_3);
        pushButton_Connect->setObjectName(QStringLiteral("pushButton_Connect"));
        pushButton_Connect->setMinimumSize(QSize(60, 30));
        pushButton_Connect->setMaximumSize(QSize(60, 30));

        horizontalLayout_3->addWidget(pushButton_Connect);


        verticalLayout_2->addLayout(horizontalLayout_3);

        textBrowser_return = new QTextBrowser(widget_3);
        textBrowser_return->setObjectName(QStringLiteral("textBrowser_return"));

        verticalLayout_2->addWidget(textBrowser_return);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_ConnectStatus = new QPushButton(widget_3);
        pushButton_ConnectStatus->setObjectName(QStringLiteral("pushButton_ConnectStatus"));
        pushButton_ConnectStatus->setMinimumSize(QSize(30, 30));
        pushButton_ConnectStatus->setMaximumSize(QSize(30, 30));

        horizontalLayout_4->addWidget(pushButton_ConnectStatus);

        label_RecvDatalenth = new QLabel(widget_3);
        label_RecvDatalenth->setObjectName(QStringLiteral("label_RecvDatalenth"));
        label_RecvDatalenth->setMinimumSize(QSize(0, 30));
        label_RecvDatalenth->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_4->addWidget(label_RecvDatalenth);

        horizontalSpacer_5 = new QSpacerItem(216, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        pushButton_8 = new QPushButton(widget_3);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(60, 30));
        pushButton_8->setMaximumSize(QSize(60, 30));

        horizontalLayout_4->addWidget(pushButton_8);

        pushButton_RightClean = new QPushButton(widget_3);
        pushButton_RightClean->setObjectName(QStringLiteral("pushButton_RightClean"));
        pushButton_RightClean->setMinimumSize(QSize(60, 30));
        pushButton_RightClean->setMaximumSize(QSize(60, 30));

        horizontalLayout_4->addWidget(pushButton_RightClean);


        verticalLayout_2->addLayout(horizontalLayout_4);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        horizontalLayout_6->addWidget(widget_3);


        verticalLayout_3->addLayout(horizontalLayout_6);

        RequestTestToolClass->setCentralWidget(centralWidget);

        retranslateUi(RequestTestToolClass);

        QMetaObject::connectSlotsByName(RequestTestToolClass);
    } // setupUi

    void retranslateUi(QMainWindow *RequestTestToolClass)
    {
        RequestTestToolClass->setWindowTitle(QApplication::translate("RequestTestToolClass", "RequestTestTool", Q_NULLPTR));
        comboBox_RequestType->clear();
        comboBox_RequestType->insertItems(0, QStringList()
         << QApplication::translate("RequestTestToolClass", "Socket", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "Socket-SSL", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "Http-Get", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "Http-Post", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "Https-Get", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "Https-Post", Q_NULLPTR)
        );
        pushButton_About->setText(QApplication::translate("RequestTestToolClass", "\345\205\263\344\272\216", Q_NULLPTR));
        comboBox_DataType->clear();
        comboBox_DataType->insertItems(0, QStringList()
         << QApplication::translate("RequestTestToolClass", "Int", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "File", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "Char", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "String", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "Bit", Q_NULLPTR)
        );
        label_key->setText(QApplication::translate("RequestTestToolClass", "Key", Q_NULLPTR));
        label_Value->setText(QApplication::translate("RequestTestToolClass", "Value", Q_NULLPTR));
        pushButton_ADDS->setText(QApplication::translate("RequestTestToolClass", "\346\211\271\351\207\217\346\267\273\345\212\240", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("RequestTestToolClass", "\346\267\273\345\212\240", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_values->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("RequestTestToolClass", "Data Type", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_values->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("RequestTestToolClass", "Value", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_values->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("RequestTestToolClass", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_values->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("RequestTestToolClass", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));

        const bool __sortingEnabled = tableWidget_values->isSortingEnabled();
        tableWidget_values->setSortingEnabled(false);
        tableWidget_values->setSortingEnabled(__sortingEnabled);

        label_SendDatalenth->setText(QApplication::translate("RequestTestToolClass", "total:  23 Byte", Q_NULLPTR));
        pushButton_LeftDel->setText(QApplication::translate("RequestTestToolClass", "\345\210\240\351\231\244", Q_NULLPTR));
        pushButton_LeftClean->setText(QApplication::translate("RequestTestToolClass", "\346\270\205\347\251\272", Q_NULLPTR));
        label_Address->setText(QApplication::translate("RequestTestToolClass", "Address", Q_NULLPTR));
        lineEdit_Address->setText(QString());
        pushButton_Connect_2->setText(QApplication::translate("RequestTestToolClass", "\345\217\221\351\200\201", Q_NULLPTR));
        pushButton_Connect->setText(QApplication::translate("RequestTestToolClass", "\350\277\236\346\216\245", Q_NULLPTR));
        textBrowser_return->setHtml(QApplication::translate("RequestTestToolClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">21332313</p></body></html>", Q_NULLPTR));
        pushButton_ConnectStatus->setText(QString());
        label_RecvDatalenth->setText(QApplication::translate("RequestTestToolClass", "Recv: 23 Byte", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("RequestTestToolClass", "ASCII", Q_NULLPTR));
        pushButton_RightClean->setText(QApplication::translate("RequestTestToolClass", "\346\270\205\347\251\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RequestTestToolClass: public Ui_RequestTestToolClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REQUESTTESTTOOL_H
