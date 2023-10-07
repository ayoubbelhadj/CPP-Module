/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed4Loser.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:33:48 by abelhadj          #+#    #+#             */
/*   Updated: 2023/10/04 20:16:27 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed4Loser.hpp"

Sed4Loser::Sed4Loser(std::string file) : file(file)
{
}

Sed4Loser::~Sed4Loser()
{
}

void	Sed4Loser::replace(std::string s1, std::string s2)
{
	if (s1.length() == 0)
		return;
	std::ifstream	ifile(this->file);
	if (ifile.is_open())
	{
		std::string	str;
		if (std::getline(ifile, str, '\0'))
		{
			std::ofstream	ofile(this->file + ".replace");
			size_t	pos = str.find(s1);
			while (pos != std::string::npos)
			{
				str.erase(pos, s1.length());
				str.insert(pos, s2);
				pos += s2.length();
				pos = str.find(s1, pos);
			}
			ofile << str;
			ofile.close();
		}
		else
		{
			std::cout << this->file << " file is enpty" << std::endl;
		}
		ifile.close();
	}
	else
	{
		std::cout << "Enable to open " << this->file << "." << std::endl;
	}
}