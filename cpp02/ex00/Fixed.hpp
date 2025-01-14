/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 17:13:08 by mbico             #+#    #+#             */
/*   Updated: 2025/01/14 23:46:33 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class	Fixed {
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		
	private:
		int					_rawBits;
		const static int	_fractBits = 8;
};
