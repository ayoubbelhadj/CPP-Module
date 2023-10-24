/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 03:13:24 by abelhadj          #+#    #+#             */
/*   Updated: 2023/10/24 17:15:19 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WRONGANIMAL"){
	std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other){
	std::cout << "WrongAnimal Copy constructor called" << std::endl;
	*this = other;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& other){
	std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

void	WrongAnimal::setType(std::string type){
	std::cout << "WrongAnimal SetType called" << std::endl;
	this->type = type;
}
std::string	WrongAnimal::getType(void) const{
	std::cout << "WrongAnimal GetType called" << std::endl;
	return(this->type);
}

void WrongAnimal::makeSound() const{
	std::cout << "WrongAnimal Sound!" << std::endl;
}