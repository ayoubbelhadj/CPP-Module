/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 20:14:11 by abelhadj          #+#    #+#             */
/*   Updated: 2023/09/30 20:33:37 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl	harl;
	if (ac == 2)
		harl.complain(av[1]);
	else
		std::cout << "Wrong Parameter, Please enter you level." << std::endl;
	return(0);
}
