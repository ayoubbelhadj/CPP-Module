#include "iter.hpp"

void iterf(int &nb){
	nb++;
}
void iterf(char &c){
	c = toupper(c);
}

int	main(){
	char tab[] = "ayoub belhadj";
	iter(tab, 13, &iterf);
	std::cout << tab << std::endl;

	int tab2[] = {56,89,69,31,0,-1,56};
	iter(tab2, 7, iterf);
	for (int i = 0; i < 7; i++)
		std::cout << tab2[i] << " ";
	std::cout << std::endl;
}