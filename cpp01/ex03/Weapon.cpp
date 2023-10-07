/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:50:31 by abelhadj          #+#    #+#             */
/*   Updated: 2023/09/28 15:05:12 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : type(type)
{

}

Weapon::~Weapon()
{
}

const std::string& Weapon::getType()
{
	std::string& ref = this->type;
	return ref;
}

void	Weapon::setType(std::string newtype)
{
	this->type = newtype;
}