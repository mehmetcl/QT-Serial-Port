/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QProgressBar *progressBar;
    QLCDNumber *lcdNumber;
    QLabel *label_scroll;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_13;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_12;
    QGridLayout *gridLayout_10;
    QGridLayout *gridLayout_8;
    QPushButton *pushButton_Connect;
    QPushButton *pushButton_Disconnect;
    QPushButton *pushButton_Refresh;
    QGridLayout *gridLayout_9;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QGridLayout *gridLayout;
    QComboBox *comboBox_port;
    QComboBox *comboBox_baudrate;
    QComboBox *comboBox_databits;
    QComboBox *comboBox_stopbits;
    QComboBox *comboBox_parity;
    QComboBox *comboBox_flowcontrol;
    QGridLayout *gridLayout_4;
    QLabel *label_7;
    QLineEdit *lineEdit_code;
    QGridLayout *gridLayout_6;
    QTextBrowser *textBrowser;
    QGridLayout *gridLayout_7;
    QLineEdit *lineEdit_send;
    QPushButton *pushButton_send;
    QPushButton *pushButton_clear;
    QGridLayout *gridLayout_11;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_open_project;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer;
    QSlider *horizontalSlider;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(894, 627);
        MainWindow->setMaximumSize(QSize(100000, 100000));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(670, 160, 118, 23));
        progressBar->setMinimum(0);
        progressBar->setValue(1);
        lcdNumber = new QLCDNumber(centralwidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(640, 62, 201, 81));
        lcdNumber->setDigitCount(5);
        lcdNumber->setProperty("intValue", QVariant(0));
        label_scroll = new QLabel(centralwidget);
        label_scroll->setObjectName(QString::fromUtf8("label_scroll"));
        label_scroll->setGeometry(QRect(670, 250, 49, 16));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(9, 9, 547, 390));
        gridLayout_13 = new QGridLayout(layoutWidget);
        gridLayout_13->setObjectName(QString::fromUtf8("gridLayout_13"));
        gridLayout_13->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_13->addItem(verticalSpacer_2, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_13->addItem(horizontalSpacer, 1, 0, 1, 1);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QString::fromUtf8("gridLayout_12"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        pushButton_Connect = new QPushButton(layoutWidget);
        pushButton_Connect->setObjectName(QString::fromUtf8("pushButton_Connect"));

        gridLayout_8->addWidget(pushButton_Connect, 0, 0, 1, 1);

        pushButton_Disconnect = new QPushButton(layoutWidget);
        pushButton_Disconnect->setObjectName(QString::fromUtf8("pushButton_Disconnect"));

        gridLayout_8->addWidget(pushButton_Disconnect, 0, 1, 1, 1);

        pushButton_Refresh = new QPushButton(layoutWidget);
        pushButton_Refresh->setObjectName(QString::fromUtf8("pushButton_Refresh"));

        gridLayout_8->addWidget(pushButton_Refresh, 0, 2, 1, 1);


        gridLayout_10->addLayout(gridLayout_8, 0, 0, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 3, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 4, 0, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 5, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        comboBox_port = new QComboBox(layoutWidget);
        comboBox_port->setObjectName(QString::fromUtf8("comboBox_port"));

        gridLayout->addWidget(comboBox_port, 0, 0, 1, 1);

        comboBox_baudrate = new QComboBox(layoutWidget);
        comboBox_baudrate->setObjectName(QString::fromUtf8("comboBox_baudrate"));

        gridLayout->addWidget(comboBox_baudrate, 1, 0, 1, 1);

        comboBox_databits = new QComboBox(layoutWidget);
        comboBox_databits->setObjectName(QString::fromUtf8("comboBox_databits"));

        gridLayout->addWidget(comboBox_databits, 2, 0, 1, 1);

        comboBox_stopbits = new QComboBox(layoutWidget);
        comboBox_stopbits->setObjectName(QString::fromUtf8("comboBox_stopbits"));

        gridLayout->addWidget(comboBox_stopbits, 3, 0, 1, 1);

        comboBox_parity = new QComboBox(layoutWidget);
        comboBox_parity->setObjectName(QString::fromUtf8("comboBox_parity"));

        gridLayout->addWidget(comboBox_parity, 4, 0, 1, 1);

        comboBox_flowcontrol = new QComboBox(layoutWidget);
        comboBox_flowcontrol->setObjectName(QString::fromUtf8("comboBox_flowcontrol"));

        gridLayout->addWidget(comboBox_flowcontrol, 5, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout, 0, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_4->addWidget(label_7, 0, 0, 1, 1);

        lineEdit_code = new QLineEdit(layoutWidget);
        lineEdit_code->setObjectName(QString::fromUtf8("lineEdit_code"));

        gridLayout_4->addWidget(lineEdit_code, 0, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 1, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_5, 0, 0, 1, 1);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        textBrowser = new QTextBrowser(layoutWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));

        gridLayout_6->addWidget(textBrowser, 0, 0, 1, 1);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        lineEdit_send = new QLineEdit(layoutWidget);
        lineEdit_send->setObjectName(QString::fromUtf8("lineEdit_send"));

        gridLayout_7->addWidget(lineEdit_send, 0, 0, 1, 1);

        pushButton_send = new QPushButton(layoutWidget);
        pushButton_send->setObjectName(QString::fromUtf8("pushButton_send"));

        gridLayout_7->addWidget(pushButton_send, 0, 1, 1, 1);

        pushButton_clear = new QPushButton(layoutWidget);
        pushButton_clear->setObjectName(QString::fromUtf8("pushButton_clear"));

        gridLayout_7->addWidget(pushButton_clear, 0, 2, 1, 1);


        gridLayout_6->addLayout(gridLayout_7, 1, 0, 1, 1);


        gridLayout_9->addLayout(gridLayout_6, 0, 1, 1, 1);


        gridLayout_10->addLayout(gridLayout_9, 1, 0, 1, 1);


        gridLayout_12->addLayout(gridLayout_10, 0, 0, 1, 1);

        gridLayout_11 = new QGridLayout();
        gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
        horizontalSpacer_2 = new QSpacerItem(35, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        pushButton_open_project = new QPushButton(layoutWidget);
        pushButton_open_project->setObjectName(QString::fromUtf8("pushButton_open_project"));

        gridLayout_11->addWidget(pushButton_open_project, 0, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_11->addItem(horizontalSpacer_3, 0, 2, 1, 1);


        gridLayout_12->addLayout(gridLayout_11, 1, 0, 1, 1);


        gridLayout_13->addLayout(gridLayout_12, 1, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_13->addItem(horizontalSpacer_4, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_13->addItem(verticalSpacer, 2, 1, 1, 1);

        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(650, 290, 160, 16));
        horizontalSlider->setMaximum(1000);
        horizontalSlider->setSingleStep(10);
        horizontalSlider->setPageStep(10);
        horizontalSlider->setValue(0);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setInvertedControls(true);
        horizontalSlider->setTickPosition(QSlider::TicksBelow);
        horizontalSlider->setTickInterval(100);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 894, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_scroll->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_Connect->setText(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        pushButton_Disconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        pushButton_Refresh->setText(QCoreApplication::translate("MainWindow", "Refresh Ports", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Port:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Baud Rate:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Data Bits:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Stop Bits:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Parity:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Flow Control:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Code:", nullptr));
        pushButton_send->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        pushButton_open_project->setText(QCoreApplication::translate("MainWindow", "Open Project", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
