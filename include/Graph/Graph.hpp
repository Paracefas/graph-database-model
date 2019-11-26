#pragma once
#include <set>

//TODO: Remove this header file
#include "../JSONParser/JSON.hpp"
#include "../Utility/Triplet.hpp"

//TODO: Make it class generic
class Graph
{
	std::set<Object*> m_vertices;
	std::set<Triplet<Object*>> m_G;
public:
	void AddEdge(Object*, Object*, Object*, bool = false);
	void AddVertex(Object*);
	void DeleteVertex(Object*, bool= false);
	std::set<Object*>* GetVertices();
	auto* GetEdges();
	void SetVertices(std::set<Object*>&);
	void SetEdges(std::set<Triplet<Object*, Object*, Object*>>);
	std::vector<Object*> operator[](Object*);
	std::vector<Triplet<Object*>> operator[](std::pair<Object*, Object*>);
};