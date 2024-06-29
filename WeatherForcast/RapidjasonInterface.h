#ifndef RAPIDJSONINTERFACE_H
#define RAPIDJSONINTERFACE_H

#include <string>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#define NumDays   7

using namespace rapidjson;

class Rapidjson
{
    public:
    Rapidjson(char * Res);
    void JsonParse();
    std::string GetDate();
    std::string GetTime();
    float GetTemperature();
    float * GetMinForcastTemp();
    float * GetMaxForcastTemp();
    std::string * GetForcastDate();

    private:
    Document d;
};


#endif
