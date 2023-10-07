/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:08:05 by abelhadj          #+#    #+#             */
/*   Updated: 2023/09/29 21:29:10 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->index = 0;
    this->flag = 0;
}
PhoneBook::~PhoneBook(){}

void    PhoneBook::Start()
{
    std::string in = "";
    this->FistPage();
    while(in.compare("EXIT"))
    {
        if(!in.compare("ADD"))
            this->AddContact();
        else if (!in.compare("SEARCH"))
        {
            this->Search();
            std::cin.clear();
        }
        std::cout << ">> ";
        std::getline(std::cin, in);
        if (std::cin.eof())
           break ;
        std::cin.clear();
    }
    std::cout << std::endl << "-----------------> GOODBYE <-----------------" << std::endl;
}

void    PhoneBook::FistPage()
{
    std::cout << "----------------> PHONEBOOK <----------------" << std::endl;
    std::cout << "       HEY WELCOME TO YOUR PHONEBOOK!!" << std::endl;
    std::cout << "If you want to add a contact write [ADD]." << std::endl;
    std::cout << "If you want to search a contact write [SEARCH]." << std::endl;
    std::cout << "If you want to exit write [EXIT]." << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
}

void    PhoneBook::AddContact()
{
    contact[this->index % 8].Add();
    this->flag++;
    contact[this->index % 8].Index(this->index % 8);
    this->index++;
}

void    PhoneBook::Show()
{
    std::cout << "--------------> CONCTACT LIST <--------------" << std::endl;
    std::cout << "|" << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "NickName" << "|";
	std::cout << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for(int i = 0; i < 8  ; i++)
        contact[i].Display();
}
int PhoneBook::Index_In()
{
    std::string in = "";
    bool    valid = 0;
    while(!valid)
    {
        std::cout << "Please enter the index contact: ";
        std::getline(std::cin, in);
        if (std::cin.eof())
		{
			std::cout << std::endl << "-----------------> GOODBYE <-----------------" << std::endl;
			exit(0) ;
		}
        if (std::cin.good() && !in.empty() && this->Isdigit(in) && (std::stoi(in) >= 0 && std::stoi(in) < 8) && std::stoi(in) < this->index)
			valid = 1;
		else
		{
			std::cin.clear();
			std::cout << "Try again, invalid Index..." << std::endl;
		}
    }
    return std::stoi(in);
}

void    PhoneBook::Search()
{
    this->Show();
	if (this->flag != 0)
	{
    	int i = this->Index_In();
		if (this->flag == 0 || this->index - 1 < i)
			std::cout << "Sorry invalid index!" << std::endl;
		else
			this->contact[i].ShowContact(i);
	}
	else
		std::cout << "Sorry, the list is empty, there is no contact to search!" << std::endl;
}

bool	PhoneBook::Isdigit(std::string str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!std::isdigit(str[i]) && str[0] != '+')
			return 0;
	}
	return 1;
}