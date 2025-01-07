/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:18:23 by mbico             #+#    #+#             */
/*   Updated: 2025/01/07 17:16:21 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Contact.hpp"

class	PhoneBook
{
	private:
		Contact	list[8];
		int		index;
	public:
		PhoneBook();
		void	add_contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
		void	search_contact(void);
};
