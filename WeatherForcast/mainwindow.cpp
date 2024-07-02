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
Rapidjson * GetWeatherData(std::string Lat, std::string Long)
{
    Data * data = new Data();
    Curl * curlobj = new Curl(Lat, Long, data);
    curlobj->Curl_Init();
    curlobj->Curl_Setup();
    curlobj->Curl_Preform();
    Rapidjson * json = new Rapidjson(data->GetResponse());

    delete(curlobj);
    delete(data);

    return json;
}
QChart * UpdateGraph(Rapidjson * json)
{
    float * Mintemp = json->GetMinForcastTemp();
    float * Maxtemp = json->GetMaxForcastTemp();
    std::string * Dates = json->GetForcastDate();

    QLineSeries * MaxTempLine = new QLineSeries();
    QLineSeries * MinTempLine = new QLineSeries();

    for(int i = 0; i < NumDays; i++)
    {
        MaxTempLine->append(i, Maxtemp[i]);
        MinTempLine->append(i, Mintemp[i]);
    }

    QPen pen(QRgb(0x830000));
    pen.setWidth(4);
    MaxTempLine->setPen(pen);
    MaxTempLine->setName("Max. Temperature");

    QPen pen_min(QRgb(0x00006e));
    pen_min.setWidth(4);
    MinTempLine->setPen(pen_min);
    MinTempLine->setName("Min. Temperature");

    QChart * chart_method = new QChart();
    chart_method->addSeries(MaxTempLine);
    chart_method->addSeries(MinTempLine);
    chart_method->createDefaultAxes();
    chart_method->setTitle("7-Days Weather ForCast");
    chart_method->setVisible(true);

    QCategoryAxis * axisX = new QCategoryAxis();
    axisX->setTitleText("Date");
    for(int i = 0; i < NumDays; i++)
    {
        axisX->append(QString::fromStdString(Dates[i]), i);
    }
    chart_method->setAxisX(axisX, MaxTempLine);
    chart_method->setAxisX(axisX, MinTempLine);

    QValueAxis* axisY = new QValueAxis;
    axisY->setTitleText("Temperature [°C]");
    axisY->setRange(20, 50);
    axisY->setTickCount(15);

    chart_method->setAxisY(axisY, MaxTempLine);
    chart_method->setAxisY(axisY, MinTempLine);




    delete(json);

    return chart_method;

}

