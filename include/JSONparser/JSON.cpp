#include "JSON.hpp"

JSON::JSON(char const* fileName, Object* obj)
    : m_fileName{fileName}, m_obj{obj} {}

JSON::~JSON()
{
    delete m_obj;
}

Object** JSON::GetObject()
{
	return &m_obj;
}

void JSON::Parse()
{
	m_file.open(m_fileName);
    m_file << m_obj->Print();
}
