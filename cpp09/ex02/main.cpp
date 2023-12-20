
#include "PmergeMe.hpp"

int	main(int ac, char **av){
	if (ac != 1){
		try
		{
			PmergeMe<std::vector<int> > vec(av);
			std::cout << "Befor:\t";
			vec.DataDisplay();
			vec.sort();
			PmergeMe<std::deque<int> > deq(av);
			deq.sort();
			std::cout << "After:\t";
			deq.DataDisplay();
			vec.TimeDisplay();
			deq.TimeDisplay();
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		
	}
	else{
		std::cerr << "Error: Wrong argument." << std::endl; 
	}
}