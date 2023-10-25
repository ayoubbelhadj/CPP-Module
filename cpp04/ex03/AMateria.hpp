/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:06:45 by abelhadj          #+#    #+#             */
/*   Updated: 2023/10/25 17:57:05 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	AMATERIA_HPP
#define	AMATERIA_HPP

#include "ICharacter.hpp"
#include <iostream>
class AMateria
{
protected:
	std::string	type;
public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria &other);
	AMateria& operator=(const AMateria &other);
	~AMateria();
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};

#endif