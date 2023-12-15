#ifndef RPN_HPP
#define RPN_HPP
#include <iostream>
#include <stack>
class RPN
{
private:
	std::stack<int>	mst;

	void		ErrorsCheck(std::string arg);
	void		calcule(char c);
	bool		isop(char c);
public:
	RPN();
	RPN(const RPN& obj);
	RPN& operator=(const RPN& obj);
	~RPN();
	void	run(std::string arg);
};

#endif