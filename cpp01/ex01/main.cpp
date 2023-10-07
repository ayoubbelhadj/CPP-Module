/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:41:54 by abelhadj          #+#    #+#             */
/*   Updated: 2023/10/02 15:43:23 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *z = zombieHorde(50, "JACK");
	if (z)
	{
		for (int i = 0; i < 50 ; i++)
			z[i].announce();
		delete [] z;
	}
	return 0;
}
