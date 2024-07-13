#ifndef DATAABSTRACT_H
#define DATAABSTRACT_H

#include <string>
#include <cstring>

class DataAbstract{
    public:
        virtual char * GetResponse() = 0;
        virtual ~DataAbstract() = 0;

    protected:
        char * Response;
        size_t size;
};

#endif // DATAABSTRACT_H
