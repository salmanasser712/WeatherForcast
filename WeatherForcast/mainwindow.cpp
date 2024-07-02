#include "mainwindow.h"
#include "ui_mainwindow.h"


Rapidjson * GetWeatherData(std::string Long, std::string Lat);
QChart *  UpdateGraph(Rapidjson * json);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    Rapidjson * json = GetWeatherData("29.9964", "31.295");
    float weather = json->GetTemperature();
    ui->CurrentWeather->setText(QString::number(weather, 'g', 4));

    std::string Date = json->GetDate();
    ui->Current_Date->setText(QString::fromStdString(Date));

    QChart * chart = UpdateGraph(json);
    ui->graphicsView->setChart(chart);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    std::string longitude = ui->Longitude_in->text().toStdString();
    std::string latitude = ui->Latitude_in->text().toStdString();
    Rapidjson * json = GetWeatherData(latitude, longitude);

    float weather = json->GetTemperature();
    ui->CurrentWeather->setText(QString::number(weather, 'g', 4));

    std::string Date = json->GetDate();
    ui->Current_Date->setText(QString::fromStdString(Date));

    QChart * chart = UpdateGraph(json);
    ui->graphicsView->setChart(chart);

}

