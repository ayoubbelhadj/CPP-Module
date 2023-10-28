/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 22:41:53 by abelhadj          #+#    #+#             */
/*   Updated: 2023/10/27 21:38:57 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

// void	leaks()
// {
// 	system("leaks Animal");
// }
int	main(){
	// atexit(leaks);
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;
	Cat basic;
	{
		Cat tmp = basic;
	}
	Animal* animal[6] = {new Dog(), new Cat(), new Dog(), new Cat(), new Dog(), new Cat()};

	for(int i = 0; i < 6; i++)
		delete animal[i];
	
	return 0;
}