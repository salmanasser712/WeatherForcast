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
    float * GetMinForcastTemp();
    float * GetMaxForcastTemp();
    std::string * GetForcastDate();
    ~Rapidjson()override = default;
};


#endif
