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
#include <QtWidgets/QRadioButton>
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
    QComboBox *comboBox_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_11;
    QHBoxLayout *horizontalLayout_6;
    QWidget *widget_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QWidget *widget_3;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *pushButton_4;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_10;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;

    void setupUi(QMainWindow *RequestTestToolClass)
    {
        if (RequestTestToolClass->objectName().isEmpty())
            RequestTestToolClass->setObjectName(QStringLiteral("RequestTestToolClass"));
        RequestTestToolClass->resize(1060, 730);
        RequestTestToolClass->setMinimumSize(QSize(1060, 730));
        centralWidget = new QWidget(RequestTestToolClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        comboBox_3 = new QComboBox(widget);
        comboBox_3->setObjectName(QStringLiteral("comboBox_3"));
        comboBox_3->setMinimumSize(QSize(100, 30));
        comboBox_3->setMaximumSize(QSize(100, 30));

        horizontalLayout_5->addWidget(comboBox_3);

        horizontalSpacer = new QSpacerItem(897, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        pushButton_11 = new QPushButton(widget);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setMinimumSize(QSize(60, 30));
        pushButton_11->setMaximumSize(QSize(60, 30));

        horizontalLayout_5->addWidget(pushButton_11);


        verticalLayout_3->addWidget(widget);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(500, 0));
        gridLayout = new QGridLayout(widget_2);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        comboBox_2 = new QComboBox(widget_2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setMinimumSize(QSize(100, 30));
        comboBox_2->setMaximumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(comboBox_2);

        lineEdit_3 = new QLineEdit(widget_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setMinimumSize(QSize(100, 30));
        lineEdit_3->setMaximumSize(QSize(65535, 30));

        horizontalLayout_2->addWidget(lineEdit_3);

        lineEdit = new QLineEdit(widget_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(100, 30));
        lineEdit->setMaximumSize(QSize(65535, 30));

        horizontalLayout_2->addWidget(lineEdit);

        pushButton_2 = new QPushButton(widget_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(60, 30));
        pushButton_2->setMaximumSize(QSize(60, 30));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(widget_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(60, 30));
        pushButton_3->setMaximumSize(QSize(60, 30));

        horizontalLayout_2->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_2);

        tableWidget = new QTableWidget(widget_2);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidget->rowCount() < 2)
            tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem4);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(0, 30));
        label_5->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(label_5);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        pushButton_6 = new QPushButton(widget_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setMinimumSize(QSize(60, 30));
        pushButton_6->setMaximumSize(QSize(60, 30));

        horizontalLayout->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(widget_2);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setMinimumSize(QSize(60, 30));
        pushButton_7->setMaximumSize(QSize(60, 30));

        horizontalLayout->addWidget(pushButton_7);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        horizontalLayout_6->addWidget(widget_2);

        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setMinimumSize(QSize(500, 0));
        gridLayout_2 = new QGridLayout(widget_3);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lineEdit_2 = new QLineEdit(widget_3);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setMinimumSize(QSize(280, 30));
        lineEdit_2->setMaximumSize(QSize(65535, 30));

        horizontalLayout_3->addWidget(lineEdit_2);

        horizontalSpacer_3 = new QSpacerItem(37, 17, QSizePolicy::Ignored, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        radioButton = new QRadioButton(widget_3);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setMinimumSize(QSize(0, 30));

        horizontalLayout_3->addWidget(radioButton);

        radioButton_2 = new QRadioButton(widget_3);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setMinimumSize(QSize(0, 30));

        horizontalLayout_3->addWidget(radioButton_2);

        pushButton_4 = new QPushButton(widget_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setMinimumSize(QSize(60, 30));
        pushButton_4->setMaximumSize(QSize(60, 30));

        horizontalLayout_3->addWidget(pushButton_4);


        verticalLayout_2->addLayout(horizontalLayout_3);

        textBrowser = new QTextBrowser(widget_3);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        verticalLayout_2->addWidget(textBrowser);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_10 = new QPushButton(widget_3);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setMinimumSize(QSize(30, 30));
        pushButton_10->setMaximumSize(QSize(30, 30));

        horizontalLayout_4->addWidget(pushButton_10);

        label_7 = new QLabel(widget_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(0, 30));
        label_7->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_4->addWidget(label_7);

        horizontalSpacer_5 = new QSpacerItem(216, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        pushButton_8 = new QPushButton(widget_3);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setMinimumSize(QSize(60, 30));
        pushButton_8->setMaximumSize(QSize(60, 30));

        horizontalLayout_4->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(widget_3);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setMinimumSize(QSize(60, 30));
        pushButton_9->setMaximumSize(QSize(60, 30));

        horizontalLayout_4->addWidget(pushButton_9);


        verticalLayout_2->addLayout(horizontalLayout_4);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);


        horizontalLayout_6->addWidget(widget_3);


        verticalLayout_3->addLayout(horizontalLayout_6);

        RequestTestToolClass->setCentralWidget(centralWidget);
        widget->raise();
        pushButton_3->raise();
        lineEdit_3->raise();
        lineEdit->raise();
        comboBox_2->raise();
        pushButton_2->raise();
        tableWidget->raise();
        tableWidget->raise();
        label_5->raise();
        pushButton_7->raise();
        pushButton_6->raise();
        pushButton_4->raise();
        radioButton_2->raise();
        radioButton->raise();
        lineEdit_2->raise();
        textBrowser->raise();
        pushButton_9->raise();
        pushButton_10->raise();
        label_7->raise();
        pushButton_8->raise();
        widget_2->raise();
        widget_3->raise();

        retranslateUi(RequestTestToolClass);

        QMetaObject::connectSlotsByName(RequestTestToolClass);
    } // setupUi

    void retranslateUi(QMainWindow *RequestTestToolClass)
    {
        RequestTestToolClass->setWindowTitle(QApplication::translate("RequestTestToolClass", "RequestTestTool", Q_NULLPTR));
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("RequestTestToolClass", "Socket", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "Socket-SSL", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "Http-Get", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "Http-Post", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "Https-Get", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "Https-Post", Q_NULLPTR)
        );
        pushButton_11->setText(QApplication::translate("RequestTestToolClass", "\345\205\263\344\272\216", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("RequestTestToolClass", "Int", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "File", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "Char", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "String", Q_NULLPTR)
         << QApplication::translate("RequestTestToolClass", "Bit", Q_NULLPTR)
        );
        lineEdit_3->setText(QApplication::translate("RequestTestToolClass", "Key", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("RequestTestToolClass", "Value", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("RequestTestToolClass", "\346\211\271\351\207\217\346\267\273\345\212\240", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("RequestTestToolClass", "\346\267\273\345\212\240", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("RequestTestToolClass", "Data Type", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("RequestTestToolClass", "Value", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("RequestTestToolClass", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("RequestTestToolClass", "\346\226\260\345\273\272\350\241\214", Q_NULLPTR));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        tableWidget->setSortingEnabled(__sortingEnabled);

        label_5->setText(QApplication::translate("RequestTestToolClass", "total:  23 Byte", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("RequestTestToolClass", "\345\210\240\351\231\244", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("RequestTestToolClass", "\346\270\205\347\251\272", Q_NULLPTR));
        lineEdit_2->setText(QApplication::translate("RequestTestToolClass", "Address", Q_NULLPTR));
        radioButton->setText(QApplication::translate("RequestTestToolClass", "Short", Q_NULLPTR));
        radioButton_2->setText(QApplication::translate("RequestTestToolClass", "Long", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("RequestTestToolClass", "\350\277\236\346\216\245", Q_NULLPTR));
        textBrowser->setHtml(QApplication::translate("RequestTestToolClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
        pushButton_10->setText(QString());
        label_7->setText(QApplication::translate("RequestTestToolClass", "Recv: 23 Byte", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("RequestTestToolClass", "ASCII", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("RequestTestToolClass", "\346\270\205\347\251\272", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RequestTestToolClass: public Ui_RequestTestToolClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REQUESTTESTTOOL_H
