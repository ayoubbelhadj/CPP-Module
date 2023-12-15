#include "RPN.hpp"

RPN::RPN(){
}

RPN::RPN(const RPN& obj){
	*this = obj;
}

RPN& RPN::operator=(const RPN& obj){
	if (this != &obj){
		this->mst = obj.mst;
	}
	return *this;
}

RPN::~RPN(){
}

void	RPN::ErrorsCheck(std::string arg){
	for (size_t i = 0; i < arg.size(); i++){
		if (!isdigit(arg[i]) && arg[i] != '+' && arg[i] != '-' && arg[i] != '*'
			&& arg[i] != '/' && arg[i] != ' '){
				std::cout << "Error: wrong input." << std::endl;
				exit(1);
			}
	}
	if (arg.empty()){
		std::cout << "Error: empty input." << std::endl;
		exit(1);
	}
}

void	RPN::calcule(char c){
	int	nbr1, nbr2;
	nbr1 = mst.top();
	mst.pop();
	nbr2 = mst.top();
	mst.pop();

	switch (c)
	{
	case '+':
		mst.push(nbr2 + nbr1);
		break;
	case '-':
		mst.push(nbr2 - nbr1);
		break;
	case '*':
		mst.push(nbr2 * nbr1);
		break;
	case '/':
		if (nbr1 == 0){
			std::cout << "Error: division by zero." << std::endl;
			exit(1);
		}
		mst.push(nbr2 / nbr1);
		break;
	}
}

bool	RPN::isop(char c){
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return 1;
	return 0;
}

void	RPN::run(std::string arg){
	ErrorsCheck(arg);
	for (size_t i = 0; i < arg.length(); i++){
		while (arg[i] == ' ')
			i++;
		if (arg[i + 1] && arg[i] == '-' && std::isdigit(arg[i + 1])){
			mst.push(-(arg[i + 1] - '0'));
			i++;
		}
		else if (std::isdigit(arg[i]))
			mst.push(arg[i] - '0');
		else if (isop(arg[i]) && mst.size() >= 2)
			calcule(arg[i]);
	}
	if (mst.size() == 1)
		std::cout << mst.top() << std::endl;
	else
		std::cout << "Error" << std::endl;
}