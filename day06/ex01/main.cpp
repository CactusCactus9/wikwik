#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int	main(){
	Data	*deser;
	uintptr_t raw;
	Data	data;

	data.num = 2;
	raw = Serializer::serialize(&data);
	if (!raw)
		return (1);
	std::cout <<  "Address before : "<< &data << std::endl;
	deser = Serializer::deserialize(raw);
	std::cout << "Data number: " << data.num << std::endl;
	std::cout << "Deserialized: " << deser->num << std::endl;
	std::cout <<  "Address after : "<<deser << std::endl;

//Allows casting between pointer types and between pointer and integer types.
//The reinterpret_cast operator is used to convert the pointer to any other type of pointer. 
//It does not perform any check whether the pointer converted is of the same type or not.
}