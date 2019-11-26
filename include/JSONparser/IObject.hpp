#pragma once
#include <optional>
#include <string>

struct IObject
{
    virtual std::string Print() = 0;
    std::optional<std::string> Name;
};