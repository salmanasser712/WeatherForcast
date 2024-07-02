#ifndef RAPIDJSONABSTRACT_H
#define RAPIDJSONABSTRACT_H

#include <string>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace rapidjson;

class RapidjsonAbstract
{
    public:
        virtual std::string GetDate() = 0;
        virtual std::string GetTime() = 0;
        virtual float GetTemperature() = 0;
        virtual ~RapidjsonAbstract() = default;

    protected:
        Document d;
};

#endif // RAPIDJSONABSTRACT_H
