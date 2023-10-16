/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 21:59:58 by abelhadj          #+#    #+#             */
/*   Updated: 2023/10/16 01:50:59 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
protected:
	std::string 	Name;
	unsigned int	HitPoints;
	unsigned int	EnergyPoints;
	unsigned int	AttackDamage;
public:
	ClapTrap();
	ClapTrap(std::string Name);
	ClapTrap(const ClapTrap &other);
	ClapTrap& operator=(const ClapTrap &other);
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif