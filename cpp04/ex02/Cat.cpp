/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:42:35 by abelhadj          #+#    #+#             */
/*   Updated: 2023/10/25 16:44:37 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"

Cat::Cat(){
	std::cout << "Cat Default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& other): AAnimal(other){
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other){
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		if (this->brain)
			delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}

Cat::~Cat(){
	delete this->brain;
	std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const{
	std::cout << "Meow!!" << std::endl;
}