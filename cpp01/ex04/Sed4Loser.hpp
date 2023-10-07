/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed4Loser.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 16:29:27 by abelhadj          #+#    #+#             */
/*   Updated: 2023/09/30 16:33:47 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SED4LOSER_HPP
# define SED4LOSER_HPP

#include <iostream>
#include <fstream>

class Sed4Loser
{
private:
	std::string file;
public:
	Sed4Loser(std::string file);
	~Sed4Loser();
	void	replace(std::string s1, std::string s2);
};

#endif