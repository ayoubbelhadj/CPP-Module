/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:47:40 by abelhadj          #+#    #+#             */
/*   Updated: 2023/10/25 17:50:51 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ICE_HPP
#define	ICE_HPP

#include <iostream>
#include "AMateria.hpp"
class Ice : public  AMateria
{
public:
	Ice();
	Ice(std::string const & type);
	Ice(const Ice &other);
	Ice& operator=(const Ice &other);
	~Ice();
	AMateria* clone() const;
};

#endif