#pragma once
#include "IObject.hpp"


struct Field : IObject
{
    Field(std::string, std::string);
    std::string Print() override;
    std::string Value;
};
