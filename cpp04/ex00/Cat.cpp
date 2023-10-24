/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:42:35 by abelhadj          #+#    #+#             */
/*   Updated: 2023/10/24 17:15:19 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat(){
	this->type = "Cat";
	std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other){
	std::cout << "Cat Copy constructor called" << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other){
	std::cout << "Cat Copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Cat::~Cat(){
	std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const{
	std::cout << "Meow!!" << std::endl;
}