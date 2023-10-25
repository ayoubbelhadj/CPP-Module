/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:40:36 by abelhadj          #+#    #+#             */
/*   Updated: 2023/10/25 16:46:34 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(): type("AAnimal"){
	std::cout << "AAnimal Default constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& other){
	std::cout << "AAnimal Copy constructor called" << std::endl;
	*this = other;
}

AAnimal&	AAnimal::operator=(const AAnimal& other){
	std::cout << "AAnimal Copy assignment operator called" << std::endl;
	if (this != &other)
		this->type = other.type;
	return (*this);
}

AAnimal::~AAnimal(){
	std::cout << "AAnimal Destructor called" << std::endl;
}

void	AAnimal::setType(std::string type){
	std::cout << "AAnimal SetType called" << std::endl;
	this->type = type;
}

std::string	AAnimal::getType(void) const{
	std::cout << "AAnimal GetType called" << std::endl;
	return(this->type);
}

