/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 14:55:09 by abelhadj          #+#    #+#             */
/*   Updated: 2023/10/02 23:11:12 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "Sed4Loser.hpp"

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		Sed4Loser	sed(av[1]);
		sed.replace(av[2], av[3]);
		return 0;	
	}
	else
		std::cout << "Wrong Parametre!" << std::endl;
	return 1;
}