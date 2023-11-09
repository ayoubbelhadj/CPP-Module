#ifndef		INTERN_HPP
#define		INTERN_HPP

#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

class Intern
{
public:
	Intern();
	Intern(const Intern& obj);
	Intern&	operator=(const Intern& obj);
	~Intern();

	AForm*	makeForm(std::string Name, std::string target);
};


#endif
