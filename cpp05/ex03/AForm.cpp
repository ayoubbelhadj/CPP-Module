/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:00:25 by abelhadj          #+#    #+#             */
/*   Updated: 2023/11/06 00:32:26 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm() : _Name("X-NAME"), _GradeSign(150), _GradeExec(150), _Sign(false){
	
}

AForm::AForm(const std::string Name, int GradeSign, int GradeExec) : _Name(Name), _GradeSign(GradeSign), _GradeExec(GradeExec), _Sign(false){
	if(GradeSign < 1 || GradeExec < 1)
		throw AForm::GradeTooHighException();
	else if (GradeSign > 150 || GradeExec > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& obj): _Name(obj.getName()), _GradeSign(obj.getGradeSign()), _GradeExec(obj.getGradeExec()){
	*this = obj;
}

AForm& AForm::operator=(const AForm& obj){
	if (this != &obj){
		this->_Sign = obj.getSigned();
	}
	return *this;
}

AForm::~AForm(){
}

std::string	AForm::getName() const{
	return (this->_Name);
}
int	AForm::getGradeExec() const{
	return(this->_GradeExec);
}

int	AForm::getGradeSign() const{
	return(this->_GradeSign);
}

int	AForm::getSigned() const{
	return(this->_Sign);
}

std::ostream& operator<<(std::ostream& COUT, AForm const &obj){
	COUT << "-------------- Form --------------" << std::endl;
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


const char* AForm::GradeTooLowException::what() const throw(){
	return("Grade is too Low");
}

const char* AForm::GradeTooHighException::what() const throw(){
	return("Grade is too High");
} 

const char* AForm::NotSignedException::what() const throw(){
	return("Form Not signed");
} 

void	AForm::beSigned(const Bureaucrat &obj){
	if (obj.getGrade() <= this->getGradeSign())
		this->_Sign = true;
	else
		throw AForm::GradeTooLowException();
}