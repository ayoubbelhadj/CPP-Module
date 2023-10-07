/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 14:19:15 by abelhadj          #+#    #+#             */
/*   Updated: 2023/09/25 17:13:20 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hh"
#include <iostream>
#include <iomanip>
#include <ctime> 

int Account::_nbAccounts = 0;
int Account::_totalAmount= 0;
int Account::_totalNbDeposits= 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp()
{
	std::time_t	time;
	struct tm	*tmp;
	std::time(&time);
	tmp = std::localtime(&time);
	std::cout << "[";
	std::cout << tmp->tm_year + 1900;
	std::cout << std::setfill('0') << std::setw(2) << tmp->tm_mon + 1;
	std::cout << std::setfill('0') << std::setw(2) << tmp->tm_mday;
	std::cout << "_";
	std::cout << std::setfill('0') << std::setw(2) << tmp->tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << tmp->tm_min;
	std::cout << std::setfill('0') << std::setw(2) << tmp->tm_sec;
	std::cout << "] ";
}

Account::Account(int initial_deposit)
{
	this->_nbAccounts++;
	this->_accountIndex = this->_nbAccounts - 1;
	this->_amount = initial_deposit;
	this->_totalAmount += _amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex<< ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex<< ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
}

void	Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex<< ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex<< ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount += deposit;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_nbDeposits++;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex<< ";";
	std::cout << "p_amount:" << _amount << ";";
	if (withdrawal <= _amount)
		std::cout << "withdrawal:" << withdrawal << ";";
	else
	{
		std::cout << "withdrawal:" << "refused" << std::endl;
		return 0;
	}
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
	return 1;
}

int	Account::checkAmount() const
{
	return (_amount);
}

int	Account::getNbAccounts()
{
	return (_nbAccounts);
}

int	Account::getTotalAmount()
{
	return (_totalAmount);
}

int	Account::getNbDeposits()
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}
