
#include "ScalarConverter.hpp"
#include <iomanip> 

int	main(int ac, char **av)
{
	if (ac == 2)
		ScalarConverter::convert(av[1]);
	else
		std::cout << "Wrong arguments" << std::endl;
}