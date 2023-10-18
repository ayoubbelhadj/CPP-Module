/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 00:28:21 by abelhadj          #+#    #+#             */
/*   Updated: 2023/10/18 05:49:55 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ClapTrap.hpp"

ClapTrap::ClapTrap(const ClapTrap &other){
	std::cout << "ClapTrap "<< Name << " Copy Constructor called" << std::endl;
	*this = other; 
}

ClapTrap::ClapTrap(std::string Name) : Name(Name), HitPoints(10), EnergyPoints(10), AttackDamage(0){
	std::cout << "ClapTrap "<< Name << " is live now." << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other){
	if (this != &other){
		this->Name = other.Name;
		this->HitPoints = other.HitPoints;
		this->EnergyPoints = other.EnergyPoints;
		this->AttackDamage = other.AttackDamage;
	}
	std::cout << "ClapTrap copy of " << other.Name << " is live now." << std::endl;
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap "<< Name << " is dead." << std::endl;
}

void	ClapTrap::attack(const std::string& target){
	if (EnergyPoints > 0 && HitPoints > 0){
		std::cout << "ClapTrap " << Name << " attacks " << target<< ", causing " << AttackDamage << " points of damage!" << std::endl;
		EnergyPoints--;
	}
	else
		std::cout << "ClapTrap " << Name << " have no Energy or Hit left." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (HitPoints > 0){
		std::cout << "ClapTrap " << Name << " lose " << amount << " points of damage!" << std::endl;
		if (HitPoints >= amount)
			HitPoints -= amount;
		else
			HitPoints = 0;
	}
	else
		std::cout << "ClapTrap " << Name << " is already dead." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (EnergyPoints > 0){
		std::cout << "ClapTrap " << Name << " gaine " << amount << " points of hit!" << std::endl;
		EnergyPoints--;
		HitPoints += amount;
	}
	else
		std::cout << "ClapTrap " << Name << " have no energy left." << std::endl;
}
