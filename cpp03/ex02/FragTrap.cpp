/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 04:14:37 by abelhadj          #+#    #+#             */
/*   Updated: 2023/10/16 04:52:07 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"FragTrap.hpp"


void	FragTrap::highFivesGuys(){
	if (HitPoints)
		std::cout << "FrapTrap " << Name << " high fives amigos!!" << std::endl;
}

FragTrap::FragTrap(){
	this->Name = "X-NAME";
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	std::cout << "FragTrap "<< Name << " Constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other){
	this->Name = other.Name;
	this->HitPoints = other.HitPoints;
	this->EnergyPoints = other.EnergyPoints;
	this->AttackDamage = other.AttackDamage;
	std::cout << "Copy of FragTrap " << other.Name << " is live now." << std::endl;
	return *this;
}

FragTrap::FragTrap(const FragTrap &other){
	std::cout << "FragTrap "<< Name << " Copy Constructor called" << std::endl;
	*this = other;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->HitPoints = 100;
	this->EnergyPoints = 100;
	this->AttackDamage = 30;
	std::cout << "FragTrap "<< Name << " Parameterized Constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << Name << " Destructor called" << std::endl;
}

