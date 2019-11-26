#include "Object.hpp"

Object::Object(std::vector<IObject*> objs)
    : m_Objects{objs} {}
    
Object::Object(char const* name, std::vector<IObject*> objs)
    : m_Objects {objs} 
{
    this->Name = name;
}

Object::~Object()
{
    for(auto* obj : m_Objects)
        delete obj;
}

std::string Object::Print() 
{
    std::stringstream ss;
    if(this->Name.has_value())
        ss << "\"" << *this->Name << "\": ";
    ss << "{";
    for(auto* obj : m_Objects)
        ss << obj->Print() << (obj == *(m_Objects.end()-1) ? "" : ",");
    ss << "}";
    return ss.str(); 
}
