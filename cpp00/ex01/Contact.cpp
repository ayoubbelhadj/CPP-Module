/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:29:35 by abelhadj          #+#    #+#             */
/*   Updated: 2023/09/29 21:26:46 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PhoneBook.hpp"

Contact::Contact(){}
Contact::~Contact(){}

std::string	Contact::Getin(std::string str)
{
	std::string	in = "";
	bool		valid = 0;
	while(!valid)
	{
		std::cout << str;
		std::getline(std::cin, in);
		if (std::cin.eof())
		{
			std::cout << std::endl << "-----------------> GOODBYE <-----------------" << std::endl;
			exit(0) ;
		}
		if (std::cin.good() && !in.empty())
			valid = 1;
		else
		{
			std::cin.clear();
			std::cout << "Try again, invalid input..." << std::endl;
		}
	}
	return (in);
}
bool	Contact::Isdigit(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!std::isdigit(str[i]) && str[0] != '+')
			return 0;
	}
	return 1;
}

bool	Contact::IsName(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!std::isalpha(str[i]) && str[i] != ' ')
			return 0;
	}
	return 1;
}
std::string	Contact::GetPhone(std::string str)
{
	std::string	in = "";
	bool		valid = 0;
	while(!valid)
	{
		std::cout << str;
		std::getline(std::cin, in);
		if (std::cin.eof())
		{
			std::cout << std::endl << "-----------------> GOODBYE <-----------------" << std::endl;
			exit(0) ;
		}
		if (std::cin.good() && !in.empty() && this->Isdigit(in) && in.length() > 9)
			valid = 1;
		else
		{
			std::cin.clear();
			std::cout << "Try again, invalid Phone Number..." << std::endl;
		}
	}
	return (in);
}

std::string	Contact::GetName(std::string str)
{
	std::string	in = "";
	bool		valid = 0;
	while(!valid)
	{
		std::cout << str;
		std::getline(std::cin, in);
		if (std::cin.eof())
		{
			std::cout << std::endl << "-----------------> GOODBYE <-----------------" << std::endl;
			exit(0) ;
		}
		if (std::cin.good() && !in.empty() && this->IsName(in))
			valid = 1;
		else
		{
			std::cin.clear();
			std::cout << "Try again, invalid Name..." << std::endl;
		}
	}
	return (in);
}

void    Contact::Add()
{
	std::cout << "---------------> ADD CONTACT <---------------" << std::endl;
	this->FirstName = this->GetName("First Name:\t");
	this->LastName = this->GetName("Last Name:\t");
	this->NickName = this->Getin("Nickname:\t");
	this->Phone = this->GetPhone("Phone:\t\t");
	this->DarkSecret = this->Getin("Dark Secret:\t");
	std::cout << "---------------------------------------------" << std::endl;
}
void	Contact::Index(int i)
{
	this->index = i;
}

std::string Contact::Getlen(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	else
		return str;
}

void	Contact::Display()
{
	if (this->FirstName.empty())
		return;
	std::cout << "|" << std::setw(10) << this->index << "|";
	std::cout << std::setw(10) << this->Getlen(this->FirstName)<< "|";
	std::cout << std::setw(10) << this->Getlen(this->LastName) << "|";
	std::cout << std::setw(10) << this->Getlen(this->NickName) << "|";
	std::cout << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
}

void	Contact::ShowContact(int i)
{
	std::cout << "-------------> CONTACT INDEX " << i << " <-------------" << std::endl;
	std::cout << "First Name:\t" << this->FirstName << std::endl;
	std::cout << "Last Name:\t" << this->LastName << std::endl;
	std::cout << "NickName:\t" << this->NickName << std::endl;
	std::cout << "Phone:\t\t" << this->Phone << std::endl;
	std::cout << "Dark secret:\t" << this->DarkSecret << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
}
