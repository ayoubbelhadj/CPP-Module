#ifndef		BUREAUCRAT_HPP
#define		BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string	_Name;
	int					_Grade;
public:
	Bureaucrat();
	Bureaucrat(const std::string Name, int Grade);
	Bureaucrat(const Bureaucrat& obj);
	Bureaucrat&	operator=(const Bureaucrat& obj);
	~Bureaucrat();

	const std::string getName() const;
	int	getGrade() const;
	void	GradeInc();
	void	GradeDec();
	void	signForm(Form& obj);

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

};

std::ostream& operator<<(std::ostream& COUT, Bureaucrat const &obj);


#endif
