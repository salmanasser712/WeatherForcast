#ifndef UTILITIES_H
#define UTILITIES_H

#include <QtCore>
#include <QtGui>
#include <QtCharts>
#include <QSharedPointer>
#include <QString>
#include <QStringList>
#include <string>
#include <memory>
#include <iostream>
#include "CurlInterface.h"
#include "DataInterface.h"
#include "RapidjasonInterface.h"
#include "Cities.h"


std::shared_ptr<Rapidjson>  GetWeatherData(std::string Lat, std::string Long);
QLineSeries * GetMaxForcastLine(std::shared_ptr<Rapidjson> json);
QLineSeries * GetMinForcastLine(std::shared_ptr<Rapidjson> json);
QCategoryAxis * GetaxisX(std::shared_ptr<Rapidjson> json);
QValueAxis * GetaxisY();
QChart * UpdateGraph(std::shared_ptr<Rapidjson> json);
QStringList GetCitiesQList(Cities obj);

#endif // UTILITIES_H
