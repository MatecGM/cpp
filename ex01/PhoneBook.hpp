/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:18:23 by mbico             #+#    #+#             */
/*   Updated: 2025/01/08 18:40:25 by mbico            ###   ########.fr       */
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
		int		search_contact(void);
};
