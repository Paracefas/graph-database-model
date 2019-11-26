#include <DataBase/DataBase.hpp>

int main()
{
	Object* Emanuel = new Object{ "Emanuel", { new Field{ "Age", "18" }, new Field { "Phone", "+54 9 223 5597 776" } } };
	Object* Aguero = new Object{ "Aguero", { new Field{ "Age", "18" }, new Field { "Phone", "+54 9 223 5593 456" } } };
	Object* Meets = new Object{ "Meets", { new Field{ "When", "18/7/2015" } } };
	Object* Knows = new Object{ "Knows", { new Field{ "When", "18/7/2015" } } };
	Object* Friend = new Object{ "Friend", { new Field{ "Quality", "Best Friend" }} };

	DataBase db{ "data" };
	db.Insert(Emanuel);
	db.Insert(Aguero);
	db.Relate(Emanuel, Aguero, Meets);
	db.Relate(Aguero, Emanuel, Knows);
	db.Relate(Emanuel, Aguero, Friend);
	db.Parse();
}