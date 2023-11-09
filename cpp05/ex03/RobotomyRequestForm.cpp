#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy Request Form", 72, 45), _Target("X-TARGET"){
	
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robotomy Request Form", 72, 45), _Target(target){

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj): AForm(obj.getName(), 72, 45){
	*this = obj;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj){
	if (this != &obj){
		this->_Target = obj.getTarget();
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

std::string	RobotomyRequestForm::getTarget() const{
	return this->_Target;
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	if (!this->getSigned())
		throw NotSignedException();
	else if (executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	else{
		static int t = 0;
		if (t % 2 == 0)
			std::cout << this->_Target << " has been robotomized successfully." << std::endl;
		else
			std::cout << "The robotomy failed." << std::endl;
		t++;
	}
}

