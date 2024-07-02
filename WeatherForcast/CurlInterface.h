#ifndef CURLINTERFACE_H
#define CURLINTERFACE_H

#include "CurlAbstract.h"


class Curl : public CurlAbstract
{
    public:
    Curl(std::string &latitude, std::string &longitude, DataAbstract *data);
    Curl_Status Curl_Init() override;
    Curl_Status Curl_Setup() override;
    Curl_Status Curl_Preform() override;
    ~Curl() override;
};

#endif
