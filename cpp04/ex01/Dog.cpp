/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:42:41 by abelhadj          #+#    #+#             */
/*   Updated: 2023/10/27 21:38:42 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

Dog::Dog(){
	std::cout << "Dog Default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog& other): Animal(other){
	std::cout << "Dog Copy constructor called" << std::endl;
	*this = other;
}

Dog& Dog::operator=(const Dog& other){
	std::cout << "Dog Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}

Dog::~Dog(){
	delete this->brain;
	std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const{
	std::cout << "Haw Haw!!" << std::endl;
}
