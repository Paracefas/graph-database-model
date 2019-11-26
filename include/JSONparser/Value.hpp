#pragma once
#include "IObject.hpp"

struct Value : IObject
{
	Value(int);
	std::string Print() override;
    int x;
};