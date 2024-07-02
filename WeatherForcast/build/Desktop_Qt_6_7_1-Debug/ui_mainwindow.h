/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCharts/QChartView>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *Longitude;
    QLabel *Latitude;
    QLineEdit *Longitude_in;
    QLineEdit *Latitude_in;
    QPushButton *pushButton;
    QLineEdit *CurrentWeather;
    QChartView *graphicsView;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *Current_Date;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 617);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Longitude = new QLabel(centralwidget);
        Longitude->setObjectName("Longitude");
        Longitude->setGeometry(QRect(280, 20, 81, 17));
        Latitude = new QLabel(centralwidget);
        Latitude->setObjectName("Latitude");
        Latitude->setGeometry(QRect(30, 20, 66, 17));
        Longitude_in = new QLineEdit(centralwidget);
        Longitude_in->setObjectName("Longitude_in");
        Longitude_in->setGeometry(QRect(390, 20, 113, 25));
        Latitude_in = new QLineEdit(centralwidget);
        Latitude_in->setObjectName("Latitude_in");
        Latitude_in->setGeometry(QRect(130, 20, 113, 25));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(600, 20, 161, 25));
        CurrentWeather = new QLineEdit(centralwidget);
        CurrentWeather->setObjectName("CurrentWeather");
        CurrentWeather->setGeometry(QRect(530, 60, 113, 25));
        CurrentWeather->setReadOnly(true);
        graphicsView = new QChartView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 100, 901, 511));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(400, 60, 121, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 60, 101, 17));
        Current_Date = new QLineEdit(centralwidget);
        Current_Date->setObjectName("Current_Date");
        Current_Date->setGeometry(QRect(210, 60, 113, 25));
        Current_Date->setReadOnly(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        Longitude->setText(QCoreApplication::translate("MainWindow", "Longitude:", nullptr));
        Latitude->setText(QCoreApplication::translate("MainWindow", "Latitude:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Get Current Weather", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Current Weather:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Current Date:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
