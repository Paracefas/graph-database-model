#pragma once

#include <fstream>

#include "StringArray.hpp"
#include "Array.hpp"
#include "Object.hpp"
#include "Field.hpp"
#include "Value.hpp"

struct JSON
{
    JSON(char const*, Object*);
    ~JSON();
	Object** GetObject();
    void Parse();
private:
    Object* m_obj;
    std::ofstream m_file;
    std::string m_fileName;
};
