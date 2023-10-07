/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 16:41:54 by abelhadj          #+#    #+#             */
/*   Updated: 2023/09/27 18:39:30 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
		Zombie	*z1 = newZombie("JACKI");
		z1->announce();
		delete z1;
		randomChump("CHAN");
		return 0;
}
