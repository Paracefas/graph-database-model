#pragma once

#include "../JSONparser/JSON.hpp"
#include "../Graph/Graph.hpp"

class DataBase
{
	JSON m_json;
	Array* m_data;
	Graph m_g;
	std::string_view m_dbName;
public:
	DataBase(std::string);
    void Relate(Object*, Object*, Object*);
	void Insert(Object*);
	void Parse();
};