#pragma once
#include <sstream>
#include <vector>
#include "IObject.hpp"

struct Object : IObject
{
    Object(std::vector<IObject*>);
    Object(char const*, std::vector<IObject*>);
    ~Object();
    
    std::string Print() override;

    std::vector<IObject*> m_Objects;
};
