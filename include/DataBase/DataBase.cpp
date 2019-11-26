#include "DataBase.hpp"

DataBase::DataBase(std::string dbName)
    : m_dbName{ dbName }, m_json{ (dbName + ".json").c_str(), new Object{ {} } }, m_data{ new Array {dbName.c_str()} }
{}
void DataBase::Relate(Object* one, Object* another, Object* w)
{
    if (m_data->size() < 0) return;
    m_g.AddEdge(one, another, w);

    int pos = -1;

    for (int i = 0; i < (int)m_data->size(); ++i)
    {
        if (auto objName = *((Object*)m_data->GetObjects()[i])->m_Objects[1]->Name; 
            objName == *one->Name )
            pos = i;
    }
    m_data->push_back(new Object{ 
            { 
                new Field { "__ID__", std::to_string(m_data->size()) },
                new Triplet<Object*>{ one, another, w }
            }
        });
        
    //TODO: Change [0] to push_back in order to make a push to __Edges__  and not override it
	((Array*)((Object*)m_data->GetObjects()[pos])->m_Objects[2])
		->push_back(
			new Object
			{ 
				{
					{ 
						new Field
						{ 
							"__Throw__", *w->Name 
						}, 
						new Field
						{ 
							"__To__", *another->Name
						}, 
						new Field
						{
							"__EdgeId__", std::to_string((int)m_data->size() - 1)
						} 
					} 
				} 
			});
}
void DataBase::Insert(Object* obj)
{
    m_g.AddVertex(obj);
    m_data->push_back(new Object{
        { 
            new Field { "__ID__", std::to_string(m_data->size()) }, 
            obj,
			new Array { "__Edges__", {} }// { new Object {{ new Field{ "__Throw__", {} } , new Field{ "__To__", {} }, new Field{"__EdgeId__", {} } } } } }
        } 
    });
}
void DataBase::Parse()
{
    (*m_json.GetObject())->m_Objects.push_back(m_data);
    m_json.Parse();
}
