/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:43:48 by abelhadj          #+#    #+#             */
/*   Updated: 2023/10/15 23:49:02 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ClapTrap.hpp"

int	main(){
	// ClapTrap a("Ayoub");
	ClapTrap b("AYoub");
	b.attack("Ali");
	b.takeDamage(5);
	b.takeDamage(5);
	b.beRepaired(1);
}