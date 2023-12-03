#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename TYPE>
void	swap(TYPE &a, TYPE &b){
	TYPE c;
	c = a;
	a = b;
	b = c;
}

template <typename TYPE>
TYPE	min(TYPE &a, TYPE &b){
	if (a < b)
		return a;
	return b;
}

template <typename TYPE>
TYPE	max(TYPE &a, TYPE &b){
	if (a > b)
		return a;
	return b;
}
#endif