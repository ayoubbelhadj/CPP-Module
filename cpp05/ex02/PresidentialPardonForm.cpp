#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _Target("X-TARGET"){
	
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _Target(target){

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj): AForm(obj.getName(), 25, 5){
	*this = obj;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj){
	if (this != &obj){
		this->_Target = obj.getTarget();
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

std::string	PresidentialPardonForm::getTarget() const{
	return this->_Target;
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	if (!this->getSigned())
		throw NotSignedException();
	else if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	std::cout << _Target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
