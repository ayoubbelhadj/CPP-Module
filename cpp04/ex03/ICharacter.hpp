/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:55:41 by abelhadj          #+#    #+#             */
/*   Updated: 2023/10/25 17:56:34 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ICHARACTER_HPP
#define	ICHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"

class ICharacter
{
public:
virtual ~ICharacter() {}
virtual std::string const & getName() const = 0;
virtual void equip(AMateria* m) = 0;
virtual void unequip(int idx) = 0;
virtual void use(int idx, ICharacter& target) = 0;
};

#endif