/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:06:37 by abelhadj          #+#    #+#             */
/*   Updated: 2023/11/26 00:29:05 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_HPP
# define ScalarConverter_HPP

# include <iostream>
#include <sstream>
#include <iomanip> 

typedef enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE
}	t_type;

class ScalarConverter
{
private:
	ScalarConverter();
public:
	ScalarConverter(const ScalarConverter& obj);
	ScalarConverter& operator=(const ScalarConverter& obj);
	~ScalarConverter();

	static	void convert(std::string arg);
};

#endif