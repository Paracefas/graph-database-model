#include "Value.hpp"


Value::Value(int x) : x{ x } {}

std::string Value::Print()
{
    return std::to_string(x);
}
