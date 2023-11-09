/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:00:25 by abelhadj          #+#    #+#             */
/*   Updated: 2023/11/06 15:44:47 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form() : _Name("X-NAME"), _GradeSign(150), _GradeExec(150), _Sign(false){
	
}

Form::Form(const std::string Name, int GradeSign, int GradeExec) : _Name(Name), _GradeSign(GradeSign), _GradeExec(GradeExec), _Sign(false){
	if(GradeSign < 1 || GradeExec < 1)
		throw Form::GradeTooHighException();
	else if (GradeSign > 150 || GradeExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& obj): _Name(obj.getName()), _GradeSign(obj.getGradeSign()), _GradeExec(obj.getGradeExec()){
	*this = obj;
}

Form& Form::operator=(const Form& obj){
	if (this != &obj){
		this->_Sign = obj.getSigned();
	}
	return *this;
}

Form::~Form(){
}

std::string	Form::getName() const{
	return (this->_Name);
}
int	Form::getGradeExec() const{
	return(this->_GradeExec);
}

int	Form::getGradeSign() const{
	return(this->_GradeSign);
}

int	Form::getSigned() const{
	return(this->_Sign);
}

std::ostream& operator<<(std::ostream& COUT, Form const &obj){
	COUT << "-------------- FORM --------------" << std::endl;
	COUT << "Form Name: " << obj.getName() << std::endl;
	COUT << "Signed: ";
	if (obj.getSigned())
		COUT << "TRUE" << std::endl;
	else
		COUT << "FALSE" << std::endl;
	COUT << "Grade to Sign: " << obj.getGradeSign() << std::endl;
	COUT << "Grade to Execute: " << obj.getGradeExec() << std::endl;
	COUT << "----------------------------------";
	return COUT;
}


const char* Form::GradeTooLowException::what() const throw(){
	return("Grade is too Low");
}

const char* Form::GradeTooHighException::what() const throw(){
	return("Grade is too High");
} 


void	Form::beSigned(const Bureaucrat &obj){
	if (obj.getGrade() <= this->getGradeSign())
		this->_Sign = true;
	else
		throw Form::GradeTooLowException();
}