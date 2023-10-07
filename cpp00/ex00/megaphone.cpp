/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 14:05:04 by abelhadj          #+#    #+#             */
/*   Updated: 2023/09/29 21:39:17 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

void	ft_strupprint(char **av, int ac)
{
	std::string str;
	for(int i = 1; i < ac; i++)
	{
		str = av[i];
		for (int j = 0; str[j]; j++)
			std::cout << (char)std::toupper(str[j]);
		if (i != ac -1)
			std::cout << " ";
	}
}

int main(int ac, char **av)
{
	if (ac > 1)
		ft_strupprint(av, ac);
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return 0;
}