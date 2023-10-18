/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 04:08:02 by abelhadj          #+#    #+#             */
/*   Updated: 2023/10/18 05:51:19 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ScavTrap.hpp"

ScavTrap::ScavTrap(){
	this->Name = "X-NAME";
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "ScavTrap "<< Name << " Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "ScavTrap "<< Name << " Parameterized Constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other){
	if (this != &other){
		this->Name = other.Name;
		this->HitPoints = other.HitPoints;
		this->EnergyPoints = other.EnergyPoints;
		this->AttackDamage = other.AttackDamage;
	}
	std::cout << "Copy of ScavTrap " << other.Name << " is live now." << std::endl;
	return *this;
}

ScavTrap::ScavTrap(const ScavTrap &other){
	std::cout << "ScavTrap "<< Name << " Copy Constructor called" << std::endl;
	*this = other;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << Name << " Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target){
	if (EnergyPoints && HitPoints){
		std::cout << "ScavTrap " << Name << " attacks " << target<< ", causing " << AttackDamage << " points of damage!" << std::endl;
		EnergyPoints--;
	}
	else if(EnergyPoints == 0)
		std::cout << "ScavTrap " << Name << " have no Energy." << std::endl;
	else if(HitPoints == 0)
		std::cout << "ScavTrap " << Name << " have no Hit." << std::endl;
}

void ScavTrap::guardGate(){
	if(HitPoints)
		std::cout << "ScavTrap " << Name << " is now in Gate keeper mode" << std::endl;
}
