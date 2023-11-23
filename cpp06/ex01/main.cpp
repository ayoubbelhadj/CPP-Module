
#include "Serializer.hpp"

int	main(){
	Data* node1 = new Data;
	Data* node2 = new Data;
	Data *lst;
	uintptr_t raw;
	
	node1->login = "abelhadj";
	node1->name = "Ayoub";
	node1->age = 24;
	node1->next = node2;

	node2->login = "aoudija";
	node2->name = "Amine";
	node2->age = 20;
	node2->next = NULL;

	std::cout << "--------------------------------------" << std::endl;
	std::cout << "	Befor Serialize:" << std::endl;
	std::cout << "node1 address: " << node1 << std::endl;
	std::cout << "name: " << node1->name << std::endl;
	std::cout << "age: " << node1->age << std::endl;
	std::cout << "address next: " << node1->next << std::endl << std::endl;

	std::cout << "node2 address node2: " << &node2 << std::endl;
	std::cout << "name: " << node2->name << std::endl;
	std::cout << "age: " << node2->age << std::endl;
	std::cout << "address next: " << node2->next << std::endl;
	std::cout << "--------------------------------------" << std::endl;

	raw = Serializer::serialize(node1);

	lst = Serializer::deserialize(raw);
	std::cout << "	After Deserialize:" << std::endl;
	std::cout << "node1 address: " << lst << std::endl;
	std::cout << "name: " << lst->name << std::endl;
	std::cout << "age: " << lst->age << std::endl;
	std::cout << "address next: " << lst->next << std::endl << std::endl;
	lst = lst ->next;
	std::cout << "node2 address: " << lst << std::endl;
	std::cout << "name: " << lst->name << std::endl;
	std::cout << "age: " << lst->age << std::endl;
	std::cout << "address next: " << lst->next << std::endl;

	
	delete node1;
	delete node2;
}