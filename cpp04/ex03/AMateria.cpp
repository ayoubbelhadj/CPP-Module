/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:10:52 by abelhadj          #+#    #+#             */
/*   Updated: 2023/10/25 17:46:14 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(std::string const & type): type(type){
}

AMateria::AMateria(const AMateria &other){
	*this = other;
}

AMateria& AMateria::operator=(const AMateria &other){
	if (this != &other)
		this->type = other.type;
	return *this;
}

std::string const & AMateria::getType() const{
	return(this->type);
}

AMateria::~AMateria(){
}
