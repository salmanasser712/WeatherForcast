#include "RapidjasonInterface.h"

Rapidjson::Rapidjson(char * Res)
{
    this->d.Parse(Res);

}

std::string Rapidjson::GetDate()
{
    std::string s = this->d["current"]["time"].GetString();
    std::string Current_Date = "";
    unsigned long int i = 0;
    while(i < s.size() && s[i] != 'T')
    {
        Current_Date += s[i];
        i++;
    }
    return Current_Date;
}

std::string Rapidjson:: GetTime()
{
    std::string s = this->d["current"]["time"].GetString();
    std::string Current_Time = "";
    unsigned long int i = 0;
    while(i < s.size() && s[i] != 'T') i++;
    i++;
    while(i < s.size())
    {
        Current_Time += s[i];
        i++;
    }
    return Current_Time;
}

float Rapidjson:: GetTemperature()
{
    return d["current"]["temperature_2m"].GetFloat();
}

float * Rapidjson::GetMinForecastTemp()
{
    const Value& MinForecastTemp = this->d["daily"]["temperature_2m_min"];
    static float arr[NumDays];
    for(SizeType i = 0; i < MinForecastTemp.Size(); i++)
    {
        arr[i] = MinForecastTemp[i].GetFloat();
    }
    return arr;
}

float * Rapidjson::GetMaxForecastTemp()
{
    const Value& MaxForecastTemp = this->d["daily"]["temperature_2m_max"];
    static float arr[NumDays];
    for(SizeType i = 0; i < MaxForecastTemp.Size(); i++)
    {
        arr[i] = MaxForecastTemp[i].GetFloat();
    }
    return arr;
}

std::string * Rapidjson:: GetForecastDate()
{
    const Value& ForecastDate = this->d["daily"]["time"];
    static std::string arr[NumDays];
    for(SizeType i = 0; i < ForecastDate.Size(); i++)
    {
        arr[i] = ForecastDate[i].GetString();
    }
    return arr;
}

