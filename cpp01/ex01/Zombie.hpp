/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:16:27 by abelhadj          #+#    #+#             */
/*   Updated: 2023/10/02 15:43:38 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ZOMBIE_HPP
# define	ZOMBIE_HPP

#include <iostream>

class Zombie
{
private:
	std::string	name;
public:
	~Zombie();
	Zombie();
	void	announce( void );
	void	SetName( std::string name );
};

Zombie* zombieHorde( int N, std::string name );

#endif