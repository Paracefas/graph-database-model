#include "Field.hpp"
#include <sstream>

Field::Field(std::string key, std::string value)
    : Value{value} 
{
	this->Name = key;
}

std::string Field::Print()
{
    std::stringstream ss;
    ss << "\"" << *this->Name << "\": " << "\"" << Value << "\"";
    return ss.str();
}   
