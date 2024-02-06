#ifndef SERIALIZER_H
#define SERIALIZER_H
#include <cstdint>
#include "Data.hpp"
#include <string>


class	Serializer{
	private:// non initializable
		Serializer();
		Serializer(const Serializer &obj);
		Serializer	&operator=(const Serializer &other);
		~Serializer();
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);//uintptr_t is safer than long to cast pointers
};

#endif