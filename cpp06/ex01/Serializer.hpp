#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP


#include <cstdint>
#include <iostream>

typedef struct Data
{
	std::string login;
	std::string name;
	size_t		age;
	struct Data	*next;
} Data;

class Serializer
{
public:
	Serializer(Serializer& obj);
	Serializer& operator=(Serializer& obj);
	Serializer();
	~Serializer();
	static uintptr_t serialize(Data* ptr);
	static Data* deserialize(uintptr_t raw);
};

#endif