#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main(){
    std::vector<int> av;

    av.push_back(5);
    av.push_back(9);
    av.push_back(3);
    av.push_back(1);
	try{
		easyfind(av, 33);
	}
	catch(const std::exception& e){
		std::cerr << e.what() << '\n';
	}
}