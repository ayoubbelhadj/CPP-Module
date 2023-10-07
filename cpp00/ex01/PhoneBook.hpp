/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:02:37 by abelhadj          #+#    #+#             */
/*   Updated: 2023/09/25 23:11:42 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook
{
private:
	Contact contact[8];
	int			Index_In(void);
	int			flag;
	int			index;
	bool        Isdigit(std::string);
public:
	PhoneBook(void);
	~PhoneBook(void);
	void    FistPage(void);
	void    AddContact(void);
	void    Show(void);
	void    Search(void);
	void	Start(void);
};

#endif
