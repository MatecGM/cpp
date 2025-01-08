/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:18:23 by mbico             #+#    #+#             */
/*   Updated: 2025/01/08 18:44:33 by mbico            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#include <string>
#include <iostream>

class	Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string	nickname;
		std::string phone_number;
		std::string	darkest_secret;
	public:
		Contact();
		void		set_contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
		std::string	get_contact(void);
		std::string	get_contact_info(void);
	
};
