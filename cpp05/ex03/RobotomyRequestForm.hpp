#ifndef		RobotomyRequestForm_HPP
#define		RobotomyRequestForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"


class RobotomyRequestForm : public AForm
{
private:
	std::string	_Target;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string _Target);
	RobotomyRequestForm(const RobotomyRequestForm& obj);
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& obj);
	virtual ~RobotomyRequestForm();
	
	std::string	getTarget() const;

	void	execute(Bureaucrat const & executor) const;
};



#endif
