#ifndef CITIES_H
#define CITIES_H

#include <string>
#include <map>
#include <vector>


class Cities{
    public:
    void AddCity( std::string name, std::string latitude, std::string longitude);
    std::pair<std::string, std::string> GetAxis(std::string name);
    std::vector<std::string> GetCities();

    private:
    std::map<std::string, std::pair<std::string, std::string> > cities;

};

#endif // CITIES_H
