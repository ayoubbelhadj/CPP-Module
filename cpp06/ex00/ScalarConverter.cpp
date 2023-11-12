
#include "ScalarConverter.hpp"
#include <iomanip> 
ScalarConverter::ScalarConverter(const ScalarConverter& obj){
	*this = obj;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj){
	(void) obj;
	return (*this);
}

ScalarConverter::~ScalarConverter(){
}

ScalarConverter::ScalarConverter(){
}


int	_isfract(std::string str)
{
	int	i = 0;
	int flag = 0;
	int dot = 0;

	if (str[0] == '-' || str[0] == '+')
			i++;
	while (str[i])
	{
		if (str[i] == '.' && (dot || !isdigit(str[i - 1]) || !isdigit(str[i + 1])))
			return 0;
		if (!isdigit(str[i]) && str[i] != '.' && (str[i] != 'f' || flag))
			return 0;
		if (i && str[i] == '.')
			dot = 1;
		if (str[i] == 'f')
			flag = 1;
		i++;
	}
	return 1;
}


int	_isfloat(std::string str)
{
	int	len = str.length();

	if (str[len - 1] == 'f')
		return 1;
	return 0;
}

int _isint(std::string arg)
{
	double v = std::atof(arg.c_str());
	if (v > INT_MAX || v < INT_MIN)
		return 0;
	int	i = 0;
	if (arg[0] == '-' || arg[0] == '+')
		i++;
	while (arg[i])
	{
		if(!isdigit(arg[i]))
			return 0;
		i++;
	}
	return 1;
}

int _ischar(std::string arg)
{
	int	i = 0;

	if (arg.length() == 1 && !isdigit(arg[0]))
		return 1;
	while (arg[i])
	{
		if(!isdigit(arg[i]))
			return 0;
		i++;
	}
	int	value = std::atoi(arg.c_str());
	if (isprint(value))
		return 1;
	return 0;
}

t_type	_checkType(std::string arg)
{
	if (_ischar(arg))
		return CHAR;
	else if (_isint(arg))
		return INT;
	else if (_isfloat(arg))
		return FLOAT;
	return DOUBLE;
}

void	_castchar(std::string arg){
	if (arg.length() == 1)
	{
		std::cout << "char: " << "'" << static_cast<char>(arg[0]) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(arg[0]) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(2)<< static_cast<float>(std::atoi(arg.c_str())) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(2)<< static_cast<double>(std::atoi(arg.c_str())) << std::endl; 
	}
	else
	{
		std::cout << "char: " << "'" << static_cast<char>(std::atoi(arg.c_str())) << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(std::atoi(arg.c_str())) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(2)<< static_cast<float>(std::atoi(arg.c_str())) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(2)<< static_cast<double>(std::atoi(arg.c_str())) << std::endl; 
	}
}

void	_castint(std::string arg){
	int	value = std::atoi(arg.c_str());

	if (isprint(value))
		std::cout << "char: " << "'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2)<<static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(2)<< static_cast<double>(value) << std::endl; 
}

void	_castfloat(std::string arg){
	float	value = std::atof(arg.c_str());

	if (isprint(static_cast<char>(value)))
		std::cout << "char: " << "'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	if (value > INT_MAX || value < INT_MIN)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2)<< static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(2)<< static_cast<double>(value) << std::endl;
}


void	_castdouble(std::string arg){
	double	value = std::atof(arg.c_str());

	if (isprint(static_cast<char>(value)))
		std::cout << "char: " << "'" << static_cast<char>(value) << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(value) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(2)<< static_cast<float>(value) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(2)<< static_cast<double>(value) << std::endl;
}


int	_ispseudo(std::string arg){
	if (arg == "+inf" || arg == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (arg == "-inf" || arg == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else if (arg == "nan" || arg == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else
		return 1;
	return 0;
}

void	ScalarConverter::convert(std::string arg){
	int	type;
	if (_isfract(arg) || _isint(arg) || arg.length() == 1)
	{
		type = _checkType(arg);
		switch (type)
		{
			case CHAR:
				_castchar(arg);
				break;
			case INT:
				_castint(arg);
				break;
			case FLOAT:
				_castfloat(arg);
				break;
			case DOUBLE:
				_castfloat(arg);
				break;
		}
	}
	else if (_ispseudo(arg))
		std::cout << "Sorry wrong input." << std::endl;
}
