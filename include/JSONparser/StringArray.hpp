#pragma once
#include <vector>
#include "IObject.hpp"
#include <sstream>

struct StringArray : std::vector<std::string>, IObject
{
	StringArray(char const*, std::initializer_list<std::string>);
	std::string Print() override;
};
