/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:02:37 by abelhadj          #+#    #+#             */
/*   Updated: 2023/09/26 00:34:47 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact
{
private:
    std::string FirstName;
    std::string LastName;
    std::string NickName;
    std::string Phone;
    std::string DarkSecret;
	int			index;
    std::string Getin(std::string);
    std::string GetPhone(std::string);
    std::string GetName(std::string);
    std::string Getlen(std::string);
    bool        Isdigit(std::string);
    bool        IsName(std::string);
public:
    Contact(void);
    ~Contact(void);
    void    Add(void);
    void    Index(int i);
    void    Display(void);
    void    ShowContact(int i);
};

#endif