/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:40:36 by abelhadj          #+#    #+#             */
/*   Updated: 2023/10/24 17:15:19 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): type("ANIMAL"){
	std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal& other){
	std::cout << "Animal Copy constructor called" << std::endl;
	*this = other;
}

Animal&	Animal::operator=(const Animal& other){
	std::cout << "Animal Copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Animal::~Animal(){
	std::cout << "Animal Destructor called" << std::endl;
}

void	Animal::setType(std::string type){
	std::cout << "Animal SetType called" << std::endl;
	this->type = type;
}

std::string	Animal::getType(void) const{
	std::cout << "Animal GetType called" << std::endl;
	return(this->type);
}

void Animal::makeSound() const{
	std::cout << "Animal Sound!" << std::endl;
}

