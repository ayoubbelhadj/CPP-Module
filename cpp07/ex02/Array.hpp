#ifndef ARRAY_HPP
#define ARRAY_HPP

#include<iostream>

template<class T>
class Array{
private:
	T* 				arr;
	unsigned int	sizy;
public:
	Array();
	Array(unsigned int n);
	Array(const Array& obj);
	Array& operator=(const Array& obj);
	~Array();

	unsigned int	size(void) const;
	
	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;
	
	class OutOfBound : public std::exception{
		public:
			virtual const char *what() const throw(){
				return ("Index is out of bounds.");
			}
	};
};

#include "Array.tpp"
#endif