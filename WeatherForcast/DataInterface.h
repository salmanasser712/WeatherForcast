#ifndef DATAINTERFACE_H
#define DATAINTERFACE_H

#include "DataAbstract.h"

class Data : public DataAbstract
{
    public:
    Data();
    char * GetResponse() override;
    static size_t write_chunk(void *data, size_t size, size_t nmemb, void *userdata);
    ~Data()override;
};

#endif
