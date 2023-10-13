/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 04:46:38 by abelhadj          #+#    #+#             */
/*   Updated: 2023/10/13 08:20:15 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	this->FixPointVal = 0;
}

Fixed::Fixed(int const Nbr){
	this->FixPointVal = Nbr << this->FractBit;
}

Fixed::Fixed(float const Nbr){
	this->FixPointVal = std::roundf(Nbr * (1 << this->FractBit));
}

Fixed::Fixed(const Fixed &other){
	this->setRawBits(other.getRawBits());	
}

Fixed& Fixed::operator=(const Fixed& other){
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed(){
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

bool Fixed::operator==(const Fixed& other) const{
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const{
	return (this->getRawBits() != other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const{
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const{
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const{
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>(const Fixed& other) const{
	return (this->getRawBits() > other.getRawBits());
}

Fixed Fixed::operator+(const Fixed& other) const{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed Fixed::operator++(int){
	Fixed	tmp(*this);
	tmp.FixPointVal = this->FixPointVal++;
	return (tmp);
}

Fixed Fixed::operator--(int){
	Fixed	tmp(*this);
	tmp.FixPointVal = this->FixPointVal--;
	return (tmp);
}

Fixed& Fixed::operator++(void){
	++this->FixPointVal;
	return (*this);
}

Fixed& Fixed::operator--(void){
	--this->FixPointVal;
	return (*this);
}

Fixed& Fixed::min(Fixed &a, Fixed &b){
	if(a.getRawBits() > b.getRawBits())
		return(b);
	return(a);
}

Fixed& Fixed::max(Fixed &a, Fixed &b){
	if(a.getRawBits() > b.getRawBits())
		return(a);
	return(b);
}

const Fixed& Fixed::min(Fixed const &a, Fixed const &b){
	if(a.getRawBits() > b.getRawBits())
		return(b);
	return(a);
}

const Fixed& Fixed::max(Fixed const &a, Fixed const &b){
	if(a.getRawBits() > b.getRawBits())
		return(a);
	return(b);
}
