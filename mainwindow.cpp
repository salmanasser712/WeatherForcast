#include "mainwindow.h"
#include "ui_mainwindow.h"

Cities cities;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->citieslist->setStyleSheet("combobox-popup: 0;");
    ui->citieslist->view()->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    QStringList citieslist = GetCitiesQList(cities);
    ui->citieslist->addItems(citieslist);

    std::string city = ui->citieslist->currentText().toStdString();
    std::pair<std::string, std::string> axis = cities.GetAxis(city);

    std::shared_ptr<Rapidjson> json = GetWeatherData(axis.first, axis.second);
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
    std::string city = ui->citieslist->currentText().toStdString();
    std::pair<std::string, std::string> axis = cities.GetAxis(city);

    std::shared_ptr<Rapidjson>  json = GetWeatherData(axis.first, axis.second);

    float weather = json->GetTemperature();
    ui->CurrentWeather->setText(QString::number(weather, 'g', 4));

    std::string Date = json->GetDate();
    ui->Current_Date->setText(QString::fromStdString(Date));

    QChart * chart = UpdateGraph(json);
    ui->graphicsView->setChart(chart);

}

