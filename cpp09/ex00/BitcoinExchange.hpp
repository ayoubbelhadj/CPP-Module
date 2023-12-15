#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <ctime>

class BitcoinExchange
{
private:
	std::map<std::string, std::string>	data;
	void		ErrorsCheck(std::ifstream   &file);

	bool		getInput(std::string line, std::string &date, std::string &value);
	void		executeInput(std::string date, std::string value);
	double		getpreviouseValue(std::string date);

	std::string	strtrim(std::string line);
	bool		DateCheck(std::string date);
	bool 		isNotFutureDate(std::string date);
	bool 		isLeapYear(int year);

	bool		ValueCheck(std::string value);
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& obj);
	BitcoinExchange& operator=(const BitcoinExchange& obj);
	~BitcoinExchange();
	void	run(std::string filename);
};




#endif