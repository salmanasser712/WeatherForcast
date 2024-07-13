#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    std::shared_ptr<Rapidjson> json = GetWeatherData("29.9964", "31.295");
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
    if(ui->Longitude_in->text().isEmpty() || ui->Latitude_in->text().isEmpty())
    {
        ui->ErrorMsg->setText("THERE IS AN EMPTY FIELD!!");
    }
    else
    {
        std::string longitude = ui->Longitude_in->text().toStdString();
        std::string latitude = ui->Latitude_in->text().toStdString();
        if(isValidNumber(longitude, true) && isValidNumber(latitude, false))
        {
            std::shared_ptr<Rapidjson>  json = GetWeatherData(latitude, longitude);

            float weather = json->GetTemperature();
            ui->CurrentWeather->setText(QString::number(weather, 'g', 4));

            std::string Date = json->GetDate();
            ui->Current_Date->setText(QString::fromStdString(Date));

            QChart * chart = UpdateGraph(json);
            ui->graphicsView->setChart(chart);

            ui->ErrorMsg->setText("");
        }
        else
        {
            ui->ErrorMsg->setText("INVALID NUMBER!!");
        }
    }

}

