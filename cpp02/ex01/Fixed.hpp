/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:13:08 by mbico             #+#    #+#             */
/*   Updated: 2025/01/15 17:59:00 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class	Fixed {
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();
		Fixed(const int raw);
		Fixed(const float raw);

		float	toFloat(void) const;
		int		toInt(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
	private:
		int					_rawBits;

		const static int	_fractBits = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);
