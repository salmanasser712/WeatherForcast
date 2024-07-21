#include "Utilities.h"


std::shared_ptr<Rapidjson> GetWeatherData(std::string Lat, std::string Long)
{
    std::shared_ptr<Data>  data = std::make_shared<Data>();
    std::shared_ptr<Curl> curlobj = std::make_shared<Curl>(Lat, Long, data);
    curlobj->Curl_Init();
    curlobj->Curl_Setup();
    curlobj->Curl_Preform();

    std::shared_ptr<Rapidjson> json = std::make_shared<Rapidjson>(data->GetResponse());

    return json;
}

QLineSeries * GetMaxForcastLine(std::shared_ptr<Rapidjson> json)
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

QLineSeries * GetMinForcastLine(std::shared_ptr<Rapidjson> json)
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

QCategoryAxis * GetaxisX(std::shared_ptr<Rapidjson>  json)
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
    axisY->setTickCount(15);

    return axisY;
}
QChart * UpdateGraph(std::shared_ptr<Rapidjson> json)
{
    QLineSeries * MaxTempLine = GetMaxForcastLine(json);
    QLineSeries * MinTempLine = GetMinForcastLine(json);

    QChart* chart_method = new QChart();
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

    return chart_method;
}

QStringList GetCitiesQList(Cities obj)
{
    std::vector<std::string> vec = obj.GetCities();
    QStringList StrList;
    for(const auto& city: vec)
    {
        StrList.append(QString::fromStdString(city));
    }
    return StrList;
}
