/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbico <mbico@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 16:31:03 by mbico             #+#    #+#             */
/*   Updated: 2025/06/21 08:33:16 by mateo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"


class ShrubberyCreationForm : public AForm {
	private:
		void		executeAction() const;
		std::string	_target;
	public:
		ShrubberyCreationForm(const ShrubberyCreationForm &ref);
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm(void);
		
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);
};
