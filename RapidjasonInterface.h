#ifndef RAPIDJSONINTERFACE_H
#define RAPIDJSONINTERFACE_H

#include "RapidjsonAbstract.h"

#define NumDays   7

class Rapidjson : public RapidjsonAbstract
{
    public:
    Rapidjson(char * Res);
    std::string GetDate() override;
    std::string GetTime() override;
    float GetTemperature() override;
    float * GetMinForecastTemp();
    float * GetMaxForecastTemp();
    std::string * GetForecastDate();
    ~Rapidjson()override = default;
};


#endif
