/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:50:35 by abelhadj          #+#    #+#             */
/*   Updated: 2023/09/28 14:59:21 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP
# include <iostream>

class Weapon
{
private:
	std::string type;
public:
	Weapon( std::string type );
	~Weapon();
	const std::string& getType( void );
	void	setType( std::string newtype );
};

#endif