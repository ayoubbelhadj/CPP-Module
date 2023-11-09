#ifndef		PresidentialPardonForm_HPP
#define		PresidentialPardonForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"


class PresidentialPardonForm : public AForm
{
private:
	std::string	_Target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string _Target);
	PresidentialPardonForm(const PresidentialPardonForm& obj);
	PresidentialPardonForm&	operator=(const PresidentialPardonForm& obj);
	virtual ~PresidentialPardonForm();
	
	std::string	getTarget() const;

	void	execute(Bureaucrat const & executor) const;
};



#endif
