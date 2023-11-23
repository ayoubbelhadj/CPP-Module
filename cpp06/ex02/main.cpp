
#include "Base.hpp"

int	main(){
	Base* x = generate();
	Base* y = generate();

	std::cout << "*x = ";
	identify(x);
	std::cout << "*y = ";
	identify(y);
	
	std::cout << "&x = ";
	identify(*x);
	std::cout << "&y = ";
	identify(*y);
	
	delete x;
	delete y;
}