/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:43:48 by abelhadj          #+#    #+#             */
/*   Updated: 2023/10/16 04:04:27 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ScavTrap.hpp"

int	main(){
	ScavTrap a("Siham");
	ScavTrap c;
	ScavTrap b("Ayoub");
	c.attack("moha");
	c = a;
	b.attack("Ali");
	c.attack("Ali");
	b.guardGate();

}