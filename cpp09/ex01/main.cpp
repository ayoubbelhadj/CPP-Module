#include "RPN.hpp"

int	main(int ac, char **av){
	if (ac != 2){
		std::cout << "Error: wrong argument." << std::endl;
		return 1;
	}
	RPN	rnp;
	rnp.run(av[1]);
	return 0;
}