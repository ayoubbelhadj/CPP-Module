/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:00:46 by abelhadj          #+#    #+#             */
/*   Updated: 2023/09/28 14:23:03 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "-str  \t   : " << &str << " : " << str << std::endl;
	std::cout << "-stringPTR : " << stringPTR << " : " << *stringPTR << std::endl;
	std::cout << "-stringREF : " << &stringREF << " : " << stringREF << std::endl;
	return 0;
}