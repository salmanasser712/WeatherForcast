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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
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
    QPushButton *pushButton;
    QChartView *graphicsView;
    QLabel *label;
    QLabel *label_2;
    QComboBox *citieslist;
    QLabel *label_3;
    QLabel *Current_Date;
    QLabel *CurrentWeather;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 617);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(680, 10, 161, 25));
        graphicsView = new QChartView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(0, 100, 901, 511));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(400, 60, 121, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 60, 101, 17));
        citieslist = new QComboBox(centralwidget);
        citieslist->setObjectName("citieslist");
        citieslist->setGeometry(QRect(350, 10, 86, 25));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(citieslist->sizePolicy().hasHeightForWidth());
        citieslist->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(11);
        citieslist->setFont(font);
        citieslist->setMaxVisibleItems(7);
        citieslist->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(175, 10, 161, 20));
        Current_Date = new QLabel(centralwidget);
        Current_Date->setObjectName("Current_Date");
        Current_Date->setGeometry(QRect(220, 60, 66, 17));
        CurrentWeather = new QLabel(centralwidget);
        CurrentWeather->setObjectName("CurrentWeather");
        CurrentWeather->setGeometry(QRect(560, 60, 66, 17));
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
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Weather Forcast", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Get Current Weather", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Current Weather:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Current Date:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Choose a governorate:", nullptr));
        Current_Date->setText(QString());
        CurrentWeather->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
