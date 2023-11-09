#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(): _Name("X-NAME"), _Grade(1){
}

Bureaucrat::Bureaucrat(const std::string Name, int Grade): _Name(Name), _Grade(Grade){
	if (this->_Grade > 150)
		throw	GradeTooLowException();
	else if (this->_Grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj){
	*this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj){
	if (this != &obj)
		this->_Grade = obj.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat(){
}

const std::string Bureaucrat::getName() const{
	return(this->_Name);
}

int	Bureaucrat::getGrade() const{
	return(this->_Grade);
}

void	Bureaucrat::GradeDec(){
	if (this->_Grade >= 150)
		throw	GradeTooLowException();
	else
		this->_Grade++;
}

void	Bureaucrat::GradeInc(){
	if (this->_Grade <= 1)
		throw	GradeTooHighException();
	else
		this->_Grade--;
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
	return("Grade is too Low");
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
	return("Grade is too High");
} 


std::ostream& operator<<(std::ostream& COUT, Bureaucrat const &obj){
	COUT << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return COUT;  
}

void	Bureaucrat::signForm(AForm& obj){
	try
	{
		obj.beSigned(*this);
		std::cout << this->getName() << " signed " << obj.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << obj.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form){
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
	
}