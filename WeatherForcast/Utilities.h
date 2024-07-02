#ifndef UTILITIES_H
#define UTILITIES_H

#include <QtCore>
#include <QtGui>
#include <QtCharts>
#include <QSharedPointer>
#include <string>
#include <memory>
#include <iostream>
#include "CurlInterface.h"
#include "DataInterface.h"
#include "RapidjasonInterface.h"

Rapidjson * GetWeatherData(std::string Lat, std::string Long);
QLineSeries * GetMaxForcastLine(Rapidjson * json);
QLineSeries * GetMinForcastLine(Rapidjson * json);
QCategoryAxis * GetaxisX(Rapidjson * json);
QValueAxis * GetaxisY();
QChart * UpdateGraph(Rapidjson * json);

#endif // UTILITIES_H
