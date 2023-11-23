#include "Base.hpp"

Base::~Base() {}

Base * generate(void){
	static bool seeded = false;
    if (!seeded) {
        std::srand(std::time(nullptr));
        seeded = true;
    }
	int randomNumber = std::rand() % 3;
	switch (randomNumber)
	{
	case 0:
		return new A;
	case 1:
		return new B;
	case 2:
		return new C;
	default:
		return new A;
	}
}

void identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "Class type A." << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class type B." << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class type C." << std::endl;
	else
		std::cout << "unknown Class." << std::endl;
}

void identify(Base& p){
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "Class type A." << std::endl;
		(void)a;
	}
	catch(const std::exception& e) {
		try
		{
			B& b = dynamic_cast<B&>(p);
			std::cout << "Class type B." << std::endl;
			(void)b;
		}
		catch(const std::exception& e) {
			try
			{
				C& c = dynamic_cast<C&>(p);
				std::cout << "Class type C." << std::endl;
				(void)c;
			}
			catch(const std::exception& e) {
				std::cout << "unknown Class." << std::endl;
			}
		}
		
	}
}