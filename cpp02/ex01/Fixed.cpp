/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 04:46:38 by abelhadj          #+#    #+#             */
/*   Updated: 2023/10/15 21:57:29 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::FractBit = 8;

Fixed::Fixed(){
	std::cout << "Default constructor called" << std::endl;
	this->FixPointVal = 0;
}

Fixed::Fixed(int const Nbr){
	std::cout << "Int cestructor called" << std::endl;
	this->FixPointVal = Nbr << this->FractBit;
}

Fixed::Fixed(float const Nbr){
	std::cout << "Float cestructor called" << std::endl;
	this->FixPointVal = std::roundf(Nbr * (1 << this->FractBit));
}

Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(other.getRawBits());	
}

Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const{
	return (this->FixPointVal);
}

void Fixed::setRawBits(int const raw){
	this->FixPointVal = raw;
}

float Fixed::toFloat( void ) const{
	return(static_cast<float>(this->getRawBits()) / (1 << this->FractBit));
}

int Fixed::toInt( void ) const{
	return (this->getRawBits() >> this->FractBit);
}

std::ostream& operator<<(std::ostream& COUT, Fixed const &i){
	COUT << i.toFloat();
	return (COUT);
}