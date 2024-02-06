#ifndef TEMPLATES_H
#define TEMPLATES_H
#include <iostream>

template	<typename T>
void	swap(T &a, T &b){
	T	c;
	c = a;
	a = b;
	b = c;
}

template	<typename T>
T	min(T a, T b){
	return ((a >= b) ? b : a);
}

template	<typename T>
T	max(T a, T b){
	return ((a <= b) ? b : a);
}

#endif

//Templates in C++ provide a way to write generic code that can work with different data types without having to rewrite the code for each type.
