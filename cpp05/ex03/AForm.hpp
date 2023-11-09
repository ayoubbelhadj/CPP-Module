/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:46:45 by abelhadj          #+#    #+#             */
/*   Updated: 2023/11/06 00:32:04 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		AForm_HPP
#define		AForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_Name;
	int					_GradeSign;
	int					_GradeExec;
	bool				_Sign;
public:
	AForm();
	AForm(const std::string Name, int GradeSign, int GradeExec);
	AForm(const AForm& obj);
	AForm&	operator=(const AForm& obj);
	virtual ~AForm();
	std::string	getName() const;
	int			getGradeSign() const;
	int			getSigned() const;
	int			getGradeExec() const;
	void 		beSigned(const Bureaucrat &obj);

	virtual void	execute(Bureaucrat const & executor) const = 0;

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

	class NotSignedException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& COUT, AForm const &obj);


#endif
