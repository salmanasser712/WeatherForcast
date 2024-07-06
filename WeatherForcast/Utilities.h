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


bool isValidNumber(std::string& stdStr, bool Longtiude);
std::shared_ptr<Rapidjson>  GetWeatherData(std::string Lat, std::string Long);
QLineSeries * GetMaxForcastLine(std::shared_ptr<Rapidjson> json);
QLineSeries * GetMinForcastLine(std::shared_ptr<Rapidjson> json);
QCategoryAxis * GetaxisX(std::shared_ptr<Rapidjson> json);
QValueAxis * GetaxisY();
QChart * UpdateGraph(std::shared_ptr<Rapidjson> json);

#endif // UTILITIES_H
