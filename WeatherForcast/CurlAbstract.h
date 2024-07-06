#ifndef CURLABSTRACT_H
#define CURLABSTRACT_H

#include <curl/curl.h>
#include <memory>
#include "DataAbstract.h"

typedef enum
{
    CURLNOK,
    CURLOK
}Curl_Status;

class CurlAbstract{
    public:
    virtual Curl_Status Curl_Init() = 0;
    virtual Curl_Status Curl_Setup() = 0;
    virtual Curl_Status Curl_Preform() = 0;
    virtual ~CurlAbstract() = 0;

    protected:
    CURL *curl;
    CURLcode result;
    char *weatherAPI;
    std::shared_ptr<DataAbstract> data;
};

#endif // CURLABSTRACT_H
