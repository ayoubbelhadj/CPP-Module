
#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(){
	std::ifstream	file("data.csv");
	std::string		line;
	std::string		date;
	std::string		exchangeRate;
	size_t			pos;

	std::getline(file, line);
	while (std::getline(file, line)){
		pos = line.find(',');
		if (pos != std::string::npos){
			date = line.substr(0, pos);
			exchangeRate = line.substr(pos+1);
			data[date] = exchangeRate;
		}
	}
	file.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj){
	*this = obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj){
	if (this != &obj){
		this->data = obj.data;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange(){
}


void	BitcoinExchange::ErrorsCheck(std::ifstream	&file){
	std::string line;
	if (!file.is_open()){
		std::cerr << "Error: could not open file." << std::endl;
		exit(1);
	}

	if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "Error: file is empty." << std::endl;
        exit(1);
    }

	std::getline(file, line);
	if (line != "date | value"){
		 std::cerr << "Error: invalid format." << std::endl;
        exit(1);
	}
}

std::string	BitcoinExchange::strtrim(std::string line){
	size_t start;
	size_t end;
	
	start = line.find_first_not_of(" \t\n");
    if (start == std::string::npos)
        return "";
	
	end = line.find_last_not_of(" \t\n");

    return line.substr(start, end - start + 1);
}

bool	BitcoinExchange::getInput(std::string line, std::string &date, std::string &value){
	size_t	pos;

	pos = line.find('|');
	if (pos == std::string::npos){
		std::cerr << "Error: bad input => " << line << std::endl;
		return 1;
	} 
	date = strtrim(line.substr(0, pos));
	value = strtrim(line.substr(pos + 1));
	return 0;
}

bool	BitcoinExchange::ValueCheck(std::string value){
	double	nbr;
	char	*ptr;
	if (value.empty()){
		std::cerr << "Error: empty value." << std::endl;
		return 1;
	}

	nbr = strtod(value.c_str(), &ptr);
	if (*ptr){
		std::cerr << "Error: bad input => " << value << std::endl;
		return 1;
	}
	if (nbr < 0){
		std::cerr << "Error: not a positive number." << std::endl;
		return 1;
	}
	else if (nbr > 1000){
		std::cerr << "Error: too large number." << std::endl;
		return 1;
	}
	return 0;
}

bool BitcoinExchange::isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

bool BitcoinExchange::isNotFutureDate(std::string date) {

	time_t now;
	struct tm * timeinfo;
	char buffer [80];

	time (&now);
	timeinfo = localtime (&now);

	strftime (buffer,80,"%Y-%m-%d",timeinfo);
	if (date > std::string(buffer))
		return 1;
	return 0;
}

bool	BitcoinExchange::DateCheck(std::string date){
	int		year, month, day, flag;
	char	*yptr, *mptr, *dptr;

	flag = 1;
	if (date.empty()){
		std::cerr << "Error: empty date." << std::endl;
		return 1;
	}
	if (date.length() != 10 || date[4] != '-' || date [7] != '-')
		flag = 0;
	if (flag){
		year = std::strtod(date.substr(0, 4).c_str(), &yptr);
		month = std::strtod(date.substr(5, 2).c_str(), &mptr);
		day = std::strtod(date.substr(8, 2).c_str(), &dptr);
	}
	if (flag && (*yptr || *mptr || *dptr))
		flag = 0;
	if (flag &&(month < 1 || month > 12 || day < 1 || day > 31))
		flag = 0;
	if (flag &&(month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		flag = 0;
	if (flag && month == 2)
		if (day > 29 || (day > 28 && !isLeapYear(year)))
			flag = 0;
	if (flag && isNotFutureDate(date))
		flag = 0;
	if (!flag){
		std::cerr << "Error: bad input => " << date << std::endl;
		return 1;
	}
	return 0;
}

double	BitcoinExchange::getpreviouseValue(std::string date){
	std::map<std::string, std::string>::iterator itr = data.lower_bound(date);
	if (itr != data.begin())
		itr--;
	return (strtod((itr->second).c_str(), NULL));
}

void	BitcoinExchange::executeInput(std::string date, std::string value){
	double	inputvalue = strtod(value.c_str(), NULL);
	double	datavalue;
	std::map<std::string, std::string>::iterator itr = data.find(date);
	if (itr != data.end())
		datavalue = strtod((itr->second).c_str(), NULL);
	else
		datavalue = getpreviouseValue(date);
	std::cout << date << " => " << inputvalue << " = " << datavalue * inputvalue << std::endl;
}

void	BitcoinExchange::run(std::string filename){
	std::ifstream	file(filename);
	std::string		line;
	std::string		date;
	std::string		value;

	ErrorsCheck(file);
	while (std::getline(file, line)){
		if (getInput(line, date, value))
			continue ;
		if (DateCheck(date) || ValueCheck(value))
			continue;
		executeInput(date, value);
	}
	file.close();
}