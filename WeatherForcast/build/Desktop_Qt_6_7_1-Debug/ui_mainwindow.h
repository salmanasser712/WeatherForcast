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
    QLabel *Longtiude;
    QLabel *Latitude;
    QLineEdit *Longitude_in;
    QLineEdit *Latitude_in;
    QPushButton *pushButton;
    QLineEdit *CurrentWeather;
    QChartView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(796, 530);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        Longtiude = new QLabel(centralwidget);
        Longtiude->setObjectName("Longtiude");
        Longtiude->setGeometry(QRect(40, 30, 81, 17));
        Latitude = new QLabel(centralwidget);
        Latitude->setObjectName("Latitude");
        Latitude->setGeometry(QRect(300, 30, 66, 17));
        Longitude_in = new QLineEdit(centralwidget);
        Longitude_in->setObjectName("Longitude_in");
        Longitude_in->setGeometry(QRect(140, 30, 113, 25));
        Latitude_in = new QLineEdit(centralwidget);
        Latitude_in->setObjectName("Latitude_in");
        Latitude_in->setGeometry(QRect(390, 30, 113, 25));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(560, 30, 161, 25));
        CurrentWeather = new QLineEdit(centralwidget);
        CurrentWeather->setObjectName("CurrentWeather");
        CurrentWeather->setGeometry(QRect(340, 80, 113, 25));
        CurrentWeather->setReadOnly(true);
        graphicsView = new QChartView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 130, 791, 361));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 796, 22));
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
        Longtiude->setText(QCoreApplication::translate("MainWindow", "Longtiude:", nullptr));
        Latitude->setText(QCoreApplication::translate("MainWindow", "Latitude:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Get Current Weather", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
