/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:46:45 by abelhadj          #+#    #+#             */
/*   Updated: 2023/11/09 14:40:15 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FORM_HPP
#define		FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_Name;
	int					_GradeSign;
	int				
	_GradeExec;	bool				_Sign;
public:
	Form();
	Form(const std::string Name, int GradeSign, int GradeExec);
	Form(const Form& obj);
	Form&	operator=(const Form& obj);
	~Form();
	std::string	getName() const;
	int			getGradeSign() const;
	int			getSigned() const;
	int			getGradeExec() const;
	void 		beSigned(const Bureaucrat &obj);

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

std::ostream& operator<<(std::ostream& COUT, Form const &obj);


#endif
