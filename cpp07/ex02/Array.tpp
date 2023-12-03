#include "Array.hpp"

#include <iostream>

template < class T >
Array<T>::Array(){
	this->sizy = 0;
	this->arr = new T[0];
}

template <class T>
Array<T>::Array(unsigned int n){
	this->sizy = n;
	this->arr = new T[n];
}


template <class T>
Array<T>::Array(const Array& obj){
	this->arr = NULL;
	*this = obj;
}


template <class T>
Array<T>& Array<T>::operator=(const Array& obj){
	if (this->arr)
		delete [] this->arr;
	if (obj.sizy != 0 && this != &obj)
	{
		this->arr = new T[obj.sizy];
		for (unsigned int i = 0; i < obj.sizy; i++)
			this->arr[i] = obj.arr[i];
		this->sizy = obj.sizy;
	}
	return *this;
}

template <class T>
Array<T>::~Array(){
	delete [] this->arr;
}

template <class T>
unsigned int	Array<T>::size(void) const{
	return this->sizy;
}

template <class T>
T& Array<T>::operator[](unsigned int index){
	if (index >= this->sizy)
		throw OutOfBound();
	return this->arr[index];
}

template <class T>
const T& Array<T>::operator[](unsigned int index) const{
	if (index >= this->sizy)
		throw OutOfBound();
	return this->arr[index];
}