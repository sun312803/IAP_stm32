/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *btnSelectFirmware_A;
    QPushButton *btnStartUpgrade;
    QTextEdit *textLog;
    QProgressBar *progressBar;
    QLineEdit *file_path_A;
    QComboBox *comboBoxSerialPorts;
    QComboBox *comboBoxBaudRate;
    QPushButton *pushButtonConnect;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *file_path_B;
    QPushButton *btnSelectFirmware_B;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *SF_version;
    QLineEdit *Serial_txt;
    QComboBox *chose_app;
    QMenuBar *menubar;
    QMenu *menudebug;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        btnSelectFirmware_A = new QPushButton(centralwidget);
        btnSelectFirmware_A->setObjectName("btnSelectFirmware_A");
        btnSelectFirmware_A->setGeometry(QRect(420, 150, 161, 23));
        btnStartUpgrade = new QPushButton(centralwidget);
        btnStartUpgrade->setObjectName("btnStartUpgrade");
        btnStartUpgrade->setGeometry(QRect(630, 180, 75, 23));
        textLog = new QTextEdit(centralwidget);
        textLog->setObjectName("textLog");
        textLog->setGeometry(QRect(70, 310, 641, 141));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(350, 480, 118, 23));
        progressBar->setValue(0);
        file_path_A = new QLineEdit(centralwidget);
        file_path_A->setObjectName("file_path_A");
        file_path_A->setGeometry(QRect(140, 150, 261, 21));
        comboBoxSerialPorts = new QComboBox(centralwidget);
        comboBoxSerialPorts->setObjectName("comboBoxSerialPorts");
        comboBoxSerialPorts->setGeometry(QRect(160, 80, 69, 22));
        comboBoxBaudRate = new QComboBox(centralwidget);
        comboBoxBaudRate->setObjectName("comboBoxBaudRate");
        comboBoxBaudRate->setGeometry(QRect(320, 80, 69, 22));
        pushButtonConnect = new QPushButton(centralwidget);
        pushButtonConnect->setObjectName("pushButtonConnect");
        pushButtonConnect->setGeometry(QRect(420, 80, 75, 23));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(270, 80, 53, 15));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(90, 80, 53, 15));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(80, 150, 53, 15));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(80, 180, 53, 16));
        file_path_B = new QLineEdit(centralwidget);
        file_path_B->setObjectName("file_path_B");
        file_path_B->setGeometry(QRect(140, 180, 261, 21));
        btnSelectFirmware_B = new QPushButton(centralwidget);
        btnSelectFirmware_B->setObjectName("btnSelectFirmware_B");
        btnSelectFirmware_B->setGeometry(QRect(420, 180, 161, 23));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(560, 20, 71, 20));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(560, 50, 71, 20));
        SF_version = new QLineEdit(centralwidget);
        SF_version->setObjectName("SF_version");
        SF_version->setGeometry(QRect(640, 20, 141, 21));
        Serial_txt = new QLineEdit(centralwidget);
        Serial_txt->setObjectName("Serial_txt");
        Serial_txt->setGeometry(QRect(640, 50, 141, 21));
        chose_app = new QComboBox(centralwidget);
        chose_app->setObjectName("chose_app");
        chose_app->setGeometry(QRect(630, 130, 69, 22));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        menudebug = new QMenu(menubar);
        menudebug->setObjectName("menudebug");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menudebug->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        btnSelectFirmware_A->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\345\233\272\344\273\266", nullptr));
        btnStartUpgrade->setText(QCoreApplication::translate("MainWindow", "\345\215\207\347\272\247", nullptr));
        textLog->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Microsoft YaHei UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        pushButtonConnect->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\263\242\347\211\271\347\216\207", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\344\270\262\345\217\243", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\345\233\272\344\273\266A", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\345\233\272\344\273\266B", nullptr));
        btnSelectFirmware_B->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\345\233\272\344\273\266", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\233\272\344\273\266\347\211\210\346\234\254\345\217\267\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\350\256\276\345\244\207\347\274\226\345\217\267\357\274\232", nullptr));
        menudebug->setTitle(QCoreApplication::translate("MainWindow", "debug", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
