#include<Cities.h>

void Cities::AddCity( std::string name, std::string latitude, std::string longitude)
{
    std::pair<std::string, std::string> axis = {latitude, longitude};
    this->cities[name] = axis;
}

std::pair<std::string, std::string> Cities::GetAxis(std::string name)
{
    return this->cities[name];
}

std::vector<std::string> Cities::GetCities()
{
    std::vector<std::string> vec;
    for(const auto& item : this->cities)
    {
        vec.push_back(item.first);
    }
    return vec;
}
