#include "Intern.hpp"


Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(const Intern& obj){
	*this = obj;
}

Intern&	Intern::operator=(const Intern& obj){
	(void) obj;
	return *this;
}

AForm*	Intern::makeForm(std::string Name, std::string target){
	std:: string formName[] = {"shrubbery creation",
							 "robotomy request",
							 "presidential pardon"};
	AForm* form[] = {new ShrubberyCreationForm(target),
					new RobotomyRequestForm(target),
					new PresidentialPardonForm(target)};
	for (int i = 0;i < 3; i++){
		if (formName[i] == Name){
			std::cout << "Intern creates " << formName[i] << std::endl;
			return form[i];
		}
	}
	std::cout << "Intern can't creates " << Name << " because this form don't exist." << std::endl;
	return nullptr;
}