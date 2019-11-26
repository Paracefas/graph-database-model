#pragma once
#include <vector>
#include "IObject.hpp"

struct Array : std::vector<IObject*>, IObject
{
	Array(const char*);
    Array(const char*, std::initializer_list<IObject*>);
    std::string Print() override ;
	std::vector<IObject*> GetObjects();
};
