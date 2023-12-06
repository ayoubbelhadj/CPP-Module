#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>

class NotFound : public std::exception
{
    public:
        virtual const char *what() const throw(){
            return ("The value not found.");
        }
};

template <typename T>
void easyfind(T& container, int value){
    typename    T::iterator itr = container.begin();

    while (itr != container.end()){
        if (*itr == value){
            std::cout << "The value [ " << value << " ] is there." << std::endl;
            return ;
        }
        itr++;
    }
    throw NotFound();
}

#endif