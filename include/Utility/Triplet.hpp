#pragma once

//TODO: Remove this header file
#include "../JSONparser/JSON.hpp"


template<typename T, typename U = T, typename Z = T>
struct Triplet 
{
	Triplet(T t, U u, Z z)
		: x{ t }, y{ u }, z{ z } {}
	
	T x;
	U y;
	Z z;
};


//TODO: Remove/Move this class
template<>
struct Triplet<Object*> : IObject
{
	Triplet(Object* t, Object* u, Object* z)
		: x{ t }, y{ u }, z{ z } {}

	std::string Print() override
	{
		std::stringstream ss;
		ss << z->Print();
		return ss.str();
	}

	Object* x, * y, * z;
};

template<typename T, typename U, typename Z>
bool operator==(Triplet<T, U, Z> l, Triplet<T, U, Z> r)
{
	return l.x == r.x && l.y == r.y && l.z == r.z;
}

template<typename T, typename U, typename Z>
bool operator<(Triplet<T, U, Z> l, Triplet<T, U, Z> r)
{
	return l.x < r.x && l.y < r.y && l.z < r.z;
}

template<typename T, typename U, typename Z>
Triplet<T, U, Z> make_triplet(T t, U u, Z z)
{
	return { t, u, z };
}
