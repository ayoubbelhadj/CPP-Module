/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 22:43:48 by abelhadj          #+#    #+#             */
/*   Updated: 2023/10/16 05:03:45 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"FragTrap.hpp"

int	main(){
	FragTrap a("Mouad");
	FragTrap c;
	FragTrap b("Ayoub");
	c = a;
	c.attack("Ali");
	a.attack("Amine");
	b.attack("Jack");
    c.takeDamage(10);
    c.highFivesGuys();

}