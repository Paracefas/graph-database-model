#include "Array.hpp"
#include <sstream>

Array::Array(const char* name)
{
	this->Name = name;
}

Array::Array(const char* name, std::initializer_list<IObject*> objs)
    : std::vector<IObject*>{objs}
{
    this->Name = name;
}

std::string Array::Print()  
{
    std::stringstream ss;
    ss << "\"" << *this->Name << "\": " << "[";
	for(auto const& item : *this)
        ss << item->Print() << (item == *(this->end()-1) ? "" : ", ");
    ss << "]";
    return ss.str();
}

std::vector<IObject*> Array::GetObjects()
{
	return *this;
}
