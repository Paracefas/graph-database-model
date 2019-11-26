#include "StringArray.hpp"
#include <sstream>

StringArray::StringArray(char const* name, std::initializer_list<std::string> list)
    : std::vector<std::string>{list} 
{
    this->Name = name;
}
std::string StringArray::Print() 
{
    std::stringstream ss;
    ss << "\"" << *this->Name << "\": [";
    for(auto const& item : *this)
        ss << "\"" << item << "\"" << (item == *(this->end()-1) ? "" : ", ");
    ss << "]";
    return ss.str();
}
