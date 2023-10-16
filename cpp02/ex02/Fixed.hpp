/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelhadj <abelhadj@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 04:42:50 by abelhadj          #+#    #+#             */
/*   Updated: 2023/10/15 21:57:44 by abelhadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FIXED_HPP
# define FIXED_HPP
# include <iostream>
# include <cmath>

class Fixed
{
private:
	int	FixPointVal;
	static const int FractBit;
	
public:
	Fixed(int const Nbr);
	Fixed();
	Fixed(float const Nbr);
	Fixed(const Fixed &other);
	~Fixed();
	Fixed&	operator=(const Fixed& other);
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	float	toFloat( void ) const;
	int		toInt( void ) const;

	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator>(const Fixed& other) const;

	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator*(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;

	Fixed&	operator++(void);
	Fixed&	operator--(void);
	Fixed	operator++(int);
	Fixed	operator--(int);

	static Fixed& min(Fixed &a, Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& min(Fixed const &a, Fixed const &b);
	static const Fixed& max(Fixed const &a, Fixed const &b);
};

std::ostream& operator<<(std::ostream& COUT, Fixed const &i);
#endif