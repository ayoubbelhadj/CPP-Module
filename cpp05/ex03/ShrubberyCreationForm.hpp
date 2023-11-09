#ifndef		ShrubberyCreationForm_HPP
#define		ShrubberyCreationForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
private:
	std::string	_Target;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string _Target);
	ShrubberyCreationForm(const ShrubberyCreationForm& obj);
	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& obj);
	virtual ~ShrubberyCreationForm();
	
	std::string	getTarget() const;

	void	execute(Bureaucrat const & executor) const;
};



#endif
