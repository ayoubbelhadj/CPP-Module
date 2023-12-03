#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename TYPE>
void	iter(TYPE *arr, size_t size, void (*f)(TYPE&)){
	if (!arr || !f)
		return ;
	for (size_t i = 0; i < size; i++)
		f(arr[i]);
}

#endif