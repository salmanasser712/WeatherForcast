#include "Utilities.h"


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

QLineSeries * GetMaxForcastLine(Rapidjson * json)
{
    float * Maxtemp = json->GetMaxForcastTemp();
    QLineSeries * MaxTempLine = new QLineSeries();

    for(int i = 0; i < NumDays; i++)
    {
        MaxTempLine->append(i, Maxtemp[i]);
    }
    QPen pen(QRgb(0x830000));
    pen.setWidth(4);
    MaxTempLine->setPen(pen);
    MaxTempLine->setName("Max. Temperature");

    return MaxTempLine;
}

QLineSeries * GetMinForcastLine(Rapidjson * json)
{
    float * Mintemp = json->GetMinForcastTemp();
    QLineSeries * MinTempLine = new QLineSeries();

    for(int i = 0; i < NumDays; i++)
    {
        MinTempLine->append(i, Mintemp[i]);
    }

    QPen pen_min(QRgb(0x00006e));
    pen_min.setWidth(4);
    MinTempLine->setPen(pen_min);
    MinTempLine->setName("Min. Temperature");

    return MinTempLine;
}

QCategoryAxis * GetaxisX(Rapidjson * json)
{
    std::string * Dates = json->GetForcastDate();

    QCategoryAxis * axisX = new QCategoryAxis();
    axisX->setTitleText("Date");
    for(int i = 0; i < NumDays; i++)
    {
        axisX->append(QString::fromStdString(Dates[i]), i);
    }

    return axisX;
}

QValueAxis * GetaxisY()
{
    QValueAxis* axisY = new QValueAxis;
    axisY->setTitleText("Temperature [°C]");
    axisY->setRange(20, 50);
    axisY->setTickCount(15);

    return axisY;
}
QChart * UpdateGraph(Rapidjson * json)
{
    QLineSeries * MaxTempLine = GetMaxForcastLine(json);
    QLineSeries * MinTempLine = GetMinForcastLine(json);

    QChart * chart_method = new QChart();
    chart_method->addSeries(MaxTempLine);
    chart_method->addSeries(MinTempLine);
    chart_method->createDefaultAxes();
    chart_method->setTitle("7-Days Weather ForCast");
    chart_method->setVisible(true);

    QCategoryAxis * axisX = GetaxisX(json);
    chart_method->setAxisX(axisX, MaxTempLine);
    chart_method->setAxisX(axisX, MinTempLine);

    QValueAxis* axisY = GetaxisY();
    chart_method->setAxisY(axisY, MaxTempLine);
    chart_method->setAxisY(axisY, MinTempLine);

    delete(json);

    return chart_method;
}
