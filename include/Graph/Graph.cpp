#include "Graph.hpp"

#include <algorithm>

void Graph::AddEdge(Object* newVertex, Object* existingVertex, Object* w, bool isBidirectional)
{
    m_G.insert(Triplet{ newVertex, existingVertex, w });
    if (isBidirectional)
        m_G.insert(make_triplet(existingVertex, newVertex, w));
}

void Graph::AddVertex(Object* newVertex)
{
    m_vertices.insert(newVertex);
}

void Graph::DeleteVertex(Object* vertex, bool isBidirectional)
{
    if (m_vertices.count(vertex))
    {
        m_vertices.erase(vertex);
        auto it = std::find_if(m_G.begin(), m_G.end(),
            [vertex](const Triplet<Object*>& t)
            {
                return t.x == vertex || t.y == vertex;
            });
        if (it != m_G.end()) m_G.erase(it);
    }
}

std::set<Object*>* Graph::GetVertices()
{
    return &m_vertices;
}

auto* Graph::GetEdges()
{
    return &m_G;
}

void Graph::SetVertices(std::set<Object*>& vertices)
{
    m_vertices = vertices;
}

void Graph::SetEdges(std::set<Triplet<Object*, Object*, Object*>> edges)
{
    m_G = edges;
}

std::vector<Object*> Graph::operator[](Object* vertex)
{
    std::vector<Object*> res;
    auto it = std::find_if(m_G.begin(), m_G.end(),
        [&vertex](const Triplet<Object*>& t)
        {
            return t.x == vertex || t.y == vertex;
        });

    if (it == m_G.end())
    {
        for (auto* item : m_vertices)
            if (item == vertex)
                res.push_back(item);
    }

    for (auto item : m_G)
        if (item.x == vertex)
            res.push_back(item.z);

    return res;
}

std::vector<Triplet<Object*>> Graph::operator[](std::pair<Object*, Object*> ft)
{
    std::vector<Triplet<Object*>> res;
    for (auto const tr : m_G)
        if (tr.x == ft.first && tr.y == ft.second)
            res.push_back(tr);
    return res;
}
