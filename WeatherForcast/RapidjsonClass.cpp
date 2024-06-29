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

float * Rapidjson::GetMinForcastTemp()
{
    const Value& MinForcastTemp = this->d["daily"]["temperature_2m_min"];
    static float arr[NumDays];
    for(SizeType i = 0; i < MinForcastTemp.Size(); i++)
    {
        arr[i] = MinForcastTemp[i].GetFloat();
    }
    return arr;
}

float * Rapidjson::GetMaxForcastTemp()
{
    const Value& MaxForcastTemp = this->d["daily"]["temperature_2m_max"];
    static float arr[NumDays];
    for(SizeType i = 0; i < MaxForcastTemp.Size(); i++)
    {
        arr[i] = MaxForcastTemp[i].GetFloat();
    }
    return arr;
}

std::string * Rapidjson:: GetForcastDate()
{
    const Value& ForcastDate = this->d["daily"]["time"];
    static std::string arr[NumDays];
    for(SizeType i = 0; i < ForcastDate.Size(); i++)
    {
        arr[i] = ForcastDate[i].GetString();
    }
    return arr;
}
