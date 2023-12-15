#include <iostream>
#include "BitcoinExchange.hpp"

int	main(int ac, char **av){
	if (ac != 2){
		std::cout << "Error: could not open file." << std::endl;
		exit(EXIT_FAILURE);
	}
	BitcoinExchange	btc;

	btc.run(av[1]);	

}